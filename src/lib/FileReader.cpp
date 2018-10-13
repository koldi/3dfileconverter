#include "FileReader.h"
#include "Vector.h"
#include "Vertex.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>


Face CreateFace(const std::vector<Vector3D>& v,
                                            const std::vector<Vector2D>& vt,
                                            const std::vector<Vector3D>& vn,
                                            const std::vector<std::string>& vertices) 
{
    Face face;
    int i = 0;
    for(auto& t : vertices)
    {
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
        i++;
    }
    return face;
}

std::unique_ptr<FileReader> FileReader::CreateFileReader(std::string fileName)
{

    auto fileReader = new FileReader(fileName);
    if(!fileReader->ReadFile())
    {
        delete fileReader;
        fileReader = nullptr;
    }
    return std::unique_ptr<FileReader>(fileReader);
}

FileReader::FileReader(std::string fileName)
: fileName_(std::move(fileName))
{
}

bool FileReader::ReadFile()
{
    std::ifstream file(fileName_);

    if (!file.is_open())
		return false;

    // for v
    std::vector<Vector3D> v;
    // for vt
    std::vector<Vector2D> vt;
    // for vn
    std::vector<Vector3D> vn;
    // Vertex
  
    std::string line;
    while (std::getline(file, line))
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
            faces_.push_back(CreateFace(v, vt, vn, tokens));
        } else {
            continue;
        }
    }

    return true;
}
