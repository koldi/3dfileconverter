#pragma once
#include <string>
#include <vector>
#include "Face.h"

struct Material;
struct Vector2D;
struct Vector3D;

class OBJParser
{
public:
    OBJParser() = default;
    const std::string ToData(const std::vector<Material>& materials) const;
    std::vector<Material> FromData(const std::string& data) const;
    void bazdmeg() const {}
private:
    Face CreateFace( const std::vector<Vector3D>& v,
                            const std::vector<Vector2D>& vt,
                            const std::vector<Vector3D>& vn,
                            const std::vector<std::string>& vertices) const;

    template<typename T>
    T GetElementByIndex(int index, const std::vector<T>& elements) const;
};