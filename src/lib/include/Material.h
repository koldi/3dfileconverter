#pragma once
#include <vector>
#include <string>
#include <utility>
#include "Face.h"

struct Material
{
    Material() {}
    Material(const std::string& name, std::vector<Face> faces)
    : name_(name)
    , faces_(std::move(faces))
    {}
    
    std::string name_;
    std::vector<Face> faces_;
};

inline bool operator==(const Material& lhs, const Material& rhs)
{
    return lhs.name_ == rhs.name_ && lhs.faces_ == rhs.faces_;
}
