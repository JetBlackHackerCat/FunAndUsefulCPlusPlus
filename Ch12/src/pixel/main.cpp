#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/saturate.hpp>

int main()
{
    cv::Mat image = cv::imread("../../asset/cat.jpg");
    cv::Vec3b pixel = image.at<cv::Vec3b>(10, 10);
    std::cout << "Pixel (10, 10) of cat.jpg is:"
              << " Blue = " << (int)pixel[0]
              << " Green = " << (int)pixel[1]
              << " Red = " << (int)pixel[2] << std::endl;
    pixel[2] = (uchar)std::min((int)pixel[2] + 10, 255);
    std::cout << "Pixel (10, 10) of cat.jpg is:"
              << " Blue = " << (int)pixel[0]
              << " Green = " << (int)pixel[1]
              << " Red = " << (int)pixel[2] << std::endl;
    pixel[2] = cv::saturate_cast<uchar>((int)pixel[2] + 100);
    std::cout << "Pixel (10, 10) of cat.jpg is:"
              << " Blue = " << (int)pixel[0]
              << " Green = " << (int)pixel[1]
              << " Red = " << (int)pixel[2] << std::endl;
    return 0;
}