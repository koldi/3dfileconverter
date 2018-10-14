/**
 * Triangle struct for STL files
 * https://en.wikipedia.org/wiki/STL_(file_format)
 */

#pragma once
#include "Vector.h"
#include <utility>

struct Triangle
{
    Vector3D normal_;
    Vector3D vertex1_;
    Vector3D vertex2_;
    Vector3D vertex3_;
    uint16_t attributes_;

    Triangle(Vector3D normal, Vector3D v1, Vector3D v2, Vector3D v3, uint16_t attr = 0)
    : normal_(std::move(normal))
    , vertex1_(std::move(v1))
    , vertex2_(std::move(v2))
    , vertex3_(std::move(v3))
    , attributes_(attr)
    {}
};