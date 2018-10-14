/**
 * This file contains all the vector implementation that we need
 * 2D Vector
 * 3D Vector
 * future improvement(TODO):
 * - this should be one class only
 * - OBJ files support another W parameter
 */

#pragma once

struct Vector2D
{
    float x_ = 0.0f;
    float y_ = 0.0f;

    Vector2D() = default;
    Vector2D(float x, float y)
    : x_(x)
    , y_(y)
    {}
};

struct Vector3D
{
    float x_ = 0.0f;
    float y_ = 0.0f;
    float z_ = 0.0f;

    Vector3D() = default;
    Vector3D(float x, float y, float z)
    : x_(x)
    , y_(y)
    , z_(z)
    {}
};

inline bool operator==(const Vector2D& lhs, const Vector2D& rhs)
{
    return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}

inline bool operator==(const Vector3D& lhs, const Vector3D& rhs)
{
    return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_ && lhs.z_ == rhs.z_;
}
