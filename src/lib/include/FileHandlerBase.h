#pragma once
#include <string>
#include <memory>
#include "FileType.h"

class FileHandlerBase 
{
protected:
    FileHandlerBase(std::string fileName)
    : fileName_(std::move(fileName))
    {
        auto ext = fileName_.substr(fileName_.find_last_of(".") + 1);
        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
        if (ext == "obj") {
            ext_ = FileType::obj;
            binary_ = false;
        } else if (ext == "stl") {
            ext_ = FileType::stl;
            binary_ = true;
        } else {
            ext_ = FileType::unknown;
            binary_ = false;
        }
    }

    std::string fileName_;
    FileType ext_;
    bool binary_ = false;
};
