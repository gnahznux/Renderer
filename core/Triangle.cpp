//
// Created by ZoomP on 05-06.
//

#include "Triangle.hpp"

bool Triangle::intersect(const Ray &ray) {
    return false;
}

bool Triangle::intersect(const Ray &ray, float &t_near, uint32_t &index) const {
    return false;
}

Vector3f Triangle::evalDiffuseColor(const Vector2f &) const {
    return Vector3f ();
}

Intersection Triangle::getIntersection(Ray _ray) {
    Intersection ret;
    return ret;
}


void Triangle::getSurfaceProperties(const Vector3f &, const Vector3f &, const uint32_t &, const Vector2f &, Vector3f &, Vector2f &) const {
    
}

Bounds3 Triangle::getBounds() {
    return Bounds3();
}
