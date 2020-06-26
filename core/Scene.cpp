//
// Created by ZoomP on 05-06.
//

#include "Scene.hpp"

void Scene::Render(RenderType renderType) {
    switch (renderType) {
        case Scene::RenderType::RASTERIZER:
            Rasterizer();
            break;
        case Scene::RenderType::RAY_TRACING:
            break;
        case Scene::RenderType::RAY_PATH_TRACING:
            break;
    }
}

/// 准备进行光栅化
void Scene::Rasterizer() {
    eye_pos = {0, 0, 25};
    eye_fov = 45.0f;
    aspect_ratio = width/height;
    z_near = 0.1;
    z_far = 50;
    frame_buf.resize(width*height);
    depth_buf.resize(width*height);
}

/// local space triangle
/// 一整套光栅化渲染管线
void Scene::RasterizerTriangle(Triangle *tri) {
    float f1 = (z_far - z_near) / 2.0;
    float f2 = (z_far + z_near) / 2.0;

    model = get_model_matrix(10);
    view = get_view_matrix(eye_pos);
    projection = get_projection_matrix(eye_fov, aspect_ratio, z_near, z_far);
    Eigen::Matrix4f mvp = projection * view * model;
    Eigen::Vector4f v[] = {
            mvp * tri->v[0],
            mvp * tri->v[1],
            mvp * tri->v[2],
    };
    for (auto& vec:v){
        vec.x() /= vec.w();
        vec.y() /= vec.w();
        vec.z() /= vec.w();
    }

    for (auto& vert: v){
        vert.x() = 0.5*width*(vert.x()+1.0);
        vert.y() = 0.5*width*(vert.y()+1.0);
        vert.z() = vert.z()*f1 + f2;
    }

    int x_min = INT_MAX, x_max = INT_MIN, y_min =INT_MAX, y_max = INT_MIN;
    for (int i = 0; i < 3; i++){
        if (v[i].x() < x_min){
            x_min = v[i].x();
        }
        if (v[i].x() > x_max){
            x_max = v[i].x();
        }
        if (v[i].y() < y_min){
            y_min = v[i].y();
        }
        if (v[i].y() > y_max){
            y_max = v[i].y();
        }
    }

    for (int i = x_min; i <= x_max; i++){
        for (int j = y_min; j <= y_max; j++){
            if (insideTriangle(i, j, v)){
                SetPixel(Vector3f(i, j, 1), Eigen::Vector3f{217.0, 238.0, 185.0});
            }
        }
    }
}

bool insideTriangle(int x, int y, const Vector4f* _v)
{
    // TODO : Implement this function to check if the point (x, y) is inside the triangle represented by _v[0], _v[1], _v[2]
    Vector3f P(x, y, 1);
    Vector3f AB(_v[1].x() - _v[0].x(), _v[1].y() - _v[0].y(), 1);
    Vector3f BC(_v[2].x() - _v[1].x(), _v[2].y() - _v[1].y(), 1);
    Vector3f CA(_v[0].x() - _v[2].x(), _v[0].y() - _v[2].y(), 1);
    Vector3f AP(P.x() - _v[0].x(), P.y() - _v[0].y(), 1);
    Vector3f BP(P.x() - _v[1].x(), P.y() - _v[1].y(), 1);
    Vector3f CP(P.x() - _v[2].x(), P.y() - _v[2].y(), 1);
    float z1 = AB.cross(AP).z();
    float z2 = BC.cross(BP).z();
    float z3 = CA.cross(CP).z();
    if ((z1 > 0 && z2 > 0 && z3 > 0) || (z1 < 0 && z2 < 0 && z3 < 0)){
        return true;
    }else{
        return false;
    }
}

void Scene::SetPixel(const Eigen::Vector3f &point, const Eigen::Vector3f &color) {
    if (point.x() < 0 || point.x() >= width || point.y() < 0 || point.y() >= height)
        return;
    auto index = (height-1-point.y())*width + point.x();
    frame_buf[index] = color;
}


Matrix4f get_model_matrix(float angle) {
    Matrix4f rotation;
    angle = angle * MY_PI / 180.f;
    rotation << cos(angle), 0, sin(angle), 0,
            0     , 1,      0    , 0,
            -sin(angle), 0, cos(angle), 0,
            0     , 0,      0    , 1;
    Matrix4f scale;
    scale << 2.5,  0 ,  0 , 0,
            0 , 2.5,  0 , 0,
            0 ,  0 , 2.5, 0,
            0 ,  0 ,  0 , 1;
    Matrix4f translate;
    translate <<
              1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1;
    return translate * rotation * scale;
}

Matrix4f get_view_matrix(Vector3f eye_pos){
    Matrix4f view = Eigen::Matrix4f::Identity();

    Matrix4f translate;
    translate << 1,0,0,-eye_pos[0],
            0,1,0,-eye_pos[1],
            0,0,1,-eye_pos[2],
            0,0,0,1;

    view = translate*view;

    return view;
}

Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio, float z_near, float z_far){
    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();
    projection <<
               -1.0f/(aspect_ratio*tan(eye_fov/360.0f * MY_PI)), 0.0f, 0.0f, 0.0f,
            0.0f,     -1.0f/tan(eye_fov/360.0f * MY_PI),     0.0f,     0.0f,
            0.0f,     0.0f,     (z_far+z_near)/(z_near-z_far),     2*z_far*z_near/(z_far-z_near),
            0.0f,     0.0f,     1.0f,     0.0f;

    return projection;
}

