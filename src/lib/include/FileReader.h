#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Material.h"

enum class FileType;

class FileReader 
{
public:
    static std::vector<Material> ReadFile(std::string fileName);
private:
    FileReader(std::string fileName);
    bool ReadFileImpl(std::string& buffer);

    std::string fileName_;
    FileType ext_;
    std::string buffer_;
};
