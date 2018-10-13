#include "FileReader.h"
#include "Vector.h"
#include "Vertex.h"
#include <fstream>

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
    std::vector<char> buffer;
    std::ifstream file;
    file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
    try {
        file.open (fileName_);
        if (!file.is_open())
		    return false;

        file.seekg(0, std::ios::end);
        int fileSize = file.tellg();
        file.seekg(0, std::ios::beg);
        file.read((char *)&buffer, fileSize);
        file.close();
    }
    catch (std::ifstream::failure e) {
        return false;
    }
    
    return true;
}
