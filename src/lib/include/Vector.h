#pragma once
// Todo make it one struct
// Todo optional w where it needed

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

    void ToString() {
        std::cout << x_ << ", " << y_ << ", " << z_ << std::endl;
    }
};

inline bool operator==(const Vector2D& lhs, const Vector2D& rhs)
{
    return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}

inline bool operator==(const Vector3D& lhs, const Vector3D& rhs)
{
    return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_ && lhs.z_ == rhs.z_;
}
