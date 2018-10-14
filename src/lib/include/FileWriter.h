#pragma once
#include "FileHandlerBase.h"
#include "Material.h"

class FileWriter : public FileHandlerBase
{
public:
    static void WriteFile(std::string fileName, const std::vector<Material>& materials);
private:
    FileWriter(std::string fileName);
    void FileWriterImpl(const std::string& buffer);
};
