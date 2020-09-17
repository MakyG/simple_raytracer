#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <vector>
#include "../raytracer/Raytracer.h"

class Menu {
public:
	void MainMenu();
    void Render();
    void RenderObjects();
    void AddObject();
    void AddTriangle();
    void AddPlane();
    void AddSphere();
    void AddLight();
    void AddDefault();
    Raytracer tracer;
private:
    Vector center = Vector(0, 0, 0);
    double radius = 0;
    Vector normal = Vector(0, 0, 0);
    Vector color = Vector(0, 0, 0);
    Vector p0 = Vector(0, 0, 0);
    Vector p1 = Vector(0, 0, 0);
    Vector p2 = Vector(0, 0, 0);
};
