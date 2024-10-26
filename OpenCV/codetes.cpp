// #include <opencv2/opencv.hpp>
// #include <iostream>
// #include <cmath>

// using namespace cv;
// using namespace std;

// float jarakObjek(float diameterPixel, float diameter, float focalLength) {
//     return (diameter * focalLength) / diameterPixel;
// }

// int main() {
//     VideoCapture cap(2);
//     if (!cap.isOpened()) {
//         cout << "Kamera tidak ada" << endl;
//         return -1;
//     }

//     Mat kamera, hsvKamera, mask;

//     // Variabel untuk trackbar (disesuaikan untuk warna oranye)
//     int hMin = 0, hMax = 10;   // Rentang hue untuk oranye
//     int sMin = 144, sMax = 224; // Saturasi tinggi untuk warna cerah
//     int vMin = 153, vMax = 255; // Value tinggi untuk pencahayaan yang baik

//     float diameter = 6.5;      // Diameter bola dalam cm
//     float focalLength = 1000;  // Panjang fokus kamera

//     namedWindow("Trackbars", (640, 200));
//     createTrackbar("Hue Min", "Trackbars", &hMin, 179);
//     createTrackbar("Hue Max", "Trackbars", &hMax, 179);
//     createTrackbar("Sat Min", "Trackbars", &sMin, 255);
//     createTrackbar("Sat Max", "Trackbars", &sMax, 255);
//     createTrackbar("Val Min", "Trackbars", &vMin, 255);
//     createTrackbar("Val Max", "Trackbars", &vMax, 255);

//     while (true) {
//         cap >> kamera;
//         if (kamera.empty()) {
//             cout << "Kamera tidak ada" << endl;
//             break;
//         }

//         cvtColor(kamera, hsvKamera, COLOR_BGR2HSV);
//         inRange(hsvKamera, Scalar(hMin, sMin, vMin), Scalar(hMax, sMax, vMax), mask);

//         // Hilangkan noise dengan operasi morfologi
//         erode(mask, mask, Mat(), Point(-1, -1), 2);
//         dilate(mask, mask, Mat(), Point(-1, -1), 2);
//         morphologyEx(mask, mask, MORPH_CLOSE, Mat(), Point(-1, -1), 2); // Menambahkan operasi close

//         // Temukan kontur
//         vector<vector<Point>> kontur;
//         vector<Vec4i> hierarchy;
//         findContours(mask, kontur, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

//         for (size_t i = 0; i < kontur.size(); i++) {
//             double area = contourArea(kontur[i]);
//             if (area > 100) { // Hanya ambil kontur dengan area cukup besar
//                 // Dapatkan bounding box
//                 Rect boundingBox = boundingRect(kontur[i]);
//                 Point center(boundingBox.x + boundingBox.width / 2, boundingBox.y + boundingBox.height / 2);
//                 int radius = boundingBox.width / 2;

//                 // Hanya deteksi objek dalam rentang ukuran tertentu
//                 if (radius > 10 && radius < 200) {  // Sesuaikan rentang ukuran sesuai dengan bola
//                     float diameterPixel = radius * 2;
//                     float jarak = jarakObjek(diameterPixel, diameter, focalLength);
                
//                     // Gambar bounding box dan informasi jarak
//                     rectangle(kamera, boundingBox, Scalar(0, 255, 0), 2);
//                     putText(kamera, "Distance: " + to_string(jarak) + " cm", Point(boundingBox.x, boundingBox.y - 10), FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255, 0), 2);
                
//                     cout << "Diameter bola yang terdeteksi: " << diameterPixel << " pixels" << endl;
//                     cout << "Radius bola yang terdeteksi: " << radius << " pixels" << endl;
//                 }
//             }
//         }

//         imshow("Deteksi Kamera", kamera);
//         imshow("Mask", mask);

//         if (waitKey(30) == 'q') break;
//     }

//     cap.release();
//     destroyAllWindows();
    
//     return 0;
// }
