//
// Created by ZoomP on 05-06.
//

#ifndef ZRENDERER_TRIANGLE_HPP
#define ZRENDERER_TRIANGLE_HPP

#include "Entity.hpp"
#include "Material.hpp"
#include "Bounds3.hpp"

using namespace Eigen;

class Triangle : public Entity{
public:
    Vector4f v[3];
    Vector3f color[3];
    Vector3f e1, e2;
    Vector2f t0, t1, t2;
    Vector3f normal;
    Material* mat;

    Triangle(Vector4f _v[3], Material* _m = nullptr)
    {
        v[0] = _v[0];
        v[1] = _v[1];
        v[2] = _v[2];
//        e1 = (v[1] - v[0]);
//        e2 = v[2] - v[0];
//        mat = _m;
//        normal = e1.cross(e2).normalized();
    }


    bool intersect(const Ray& ray) override;
    bool intersect(const Ray& ray, float& t_near, uint32_t& index) const override;
    Intersection getIntersection(Ray _ray) override;
    Vector3f evalDiffuseColor(const Vector2f &) const override;
    void getSurfaceProperties(const Vector3f &, const Vector3f &, const uint32_t &, const Vector2f &, Vector3f &, Vector2f &) const override;
    Bounds3 getBounds() override;
};



#endif //ZRENDERER_TRIANGLE_HPP
