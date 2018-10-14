/**
 * File Reader class.
 * Inherits from FileHandlerBase.
 * It can read binary and text files.
 */

#pragma once
#include "FileHandlerBase.h"

struct Material;

class FileReader : public FileHandlerBase
{
public:
    /**
     * Read the file for the given file name,
     * parse its content and create materials.
     * @param fileName: file name
     * @return Material list which the file contains
     *         in case of any error, the return vector is empty.
     */
    static std::vector<Material> ReadFile(std::string fileName);
private:
    FileReader(std::string fileName);
    bool ReadFileImpl(std::string& buffer);

    std::string buffer_;
};
