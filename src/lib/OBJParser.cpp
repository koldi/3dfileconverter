#include "OBJParser.h"
#include "Material.h"
#include "Vector.h"
#include "Face.h"
#include <sstream>
#include <algorithm>

const std::string OBJParser::ToData(const std::vector<Material>& materials)  const
{
    (void)materials;
    return "";
}

std::vector<Material> OBJParser::FromData(const std::string& data) const
{
    std::vector<Material>  result;
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
                result.emplace_back(name, faces);
                faces.clear();
            }
            name = tokens[1];
        } else {
            continue;
        }
    }
    // save last material
    if (name != "unnamed" || !faces.empty()) {
        result.emplace_back(name, faces);
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
        // TODO index could be negateive
        if (t == "f")
            continue;
        auto delimiterCount = std::count_if(std::begin(t), std::end(t), [](char c){
            return c == '/';
        });
        if (delimiterCount == 0) {
            // TODO emplace, empty vectors
            Vertex vertex = {v[std::stoi(t) - 1], {}, {}};
            face.vertexList_.push_back(vertex);
        } else {
            std::istringstream streamToken(t);
            std::string item;
            std::vector<std::string> splittedStrings;
            while (std::getline(streamToken, item, '/'))
            {
                splittedStrings.push_back(item);
            }
            if (splittedStrings.size() == 2) {
                // TODO emplace, empty vectors
                Vertex vertex = {v[std::stoi(splittedStrings[0]) - 1], vt[std::stoi(splittedStrings[1]) - 1], {}};
                face.vertexList_.push_back(vertex);
            } else {
                // TODO emplace, empty vectors
                
                if(!splittedStrings[1].empty()) {
                    Vertex vertex = {v[std::stoi(splittedStrings[0]) - 1], vt[std::stoi(splittedStrings[1]) - 1], vn[std::stoi(splittedStrings[2]) - 1]};
                    face.vertexList_.push_back(vertex);
                } else {
                    Vertex vertex = {v[std::stoi(splittedStrings[0]) - 1], {}, vn[std::stoi(splittedStrings[2]) - 1]};
                    face.vertexList_.push_back(vertex);
                }
            }
        }
    }
    return face;
}