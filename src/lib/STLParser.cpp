#include "STLParser.h"
#include "Material.h"
#include "Triangle.h"
#include <iostream>
#include <sstream>
/**
 * STL files contains:
 * 1. 80 character header - cant begin with "solid"
 * 2. 4 byte little endian int - number of triangles
 * 3. all triangles
 */

namespace 
{
    template<typename T>
    T GetNumberFromStream(std::iostream& s) {
        auto size = sizeof(T);
        char intStr[size];
        s.read(intStr, size);
        return *(T*)intStr;
    }

    template<typename T>
    void WriteNumberToStream(std::iostream& s, T input) {
        auto size = sizeof(T);
        char* inputStr = (char*)&input;
        s.write(inputStr, size);
    }

    Vector3D GetVector3DFromStream(std::iostream& s) {
        return Vector3D(
            GetNumberFromStream<float>(s),
            GetNumberFromStream<float>(s),
            GetNumberFromStream<float>(s)
        );
    }

    void WriteVector3DToStream(std::iostream& s, const Vector3D& input) {
        WriteNumberToStream<float>(s, input.x_);
        WriteNumberToStream<float>(s, input.y_);
        WriteNumberToStream<float>(s, input.z_);
    }

    Triangle GetTriangleFromStream(std::iostream& s) {
        return Triangle(
            GetVector3DFromStream(s),
            GetVector3DFromStream(s),
            GetVector3DFromStream(s),
            GetVector3DFromStream(s),
            GetNumberFromStream<uint16_t>(s)
        );
    }

    void WriteTriangleToStream(std::iostream& s, const Triangle& input) {
        WriteVector3DToStream(s, input.normal_);
        WriteVector3DToStream(s, input.vertex1_);
        WriteVector3DToStream(s, input.vertex2_);
        WriteVector3DToStream(s, input.vertex3_);
        WriteNumberToStream<uint16_t>(s, input.attributes_);        
    }
}

const std::string STLParser::ToData(const std::vector<Material>& material) const
{
    std::vector<Triangle> allTriangles;
    for (const auto& m : material) {
        for (const auto& f : m.faces_) {
            std::vector<Triangle> t = GetTrianglesFromFace(f);
            allTriangles.insert(allTriangles.end(), t.begin(), t.end());
        }
    }

    std::stringstream ss;
    for (int i = 0; i < 80; ++i) {
        ss << 'a';
    }
    WriteNumberToStream<unsigned int>(ss, allTriangles.size());
    for (const auto& t : allTriangles) {
        WriteTriangleToStream(ss, t);
    }

    return ss.str();
}

std::vector<Material> STLParser::FromData(const std::string& data) const
{
    std::stringstream ss(data);
    // header
    char header[80];
    ss.read(header, 80);
    // triangle count
    unsigned int num_triangles = GetNumberFromStream<unsigned int>(ss);
    // triangles
    for(unsigned int i = 0; i < num_triangles; ++i) {
        auto t = GetTriangleFromStream(ss);
        (void)t;
        // todo create material from triangle
    }

    return {};
}

std::vector<Triangle> STLParser::GetTrianglesFromFace(const Face& face) const
{
    std::vector<Triangle> result;
    if (face.size() < 3) {
        return {};
    } 
    
    auto faceCopy = face;
    int first = 0;
    int second = 1;
    int third = 2;
    while(!faceCopy.empty()) {
        result.emplace_back(face[first].vn_, face[first].v_, face[second].v_, face[third].v_);
        if (faceCopy.size() == 3) {
            faceCopy.clear();  
            break;
        }
        faceCopy.erase(faceCopy.begin() + second);

        first = third;
        second = first+1;
        if (faceCopy.size() == 3) {
            third = 0;
        } else {
            third = second+1;
        }
        // TODO what if the angle is larger then 180?
    }
    
    return result;
}
