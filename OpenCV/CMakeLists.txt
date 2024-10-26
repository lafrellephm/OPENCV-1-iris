cmake_minimum_required(VERSION 3.10)
# Nama proyek
project(OpenCV_Learning)
# Mencari OpenCV yang terinstal di sistem
find_package(OpenCV REQUIRED)
# Menambahkan executable dari file main.cpp
add_executable(camera camera_detection.cpp)
# Menautkan library OpenCV
target_link_libraries(camera ${OpenCV_LIBS})

