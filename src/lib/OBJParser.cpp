#include "OBJParser.h"
#include "Material.h"
#include "Vector.h"
#include "Face.h"
#include <sstream>
#include <algorithm>

namespace {
    template<typename T>
    T GetElementByIndex(int index, const std::vector<T>& elements)
    {
        if (index > 0) {
            return elements[index-1];
        } else {
            return elements[elements.size()+index];
        }
    }
}

const std::string OBJParser::ToData(const std::vector<Material>&)  const
{
    assert(false && "Not implemented");
    return "";
}

std::vector<Material> OBJParser::FromData(const std::string& data) const
{
    std::vector<Material> result;
    // material name
    std::string name = "unnamed";
    // for v
    std::vector<Vector3D> v;
    // for vt
    std::vector<Vector2D> vt;
    // for vn
    std::vector<Vector3D> vn;
    // Faces
    std::vector<Face> faces;
  
    std::istringstream streamToken(data);
    std::string line;
    while (std::getline(streamToken, line))
    {
        if (line.empty())
            continue;
        std::istringstream streamLine(line);
        std::vector<std::string> tokens(std::istream_iterator<std::string>{streamLine}, std::istream_iterator<std::string>());

        const std::string& type = tokens[0];
        if (type == "v") {
            v.emplace_back(std::stof(tokens[1]),std::stof(tokens[2]),std::stof(tokens[3]));
        } else if (type == "vt") {
            vt.emplace_back(std::stof(tokens[1]),std::stof(tokens[2]));
        } else if (type == "vn") {
            vn.emplace_back(std::stof(tokens[1]),std::stof(tokens[2]),std::stof(tokens[3]));
        } else if (type == "f") {
            faces.push_back(OBJParser::CreateFace(v, vt, vn, tokens));
        } else if (type == "usemtl")  {
            // save previous material
            if (name != "unnamed" || !faces.empty()) {
                result.emplace_back(name, std::move(faces));
                faces.clear();
            }
            name = tokens[1];
        } else {
            continue;
        }
    }
    // save last material
    if (name != "unnamed" || !faces.empty()) {
        result.emplace_back(name, std::move(faces));
    }

    return result;
}

Face OBJParser::CreateFace(const std::vector<Vector3D>& v,
                            const std::vector<Vector2D>& vt,
                            const std::vector<Vector3D>& vn,
                            const std::vector<std::string>& vertices) const
{
    Face face;
    for(auto& t : vertices)
    {
        if (t == "f")
            continue;
        auto delimiterCount = std::count_if(std::begin(t), std::end(t), [](char c){
            return c == '/';
        });
        // f 1 2 3 4
        if (delimiterCount == 0) {
            face.emplace_back(Vertex{GetElementByIndex(std::stoi(t), v), {}, {}});
        } else {
            std::istringstream streamToken(t);
            std::string item;
            std::vector<std::string> splittedStrings;
            while (std::getline(streamToken, item, '/')) {
                splittedStrings.push_back(item);
            }
            // f 1/2 2/2 3/2
            if (splittedStrings.size() == 2) {
                face.push_back(Vertex{GetElementByIndex(std::stoi(splittedStrings[0]), v), 
                                      GetElementByIndex(std::stoi(splittedStrings[1]), vt), 
                                      {}});
            } else {                
                // f 1/2/1 2/2/1 3/2/1
                if(!splittedStrings[1].empty()) {
                    face.push_back(Vertex{GetElementByIndex(std::stoi(splittedStrings[0]), v), 
                                          GetElementByIndex(std::stoi(splittedStrings[1]), vt), 
                                          GetElementByIndex(std::stoi(splittedStrings[2]), vn)});
                // f 1//2 2//2 3//2
                } else {
                    face.push_back(Vertex{GetElementByIndex(std::stoi(splittedStrings[0]), v), 
                                          {}, 
                                          GetElementByIndex(std::stoi(splittedStrings[2]), vn)});
                }
            }
        }
    }
    return face;
}
