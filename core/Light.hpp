//
// Created by ZoomP on 05-06.
//

#ifndef ZRENDERER_LIGHT_HPP
#define ZRENDERER_LIGHT_HPP

#include "../global.hpp"

class Light{
public:
    Eigen::Vector3f position;
    Eigen::Vector3f intensity;
    Light(const Eigen::Vector3f& p, const Eigen::Vector3f& i):position(p), intensity(i){}
    virtual ~Light() = default;
};

#endif //ZRENDERER_LIGHT_HPP
