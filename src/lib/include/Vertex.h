#pragma once
#include "Vector.h"
#include <utility>

struct Vertex
{
    Vertex(Vector3D v, Vector2D vt, Vector3D vn) 
    : v_{std::move(v)}
    , vt_(std::move(vt))
    , vn_(std::move(vn))
    {}

    void ToString() const {
        std::cout << "Coords: " << v_.x_ << ", " << v_.y_ << ", " << v_.z_ << "\n";
        std::cout << "Textures: " << vt_.x_ << ", " << vt_.y_ << "\n";
        std::cout << "Normals: " << vn_.x_ << ", " << vn_.y_ << ", " << vn_.z_ << "\n";
    }

    Vector3D v_;
    Vector2D vt_;
    Vector3D vn_;
};
