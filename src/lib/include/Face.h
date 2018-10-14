#pragma once

#include <vector>
#include <iostream>
#include "Vertex.h"

using Face = std::vector<Vertex>;

// struct Face
// {
//     std::vector<Vertex> vertexList_;
//     void ToString() const {
//         for (auto v : vertexList_) {
//             std::cout << "Vertex: \n";
//             v.ToString();
//         }
//         std::cout << std::flush;
//     }
// };