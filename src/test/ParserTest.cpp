#include "catch2.hpp"
#include "Parser.h"

class ParserA {
public:
    const std::string ToData(const std::vector<Material>&) const { return ""; }
    std::vector<Material> FromData(const std::string&) const 
    {
        std::vector<Material> m;
        Material mat1(std::string("mat1"), {});
        m.push_back(mat1);
        return m; 
    }
};

class ParserB {
public:
    const std::string ToData(const std::vector<Material>&) const { return ""; }
    std::vector<Material> FromData(const std::string&) { return {}; }
};

class NotAParserA {
};

class NotAParserB {
public:
    const std::string ToData(const std::vector<Material>&) const { return ""; }
};

class NotAParserC {
public:
    std::vector<Material> FromData(const std::string&) { return {}; }
};

TEST_CASE("Good Parser", "[parser]")
{
    ParserA a;
    SECTION( "have FromData const function" ) 
    {
        REQUIRE(parser::is_parser<ParserA>::value);
    }

    SECTION( "dont have FromData function" ) 
    {
        REQUIRE(parser::is_parser<ParserB>::value);
    }

    SECTION( "returns a material vector" ) 
    {
        auto m = parser::parse(a, "");
        REQUIRE(m.size() != 0);
    }
}

TEST_CASE("Wrong Parser", "[parser]")
{
    NotAParserA a;
    SECTION( "dont have FromData function" ) 
    {
        REQUIRE(parser::is_parser<NotAParserA>::value == false);
    }

    SECTION( "dont have FromData function" ) 
    {
        REQUIRE(parser::is_parser<NotAParserB>::value == false);
    }

    SECTION( "dont have FromData function" ) 
    {
        REQUIRE(parser::is_parser<NotAParserC>::value == false);
    }

    SECTION( "returns an empty material vector" ) 
    {
        auto m = parser::parse(a, "");
        REQUIRE(m.size() == 0);
    }

    SECTION( "returns an empty string" ) 
    {
        std::vector<Material> v;
        auto m = parser::parse(a, v);
        REQUIRE(m.empty());
    }
}

