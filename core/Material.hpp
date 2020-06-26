//
// Created by ZoomP on 05-06.
//

#ifndef ZRENDERER_MATERIAL_HPP
#define ZRENDERER_MATERIAL_HPP


#include "../global.hpp"
#include "Texture.hpp"

using namespace Eigen;
enum MaterialType{
    DIFFUSE_AND_GLOSSY,
    REFLECTION_AND_REFRACTION,
    REFLECTION
};

class Material {
public:
    MaterialType m_type;
    Vector3f m_color;
    Vector3f m_emission;
    float ior;
    float Kd, Ks;
    float specularExponent;
    Texture *tex;



    inline Material(MaterialType t = DIFFUSE_AND_GLOSSY, Vector3f c = Vector3f(1,1,1), Vector3f e = Vector3f(0, 0, 0));
    inline MaterialType getType();
    inline Vector3f getColor();
    inline Vector3f getColorAt(float u, float v);
    inline Vector3f getEmission();
};

#endif //ZRENDERER_MATERIAL_HPP
