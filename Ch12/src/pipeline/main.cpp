#include <iostream>
#include <opencv2/opencv.hpp>

#define BLUR_CYCLES 5

int main()
{
    cv::Mat image = cv::imread("../../asset/cat.jpg");
    std::cout << "Read cat.jpg with: " << image.rows << "x" << image.cols << std::endl;
    cv::Mat adjusted_image = cv::Mat::zeros(image.size(), image.type());
    float alpha = 1 + 0.4;
    float beta = 50;
    image.convertTo(adjusted_image, -1, alpha, beta); 
    float normalizer = 1.0f / (5*5); 
    cv::Mat kernel = cv::Mat::ones(5, 5, CV_32F) * normalizer;
    for (int i = 0; i < BLUR_CYCLES; i++) {
        cv::filter2D(adjusted_image, adjusted_image, -1, kernel);
    }
    cv::imwrite("output/cat_adjusted.jpg", adjusted_image);
    return 0;
}