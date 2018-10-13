#pragma once
#include <string>
#include <memory>
#include "Face.h"

class FileReader 
{
public:
    static std::unique_ptr<FileReader> CreateFileReader(std::string fileName);
    FileReader(std::string fileName);
    bool ReadFile();
    std::string fileName_;
    std::vector<Face> faces_;
};
