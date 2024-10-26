// TUGAS 1 OPENCVVVVVVVVVVV

#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

// regresi
float hitungJarak(float diameterPixel) {
    return (0.0003 * pow(diameterPixel, 2)) - (0.2859 * diameterPixel) + 77.6615;
}

int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "Kamera ga ada" << endl;
        return -1;
    }

    Mat kamera, hsvKamera, mask;

    int hMin = 0, hMax = 10;  
    int sMin = 144, sMax = 224;
    int vMin = 153, vMax = 255;

    while (true) {
        cap >> kamera;
        if (kamera.empty()) {
            cout << "Kamera ga ada" << endl;
            break;
        }

        cvtColor(kamera, hsvKamera, COLOR_BGR2HSV);
        inRange(hsvKamera, Scalar(hMin, sMin, vMin), Scalar(hMax, sMax, vMax), mask);

        // Hilangkan noise dengan operasi morfologi
        erode(mask, mask, Mat(), Point(-1, -1), 2);
        dilate(mask, mask, Mat(), Point(-1, -1), 2);
        morphologyEx(mask, mask, MORPH_CLOSE, Mat(), Point(-1, -1), 2);

        // kontur
        vector<vector<Point>> kontur;
        vector<Vec4i> hierarchy;
        findContours(mask, kontur, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

        for (size_t i = 0; i < kontur.size(); i++) {
            double area = contourArea(kontur[i]);
            if (area > 100) {
                // bounding box circle
                Point2f center;
                float radius;
                minEnclosingCircle(kontur[i], center, radius);

                if (radius > 50 && radius < 300) {  
                    float diameterPixel = radius * 2; // Hitung diameter dalam piksel
                    float jarak = hitungJarak(diameterPixel); // Hitung jarak pakai regresi
                    
                    // Gambar lingkaran box dan jarak
                    circle(kamera, center, static_cast<int>(radius), Scalar(0, 255, 0), 2);
                    putText(kamera, "Distance: " + to_string(jarak) + " cm", Point(center.x, center.y - radius - 10), FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255, 0), 2);
                    
                    cout << "Diameter bola pixel: " << diameterPixel << " pixels" << endl;
                    cout << "Jarak Perkiraan: " << jarak << " cm" << endl;
                }
            }
        }

        imshow("Deteksi Kamera", kamera);
        imshow("Mask", mask);

        if (waitKey(30) == 'q') break;
    }

    cap.release();
    destroyAllWindows();
    
    return 0;
}
