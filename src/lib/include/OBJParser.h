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
    static const std::string ToOBJ(const Face& face);
    static std::vector<Material> FromOBJ(const std::string& face);
private:
    static Face CreateFace( const std::vector<Vector3D>& v,
                            const std::vector<Vector2D>& vt,
                            const std::vector<Vector3D>& vn,
                            const std::vector<std::string>& vertices);
};