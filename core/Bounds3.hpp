//
// Created by ZoomP on 05-06.
//

#ifndef ZRENDERER_BOUNDS3_HPP
#define ZRENDERER_BOUNDS3_HPP

#include "../global.hpp"
#include "Ray.hpp"

using namespace Eigen;
class Bounds3 {
public:
    Vector3f p_min, p_max;

    Bounds3();

    Bounds3(const Vector3f p);

    Bounds3(const Vector3f p1, const Vector3f p2);

    //对角线长度
    Vector3f diagonal() const;

    //最长的边 用于bvh 划分
    int maxExtent() const;

    //表面积
    double surfaceArea() const;

    //质心
    Vector3f centroid() const;

    //与另外一个包围盒相交组成的包围盒
    Bounds3 intersect(const Bounds3 b);

    Vector3f offset(const Vector3f& p) const;

    inline const Vector3f& operator[](int i) const;

    //射线与该包围盒是否相交
    inline bool intersectP(const Ray& ray, const Vector3f& invDir, const std::array<int, 3>& dirIsNeg) const;

    ///检测b1 b2是否重叠
    friend bool Overlaps(const Bounds3& b1, const Bounds3& b2){
        bool x = (b1.p_max.x() >= b2.p_min.x()) && (b1.p_min.x() <= b2.p_max.x());
        bool y = (b1.p_max.y() >= b2.p_min.y()) && (b1.p_min.y() <= b2.p_max.y());
        bool z = (b1.p_max.z() >= b2.p_min.z()) && (b1.p_min.z() <= b2.p_max.z());
        return (x && y && z);
    }

    /// 检测p点是否再Bounds3 b的内部
    friend bool Inside(const Vector3f& p , const Bounds3& b){
        return (p.x() >= b.p_min.x() && p.x() <= b.p_max.x() &&
                p.y() >= b.p_min.y() && p.y() <= b.p_max.y() &&
                p.z() >= b.p_min.y() && p.z() <= b.p_max.z());
    }
};

// 组合包围盒b1和b2
inline Bounds3 Union(const Bounds3& b1, const Bounds3& b2){
    Bounds3 ret;
    ret.p_min = b1.p_min.cwiseMin(b2.p_min);
    ret.p_max = b1.p_max.cwiseMax(b2.p_max);
    return ret;
}

//将p点 纳入包围盒中
inline Bounds3 Union(const Bounds3& b, const Vector3f& p){
    Bounds3 ret;
    ret.p_min = b.p_min.cwiseMin(p);
    ret.p_max = b.p_max.cwiseMax(p);
    return ret;
}

#endif //ZRENDERER_BOUNDS3_HPP
