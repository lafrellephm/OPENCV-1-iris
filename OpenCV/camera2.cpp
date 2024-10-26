// #include <opencv2/opencv.hpp>
// #include <iostream>
// #include <cmath>

// using namespace cv;
// using namespace std;

// // Fungsi untuk menghitung jarak menggunakan regresi polinomial
// float hitungJarak(float diameterPixel) {
//     return (0.0003 * pow(diameterPixel, 2)) - (0.2859 * diameterPixel) + 77.6615;
// }

// int main() {
//     Mat foto=imread("nwjns.png", IMREAD_GRAYSCALE);
//     // if (!cap.isOpened()) {
//     //     cout << "foto tidak ada" << endl;
//     //     return -1;
//     // }

//     Mat hsvKamera, mask;

//     // Variabel untuk trackbar (disesuaikan untuk warna oranye)
//     int hMin = 0, hMax = 10;   // Rentang hue untuk oranye
//     int sMin = 144, sMax = 224; // Saturasi tinggi untuk warna cerah
//     int vMin = 153, vMax = 255; // Value tinggi untuk pencahayaan yang baik

//     while (true) {
//         // cap >> foto;
//         // if (foto.empty()) {
//         //     cout << "foto tidak ada" << endl;
//         //     break;
//         // }

//         cvtColor(foto, hsvKamera, COLOR_BGR2HSV);
//         inRange(hsvKamera, Scalar(hMin, sMin, vMin), Scalar(hMax, sMax, vMax), mask);

//         // Hilangkan noise dengan operasi morfologi
//         erode(mask, mask, Mat(), Point(-1, -1), 2);
//         dilate(mask, mask, Mat(), Point(-1, -1), 2);
//         morphologyEx(mask, mask, MORPH_CLOSE, Mat(), Point(-1, -1), 2);

//         // Temukan kontur
//         vector<vector<Point>> kontur;
//         vector<Vec4i> hierarchy;
//         findContours(mask, kontur, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

//         for (size_t i = 0; i < kontur.size(); i++) {
//             double area = contourArea(kontur[i]);
//             if (area > 100) {
//                 // Dapatkan bounding circle
//                 Point2f center;
//                 float radius;
//                 minEnclosingCircle(kontur[i], center, radius);

//                 // Hanya deteksi objek dalam rentang ukuran tertentu
//                 if (radius > 50 && radius < 300) {  // Sesuaikan rentang ukuran sesuai dengan bola
//                     float diameterPixel = radius * 2; // Hitung diameter dalam piksel
//                     float jarak = hitungJarak(diameterPixel); // Hitung jarak menggunakan regresi
                    
//                     // Gambar lingkaran dan informasi jarak
//                     circle(foto, center, static_cast<int>(radius), Scalar(0, 255, 0), 2);
//                     putText(foto, "Distance: " + to_string(jarak) + " cm", Point(center.x, center.y - radius - 10), FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255, 0), 2);
                    
//                     cout << "Diameter bola pixel: " << diameterPixel << " pixels" << endl;
//                     cout << "Jarak Perkiraan: " << jarak << " cm" << endl;
//                 }
//             }
//         }

//         imshow("Deteksi foto", foto);
//         imshow("Mask", mask);

//         if (waitKey(30) == 'q') break;
//     }

//     foto.release();
//     destroyAllWindows();
    
//     return 0;
// }
