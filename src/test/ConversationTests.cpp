#include "catch2.hpp"
#include "STLParser.h"
#include "OBJParser.h"
#include "Material.h"
#include <vector>

std::string minimalOBJFileDataForConversation = R"(
v 1.000000 -1.000000 -1.000000
v 1.000000 -1.000000 1.000000
v -1.000000 -1.000000 1.000000
v -1.000000 -1.000000 -1.000000
vt 1.0000 1.0000
vt -1.0000 1.0000
vn 0.0000 -1.0000 0.0000
vn 0.0000 1.0000 0.0000
vn 1.0000 0.0000 0.0000
vn -0.0000 -0.0000 1.0000
usemtl Material
f 1 2 3 4
f 1/1 2/2 3/1 4/2
f 1/1/1 2/2/2 3/1/3 4/2/4
f 1//1 2//2 3//3 4//4
)";

TEST_CASE("Conversation", "[parser]")
{
    STLParser stlParser;
    OBJParser objParser;
    SECTION( " minimal data object " ) 
    {
        auto material = objParser.FromData(minimalOBJFileDataForConversation);
        auto stlString = stlParser.ToData(material);

        REQUIRE(!stlString.empty());
    }
}
