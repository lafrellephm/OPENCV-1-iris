#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
    // Membaca video dari file bernama VALORANT.mp4
    VideoCapture cap("VALORANT.mp4");

    // Periksa apakah video berhasil dibuka
    if (!cap.isOpened()) {
        printf("Error: Video tidak dapat dibuka.\n");
        return -1;
    }
    Size ukuranBaru(1280, 720);
    Mat vidResized;

    Mat frame;
    while (true) {
        // Membaca setiap frame dari video
        bool ret = cap.read(frame);

        // Jika frame tidak berhasil dibaca (misalnya video selesai)
        if (!ret) {
            printf("Selesai membaca video.\n");
            break;
        }

            resize(frame, vidResized, ukuranBaru);

        // Tampilkan frame di jendela
        imshow("Video VALORANT", vidResized);

        // Menunggu 30 ms antara setiap frame (untuk kecepatan video yang normal)
        if (waitKey(30) == 'q') {
            break; // Keluar dari loop jika pengguna menekan 'q'
        }
    }

    return 0;
}
