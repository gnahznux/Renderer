//
// Created by ZoomP on 05-06.
//

#ifndef ZRENDERER_TEXTURE_HPP
#define ZRENDERER_TEXTURE_HPP

#include "../global.hpp"
class Texture {
private:
    cv::Mat image_data;
public:
    int width, height;

    Texture(const std::string& name);

    Eigen::Vector3f getColor(float u, float v);
};


#endif //ZRENDERER_TEXTURE_HPP
