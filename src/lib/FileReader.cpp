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
    std::string input;
    
    if(!fileReader.ReadFileImpl(input))
    {
        return {};
    }

    switch(fileReader.ext_)
    {
        case FileType::obj:
            {
                OBJParser parser;
                return parser::parse(parser, input);
            }
        case FileType::stl:
        case FileType::unknown:
            break;
    }

    return {};
}

FileReader::FileReader(std::string fileName)
: FileHandlerBase(std::move(fileName))
{
}

bool FileReader::ReadFileImpl(std::string& buffer)
{
    std::ifstream file;
    file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
    try {
        if (binary_)
            file.open (fileName_, std::ios::in | std::ios::binary);
        else
            file.open (fileName_, std::ios::in);

        if (!file.is_open())
		    return false;

        buffer = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
    }
    catch (std::ifstream::failure e) {
        file.close();
        return false;
    }
    
    return true;
}
