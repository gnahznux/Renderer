//
// Created by ZoomP on 05-06.
//

#include "Material.hpp"

MaterialType Material::getType() {
    return m_type;
}

Vector3f Material::getColor() {
    return m_color;
}

Vector3f Material::getEmission() {
    return m_emission;
}

Vector3f Material::getColorAt(float u, float  v) {
    if (tex == nullptr){
        return Vector3f();
    }
    return tex->getColor(u, v);
}