#include <algorithm>
#include <iostream>
#include "Raytracer.h"

void Raytracer::Render() {
    // SET CANVAS HEIGHT AND WIDTH
    
	const int height = 500;
	const int width = 500;

	// PREDEFINE COLORS
	
    const Vector white(255, 255, 255);
    const Vector grey(100, 100, 100);
    const Vector black(0, 0, 0);
    const Vector red(255, 0, 0);
    const Vector green(0, 255, 0);
    const Vector blue(0, 0, 255);
    const Vector darkGrey(30, 30, 30);
    const Vector yellow(255, 255, 0);

    // CREATE RENDERER FILE
    
	std::ofstream out("output.bmp");
	out << "P3 \n" << width << "\n" << height << "\n" << "255\n";
    
    // CREATES PIXEL FILL
    
    Vector pixColor(black);
    
    // SET UP CAMERA
    
    Vector cameraPosition = Vector(0, 0, 0);
    Vector viewDirection = Vector(0, 0, 1);
    double screenDistance = 1;
    
    // DEFINE SCREEN CENTER
    
    Vector screenCenter = cameraPosition + viewDirection * screenDistance;
    Vector p0 = screenCenter + Vector(-1, 1, 0);
    Vector p1 = screenCenter + Vector(1, 1, 0);
    Vector p2 = screenCenter + Vector(-1, -1, 0);

    // RENDERING LOOP
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            // objects.push_back(std::make_shared<Sphere>(Vector(0, 0, 0), 5, Vector(255, 0, 0))); // TEST

            double t;
            pixColor = darkGrey;
            
            double u = (double)x / width;
            double v = (double)y / height;

            Vector hitPoint = p0 + (p1 - p0) * u + (p2 - p0) * v; // Point of intersection
            Vector rayDirection = hitPoint - cameraPosition;
            
            double closestIndex = -1;
            double closestLength = 20000000;
            Ray closestRay = Ray(cameraPosition, rayDirection.normalize(), 0);

            for(unsigned int i = 0; i < objects.size(); i++){
                Ray ray = Ray(cameraPosition, rayDirection.normalize(), 1000000);
                if(objects[i]->Intersects(ray)){
                    if (ray.length < closestLength) {
                        closestLength = ray.length;
                        closestIndex = i;
                        closestRay = ray;
                    }
                }
            }

            if(objects.size() > closestIndex && closestIndex >= 0){
                Vector objectColor = objects[closestIndex]->GetColor();
                pixColor = objectColor;
                Vector intersectPoint = closestRay.origin + closestRay.direction * closestRay.length;
                for (unsigned int i = 0; i < lights.size(); i++) {

                    Vector diffuse = objects[closestIndex]->CalculateDiffuse(hitPoint, intersectPoint);

                    Vector lightDirection = (lights[i].center - hitPoint).normalize();

                    double lightStrength = std::clamp(diffuse.Dot(lightDirection), 0.0, 1.0);
                    Vector multiplicator = Vector(lights[i].color.x / 255, lights[i].color.y / 255, lights[i].color.z / 255) * lightStrength;
                    Vector calculatedColor = Vector(objectColor.x * multiplicator.x, objectColor.y * multiplicator.y, objectColor.z * multiplicator.z);
                    pixColor = calculatedColor;
                }
            }
            out << (int)pixColor.x << ' ' << (int)pixColor.y << ' ' << (int)pixColor.z << '\n';
        }
    }
}
