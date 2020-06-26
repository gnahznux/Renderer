//
// Created by ZoomP on 05-06.
//

#include "Bounds3.hpp"

Bounds3::Bounds3() {
    auto max_value = std::numeric_limits<double>::max();
    auto min_value = std::numeric_limits<double>::lowest();
    p_min = Vector3f(max_value, max_value, max_value);
    p_max = Vector3f(min_value, min_value, min_value);
}

Bounds3::Bounds3(Vector3f p):p_min(p), p_max(p) {

}

Bounds3::Bounds3(const Vector3f p1, const Vector3f p2) {
    p_min = p1.cwiseMin(p2);
    p_max = p1.cwiseMax(p2);
}

Vector3f Bounds3::diagonal() const {
    return p_max - p_min;
}

int Bounds3::maxExtent() const {
    auto d = diagonal();
    return d.maxCoeff();
}

double Bounds3::surfaceArea() const {
    auto d = diagonal();
    return 2 * (d.x() * d.y() + d.x() * d.z() + d.y() + d.z());
}

Vector3f Bounds3::centroid() const {
    return 0.5f * p_min + 0.5f * p_max;
}

Bounds3 Bounds3::intersect(const Bounds3 b) {
    return Bounds3(p_min.cwiseMax(b.p_min), p_max.cwiseMin(b.p_max));
}

Vector3f Bounds3::offset(const Vector3f& p) const {
    Vector3f o = p - p_min;
    if (p_max.x() > p_min.x()){
        o.x() /= p_max.x() - p_min.x();
    }
    if (p_max.y() > p_min.y()){
        o.y() /= p_max.y() - p_min.y();
    }
    if (p_max.z() > p_min.z()){
        o.z() /= p_max.z() - p_min.z();
    }
    return o;
}

bool Bounds3::intersectP(const Ray &ray, const Vector3f &invDir, const std::array<int, 3> &dirIsNeg) const {
    return false;
}

const Vector3f & Bounds3::operator[](int i) const {
    return (i == 0) ? p_min : p_max;
}