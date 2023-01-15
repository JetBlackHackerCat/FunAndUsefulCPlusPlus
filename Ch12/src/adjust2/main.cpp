#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("../../asset/cat.jpg");
    std::cout << "Read cat.jpg with: " << image.rows << "x" << image.cols << std::endl;
    cv::Mat adjusted_image = cv::Mat::zeros(image.size(), image.type());
    float alpha = 1 + 0.4;
    float beta = 50;
    image.convertTo(adjusted_image, -1, alpha, beta); 
    cv::imwrite("output/cat_adjusted.jpg", adjusted_image);
    return 0;
}