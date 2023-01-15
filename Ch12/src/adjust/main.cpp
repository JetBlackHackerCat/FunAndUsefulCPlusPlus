#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/saturate.hpp>

int main()
{
    cv::Mat image = cv::imread("../../asset/cat.jpg");
    std::cout << "Read cat.jpg with: " << image.rows << "x" << image.cols << std::endl;
    cv::Mat adjusted_image = cv::Mat::zeros(image.size(), image.type());
    float alpha = 1 + 0.4;
    float beta = 50;
    for (int x = 0; x < image.rows; x++)
    {
        for (int y = 0; y < image.cols; y++)
        {
            auto &pixel = image.at<cv::Vec3b>(x, y);
            auto &adjusted_pixel = adjusted_image.at<cv::Vec3b>(x, y);
            for (int c = 0; c < image.channels(); c++)
            {
                adjusted_pixel[c] = cv::saturate_cast<uchar>(alpha * pixel[c] + beta);
            }
        }
    }
    cv::imwrite("output/cat_adjusted.jpg", adjusted_image);
    return 0;
}