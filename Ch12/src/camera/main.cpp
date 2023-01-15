#include <iostream>
#include <opencv2/opencv.hpp> 
#include <opencv2/highgui.hpp> 

int main()
{
    std::string config = "nvarguscamerasrc sensor-id={} ! video/x-raw(memory:NVMM), width=1280, height=720, format=(string)NV12, framerate=(fraction)60/1 ! nvvidconv flip-method=2 ! video/x-raw, width={}, height={}, format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink wait-on-eos=false max-buffers=1 drop=true";
    cv::VideoCapture camera = cv::VideoCapture(config, cv::CAP_GSTREAMER);

    cv::Mat frame;
    camera.grab();
    camera.retrieve(frame);
    cv::imshow("camera", frame);
    return 0;
}