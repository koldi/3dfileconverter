#include "FileReader.h"
#include "Vector.h"
#include "Vertex.h"
#include "FileType.h"
#include "OBJParser.h"
#include "Parser.h"
#include <fstream>
#include <algorithm>

std::vector<Material> FileReader::ReadFile(std::string fileName)
{

    FileReader fileReader = {fileName};
    std::vector<char> buffer;
    if(!fileReader.ReadFile(buffer))
    {
        return {};
    }

    std::string input(buffer.begin(),buffer.end());
    switch(fileReader.ext_)
    {
        case FileType::obj:
            {
                OBJParser parser;
                return parser::parse(parser, input);
            }
        case FileType::stl:
            break;
        case FileType::unknown:
            break;
    }

    return {};
}

FileReader::FileReader(std::string fileName)
: fileName_(std::move(fileName))
{
    auto ext = fileName_.substr(fileName_.find_last_of(".") + 1);
    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    if (ext == "obj") {
        ext_ = FileType::obj;
    } else if (ext == "stl") {
        ext_ = FileType::stl;
    } else {
        ext_ = FileType::unknown;
    }
}

bool FileReader::ReadFile(std::vector<char>& buffer)
{
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
        file.close();
        return false;
    }
    
    return true;
}
