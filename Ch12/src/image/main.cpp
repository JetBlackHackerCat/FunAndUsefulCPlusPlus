#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("../../asset/cat.jpg");
    std::cout << "Read cat.jpg with: " << image.rows << "x" << image.cols << std::endl;
    return 0;
}