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

    Vector3D v_;
    Vector2D vt_;
    Vector3D vn_;
};
