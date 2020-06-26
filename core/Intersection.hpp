//
// Created by ZoomP on 05-06.
// used for store intersect information
//

#ifndef ZRENDERER_INTERSECTION_HPP
#define ZRENDERER_INTERSECTION_HPP

#include "../global.hpp"
#include "Entity.hpp"
#include "Material.hpp"

using namespace Eigen;

class Entity;

struct Intersection{
    bool happened;
    Vector3f coords;
    Vector3f normal;
    double distance;
    Entity* obj;
    Material* mat;

    Intersection(){
        happened = false;
        coords = Vector3f ();
        normal = Vector3f ();
        distance = std::numeric_limits<double>::max();
        obj = nullptr;
        mat = nullptr;
    }
};

#endif //ZRENDERER_INTERSECTION_HPP
