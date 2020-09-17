#pragma once
#include <math.h>
#include <array>
#include "Vector.h"

class Object{
public:
    virtual Vector GetCenter() = 0;
    virtual Vector GetColor() = 0;
    virtual Vector GetNormal(const Vector& pi) = 0;
    virtual bool Intersects(Ray ray) = 0;
    virtual Vector CalculateDiffuse(const Vector& hitPoint, const Vector& intersectPoint) = 0;
};

class Plane : public Object{
public:
	Plane(const Vector& center, const Vector& normal, const Vector& color) : center(center), normal(normal), color(color) {}
    Vector CalculateDiffuse(const  Vector& hitPoint, const Vector& intersectPoint) override{
        return (intersectPoint - GetCenter()).normalize();
    }

    Vector GetColor(){
        return color;
	}

    Vector GetNormal (const Vector& pi) override{
        return normal;
    }

    Vector GetCenter() override{
        return center;
    }

    bool Intersects(Ray ray) override {
        // assuming vectors are all normalized
        Vector n = normal;
        Vector p0 = center;
        Vector l0 = ray.origin;
        Vector l = ray.direction;
        double t;
        double denom = n.Dot(l);
        ray.length = denom;
        if (denom > 1e-6) {
            Vector p0l0 = p0 - l0;
            t = p0l0.Dot(n) / denom;
            return ray.length = t, (t >= 0);
        }
        return false;
    }
private:
    Vector center;
    Vector normal;
    Vector color;
};

class Sphere : public Object{

public:
    Sphere(const Vector& center, const double& radius, const Vector& color) : center(center), radius(radius), color(color) {}
    Vector CalculateDiffuse(const  Vector& hitPoint, const Vector& intersectPoint) override{
        return (intersectPoint - GetCenter()).normalize();
    }

    Vector GetColor(){
        return color;
    }

    Vector GetCenter() override{
        return center;
    }
    Vector GetNormal(const Vector& pi) override{
        return Vector(pi - center) / radius;
    }
    
    bool Intersects(Ray ray) override{
        Vector originToSphere = center - ray.origin;
        double projection = originToSphere.Dot(ray.direction);
        Vector distanceVector = originToSphere - ray.direction * projection;
        double newDistance = distanceVector.Dot(distanceVector);
        double newRadius = radius * radius;
        
        if (newDistance > newRadius)
            return false;
        
        double newLength = projection - sqrt(newRadius - newDistance);
        
        if(newLength < ray.length && newLength > 0){
            ray.length = newLength;
            return true;
        }
        return false;
    }
private:
    Vector center;
    double radius;
    Vector color;
};

class Triangle : public Object {
    
public:
	Triangle(const Vector& p0, const Vector& p1, const Vector& p2, const Vector& color) : p0(p0), p1(p1), p2(p2), color(color) {}
    // RETURNS ORIGIN OF THE TRIANGLE CALCULATED BY ITS THREE POINTS

    Vector CalculateDiffuse(const Vector& hitPoint, const Vector& intersectPoint) override{
        return (hitPoint + GetNormal(hitPoint) * 1e-3);
    }
    Vector GetCenter() override{
        return (p0 + p1 + p2) / 3;
    }
    Vector GetColor() override {
        return color;
    }
    Vector GetNormal (const Vector& pi) override{
        Vector normal = Vector(0, 0, 0);
        Vector A = p1 - p0; // Edge Vectors A, B
        Vector B = p2 - p0;
        normal = A.CrossProduct(B).normalize();
        return normal;
    }
    bool Intersects(Ray ray) override {
        Vector v0v1 = p1 - p0; 
        Vector v0v2 = p2 - p0; 
        Vector pvec = ray.direction.CrossProduct(v0v2); 
        double det = v0v1.Dot(pvec); 
        double t, u, v;

        // if the determinant is negative the triangle is backfacing
        // if the determinant is close to 0 (kEpsilon), the ray misses the triangle
        if (det < kEpsilon) 
            return false; 
        
        // ray and triangle are parallel if det is close to 0
        if (fabs(det) < kEpsilon) 
            return false; 
        
        double invDet = 1 / det; 
    
        Vector tvec = ray.origin - p0; 
        u = tvec.Dot(pvec) * invDet; 
        if (u < 0 || u > 1) 
            return false; 
    
        Vector qvec = tvec.CrossProduct(v0v1); 
        v = ray.direction.Dot(qvec) * invDet; 
        if (v < 0 || u + v > 1) 
            return false;

        ray.length = v0v2.Dot(qvec) * invDet;

        return true;
    }

private:
    Vector p0;
    Vector p1;
    Vector p2;
    Vector color;
};

struct Light{
    // LIGHT CONSTRUCTOR

    Light (Vector center, Vector color) : center(center), color(color){}

    Light() : center(Vector(0, 0, 0)), color(Vector(255,255,255)) {}
    // DEFINE LIGHT PARAMETERS

    Vector center;
    Vector color;
};


