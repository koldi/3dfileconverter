/***
 * Simple parser for STL files based on https://en.wikipedia.org/wiki/STL_(file_format)
 */

#pragma once
#include <string>
#include <vector>
#include "Face.h"
#include "Triangle.h"

struct Material;

class STLParser
{
public:
    const std::string ToData(const std::vector<Material>& materials) const;
    std::vector<Material> FromData(const std::string& data) const;
private:
    std::vector<Triangle> GetTrianglesFromFace(const Face& face) const;
};