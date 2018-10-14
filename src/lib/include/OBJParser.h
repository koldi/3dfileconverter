#pragma once
#include <string>
#include <vector>

struct Face;
struct Material;
struct Vector2D;
struct Vector3D;

class OBJParser
{
public:
    const std::string ToData(const std::vector<Material>& materials) const;
    std::vector<Material> FromData(const std::string& data) const;
private:
    Face CreateFace( const std::vector<Vector3D>& v,
                            const std::vector<Vector2D>& vt,
                            const std::vector<Vector3D>& vn,
                            const std::vector<std::string>& vertices) const;
};