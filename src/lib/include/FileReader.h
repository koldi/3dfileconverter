#pragma once
#include "FileHandlerBase.h"
#include "Material.h"

class FileReader : public FileHandlerBase
{
public:
    static std::vector<Material> ReadFile(std::string fileName);
private:
    FileReader(std::string fileName);
    bool ReadFileImpl(std::string& buffer);

    std::string buffer_;
};
