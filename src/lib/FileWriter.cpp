#include "FileWriter.h"
#include "Vector.h"
#include "Vertex.h"
#include "STLParser.h"
#include "Parser.h"

#include <fstream>
#include <algorithm>

void FileWriter::WriteFile(std::string fileName, const std::vector<Material>& materials)
{
    FileWriter fileWriter = {fileName};
    std::string output;
    switch(fileWriter.ext_) {
        case FileType::stl:
            {
                STLParser parser;
                output = parser::parse(parser, materials);
            }
        case FileType::obj:
        case FileType::unknown:
            break;
    }
    fileWriter.FileWriterImpl(output);
}

FileWriter::FileWriter(std::string fileName)
: FileHandlerBase(std::move(fileName))
{}

void FileWriter::FileWriterImpl(const std::string& buffer)
{
    std::ofstream file;
    file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
    try {
        if (binary_)
            file.open (fileName_, std::ios::out | std::ios::binary);
        else
            file.open (fileName_, std::ios::out);

        if (!file.is_open())
		    return;

        file << buffer;
        file.close();
    }
    catch (std::ifstream::failure e) {
        file.close();
        return;
    }
}
