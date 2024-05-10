# ZRender

# start
https://docs.conan.io/2/tutorial/consuming_packages/build_simple_cmake_project.html

$ conan install . --output-folder=build --build=missing
$ cd build
$ cmake ..
$ cmake --build .

## Summary
简易CPU模拟渲染器

[]基础数学库
    
    [] Vector 向量
    [] Matrix 矩阵
    [] Triangel 三角形
    [] Sphere 球
    [] Ray 射线
    [] BoundBox 包围盒
    [] MathLib 各种数学计算方法
    
[] ObjLoader 模型加载器

[] Scene 场景

    [] Camera 相机
    
[] Renderer 渲染器

    [] Material 材质
    [] Shading Model 光照模型
   custom renderer
