//
// Created by ZoomP on 05-06.
//

#include "Texture.hpp"

Texture::Texture(const std::string &name) {
    image_data = cv::imread(name);
    cv::cvtColor(image_data, image_data, cv::COLOR_RGB2BGR);
    width = image_data.cols;
    height = image_data.rows;
};

Eigen::Vector3f Texture::getColor(float u, float v) {
    auto u_img = u * width;
    // uv-cord v from bottom to top, image height from top to bottom
    auto v_img = (1-v) * height;
    auto color = image_data.at<cv::Vec3b>(u_img, v_img);
    return Eigen::Vector3f(color[0], color[1], color[2]);
};
