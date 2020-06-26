//
// Created by ZoomP on 05-06.
//

#ifndef ZRENDERER_ENTITY_HPP
#define ZRENDERER_ENTITY_HPP

#include "Ray.hpp"
#include "Intersection.hpp"
#include "Bounds3.hpp"
#include "Shader.hpp"

class Entity {
private:
    std::function<Eigen::Vector3f(vertex_shader_payload)> vertex_shader;
    std::function<Eigen::Vector3f(fragment_shader_payload)> fragment_shader;
public:
    Entity(){};
    virtual ~Entity(){};

    void set_vertex_shader(std::function<Eigen::Vector3f(vertex_shader_payload)> vert_shader) {
        vertex_shader = vert_shader;
    }
    void set_fragment_shader(std::function<Eigen::Vector3f(fragment_shader_payload)> frag_shader) {
        fragment_shader = frag_shader;
    }

    virtual bool intersect(const Ray& ray) = 0;
    virtual bool intersect(const Ray& ray, float &, uint32_t &) const = 0;
    virtual Intersection getIntersection(Ray _ray) = 0;
    virtual void getSurfaceProperties(const Vector3f &, const Vector3f &, const uint32_t &, const Vector2f &, Vector3f &, Vector2f &) const = 0;
    virtual Vector3f evalDiffuseColor(const Vector2f &) const = 0;
    virtual Bounds3 getBounds() = 0;
};


#endif //ZRENDERER_ENTITY_HPP
