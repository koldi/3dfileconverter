/**
 * File Writer class.
 * Inherits from FileHandlerBase.
 * It can write binary and text files.
 */

#pragma once
#include "FileHandlerBase.h"
#include "Material.h"

class FileWriter : public FileHandlerBase
{
public:
    /**
     * Write the file for the given file name,
     * parse the material list and create a string.
     * @param fileName: file name
     * @param materials: material list
     */
    static void WriteFile(std::string fileName, const std::vector<Material>& materials);
private:
    FileWriter(std::string fileName);
    void FileWriterImpl(const std::string& buffer);
};
