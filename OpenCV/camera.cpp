// #include <opencv2/opencv.hpp>
// #include <iostream>

// using namespace cv;
// using namespace std;

// // Parameter kamera
// const float ACTUAL_WIDTH = 16.0f;  // Lebar objek dalam cm
// const float FOCAL_LENGTH = 700.0f; // Focal length dalam pixel, sesuaikan dengan kamera kamu
// const double KNOWN_DISTANCE = 50.0; // Jarak kalibrasi dari kamera ke objek dalam cm

// // Fungsi untuk menghitung jarak
// float calculateDistance(float widthInPixels) {
//     if (widthInPixels <= 0) return 0; // untuk menghindari pembagian dengan nol
//     return (ACTUAL_WIDTH * FOCAL_LENGTH) / widthInPixels;
// }

// int main() {
//     // Membaca video dari kamera
//     VideoCapture cap(0);
//     if (!cap.isOpened()) {
//         cout << "Error: Could not open camera." << endl;
//         return -1;
//     }

//     Mat frame, hsvFrame, mask;

//     // Trackbar untuk mengatur HSV
//     int hMin = 0, hMax = 179;
//     int sMin = 0, sMax = 255;
//     int vMin = 0, vMax = 255;

//     namedWindow("Trackbars");
//     createTrackbar("H Min", "Trackbars", &hMin, hMax);
//     createTrackbar("H Max", "Trackbars", &hMax, hMax);
//     createTrackbar("S Min", "Trackbars", &sMin, sMax);
//     createTrackbar("S Max", "Trackbars", &sMax, sMax);
//     createTrackbar("V Min", "Trackbars", &vMin, vMax);
//     createTrackbar("V Max", "Trackbars", &vMax, vMax);

//     while (true) {
//         cap >> frame; // Mengambil frame dari kamera
//         if (frame.empty()) break;

//         // Mengubah frame ke ruang warna HSV
//         cvtColor(frame, hsvFrame, COLOR_BGR2HSV);

//         // Menerapkan thresholding berdasarkan HSV
//         Scalar lower(hMin, sMin, vMin);
//         Scalar upper(hMax, sMax, vMax);
//         inRange(hsvFrame, lower, upper, mask);

//         // Deteksi objek menggunakan kontur
//         vector<vector<Point>> contours;
//         findContours(mask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

//         for (size_t i = 0; i < contours.size(); i++) {
//             double area = contourArea(contours[i]);
//             if (area > 200) { // Filter area minimum
//                 Rect boundingBox = boundingRect(contours[i]);
//                 double objectWidthInPixels = boundingBox.width;

//                 // Hitung jarak menggunakan rumus perbandingan
//                 double distance = (ACTUAL_WIDTH * KNOWN_DISTANCE) / objectWidthInPixels;

//                 // Menggambar kotak deteksi
//                 rectangle(frame, boundingBox.tl(), boundingBox.br(), Scalar(0, 255, 0), 2);
//                 putText(frame, "Distance: " + to_string(distance) + " cm", Point(boundingBox.x, boundingBox.y - 10),
//                         FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);
//             }
//         }

//         // Tampilkan hasil
//         imshow("Detection", frame);
//         imshow("Mask", mask); // Tampilkan mask

//         if (waitKey(30) >= 0) break; // Keluar jika ada input
//     }

//     cap.release();
//     destroyAllWindows();
//     return 0;
// }
