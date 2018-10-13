#pragma once
#include <string>
#include <memory>
#include "Face.h"

class FileReader 
{
public:
    static std::unique_ptr<FileReader> CreateFileReader(std::string fileName);
private:
    FileReader(std::string fileName);
    bool ReadFile();

    std::string fileName_;
    std::string buffer_;
};
