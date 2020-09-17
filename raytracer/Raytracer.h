#pragma once

#include <memory>
#include <fstream>
#include <cmath>
#include <iostream>
#include <vector>

#include "Vector.h"
#include "Ray.h"
#include "Object.h"


class Raytracer{
public:
    void Render();
    inline void AddTriangle(const Vector& p0, const Vector& p1, const Vector& p2, const Vector& color){
        objects.push_back(std::make_shared<Triangle>(p0, p1, p2, color));
    }
    inline void AddPlane(const Vector& center, const Vector& normal, const Vector& color) {
        objects.push_back(std::make_shared<Plane>(center, normal, color));
    }
    inline void AddSphere(const Vector& center, const double& radius, const Vector& color){
        objects.push_back(std::make_shared<Sphere>(center, radius, color));
    }
    inline void AddLight(const Vector& center, const Vector& color){
        lights.emplace_back(center, color);
    }

protected:
    std::vector<std::shared_ptr<Object>>objects;
    std::vector<Light>lights;
};

