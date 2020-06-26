//
// Created by ZoomP on 05-06.
//

#ifndef ZRENDERER_SHADER_HPP
#define ZRENDERER_SHADER_HPP

#include "../global.hpp"
#include "Texture.hpp"

struct vertex_shader_payload {
    Eigen::Vector3f position;
};

struct fragment_shader_payload {
    Eigen::Vector3f view_pos;
    Eigen::Vector3f color;
    Eigen::Vector3f normal;
    Eigen::Vector2f tex_coords;
    Texture* texture;

    fragment_shader_payload(const Eigen::Vector3f& col, const Eigen::Vector3f& nor,const Eigen::Vector2f& tc, Texture* tex) :
            color(col), normal(nor), tex_coords(tc), texture(tex) {}

};

#endif //ZRENDERER_SHADER_HPP
