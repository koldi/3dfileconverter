#pragma once
#include <utility>
#include <variant>
#include "OBJParser.h"

template<typename ... Base>
struct Visitor : Base ...
{
    using Base::operator()...;
};

template<typename ... T> Visitor(T...) -> Visitor<T...>;

class Parser
{
public:
    void parse()
    {
        std::visit(visitor, parsers);
    }
private:
    Visitor visitor = {
        [](OBJParser p) -> std::vector<Material> { return p.FromOBJ(""); }
    }
    std::variant<OBJParser> parsers;
}