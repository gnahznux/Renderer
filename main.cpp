#include <iostream>
#include "global.hpp"
#include "core/Scene.hpp"
#include "opencv2/opencv.hpp"

int main(int argc, const char** argv)
{
    Scene s(700, 700);
    Eigen::Vector4f pos[3]{{2, 0, -2, 1}, {0, 2, -2, 1}, {-2, 0, -2, 1}};
    Triangle t(pos, nullptr);
    int key = 0;
    while (key != 27) {
        s.Rasterizer();
        s.RasterizerTriangle(&t);
        cv::Mat image(700, 700, CV_32FC3, s.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);
    }
    return 0;
}