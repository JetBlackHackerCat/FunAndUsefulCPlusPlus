#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat image = cv::imread("../../asset/alley.jpg");
    std::cout << "Read alley.jpg with: " << image.rows << "x" << image.cols << std::endl;
    float normalizer = 1.0f / (5*5); 
    cv::Mat kernel = cv::Mat::ones(5, 5, CV_32F) * normalizer;
    cv::Mat adjusted_image = cv::Mat::zeros(image.size(), image.type());
    cv::filter2D(image, adjusted_image, -1, kernel);
    cv::imwrite("output/alley_adjusted.jpg", adjusted_image);
    return 0;
}