//
// Created by ZoomP on 05-06.
//

#ifndef ZRENDERER_SCENE_HPP
#define ZRENDERER_SCENE_HPP

#include "../global.hpp"
#include "Entity.hpp"
#include "Light.hpp"
#include "Ray.hpp"
#include "Triangle.hpp"

using namespace Eigen;

class Scene {
    enum RenderType{
        RASTERIZER,
        RAY_TRACING,
        RAY_PATH_TRACING
    };
private:
    int width = 1200;
    int height = 960;
    Vector3f background_color = Vector3f (0.235294, 0.67451, 0.843137);
    std::vector<Entity*> entities;
    std::vector<std::unique_ptr<Light>> lights;

    std::vector<Vector3f> frame_buf;
    std::vector<float> depth_buf;

    Vector3f eye_pos;
    float eye_fov;
    float aspect_ratio;
    float z_near, z_far;
    Matrix4f model, view, projection;

public:
    Scene(int w, int h):width(w), height(h){}


    void Render(RenderType renderType);

    void Add(Entity* entity){
        entities.push_back(entity);
    };

    void Add(std::unique_ptr<Light> light){
        lights.push_back(std::move(light));
    }

    const std::vector<Entity*>& get_entities() const {
        return entities;
    }

    const std::vector<std::unique_ptr<Light>>& get_ligts() const {
        return lights;
    }

    void set_model_matrix(const Matrix4f& _model){ model = _model; };
    void set_view_matrix(const Matrix4f& _view) { view = _view; };
    void set_projection_matrix(const Matrix4f _projection) { projection = _projection; };

    std::vector<Vector3f>& frame_buffer(){ return frame_buf; }

    void Rasterizer();
    void RasterizerTriangle(Triangle* tri);
private:


    void RayTracing();

    void SetPixel(const Eigen::Vector3f& point, const Eigen::Vector3f& color);
};

bool insideTriangle(int x, int y, const Vector4f* _v);

Matrix4f get_model_matrix(float angle);

Matrix4f get_view_matrix(Vector3f eye_pos);

Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio, float z_near, float z_far);


#endif //ZRENDERER_SCENE_HPP
