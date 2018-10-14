#include <iostream>
#include <fstream>
#include "FileReader.h"
#include "STLParser.h"

  struct point {
    float x;
    float y;
    float z;

    point() : x(0), y(0), z(0) {}
    point(float xp, float yp, float zp) : x(xp), y(yp), z(zp) {}

       void ToString(){
      std::cout << x << ", " << y << ", " << z << std::endl;
    }
  };

  struct triangle {
    point normal;
    point v1;
    point v2;
    point v3;
    triangle(point normalp, point v1p, point v2p, point v3p) :
      normal(normalp), v1(v1p), v2(v2p), v3(v3p) {}
    void ToString(){
      v1.ToString();
      v2.ToString();
      v3.ToString();
    }
  };

  std::ostream& operator<<(std::ostream& out, const triangle& t);

std::ostream& operator<<(std::ostream& out, const point p) {
    out << "(" << p.x << ", " << p.y << ", " << p.z << ")" << std::endl;
    return out;
  }

  std::ostream& operator<<(std::ostream& out, const triangle& t) {
    out << "---- TRIANGLE ----" << std::endl;
    out << t.normal << std::endl;
    out << t.v1 << std::endl;
    out << t.v2 << std::endl;
    out << t.v3 << std::endl;
    return out;
  }
  
  float parse_float(std::ifstream& s) {
    char f_buf[sizeof(float)];
    s.read(f_buf, 4);
    float* fptr = (float*) f_buf;
    return *fptr;
  }

  point parse_point(std::ifstream& s) {
    float x = parse_float(s);
    float y = parse_float(s);
    float z = parse_float(s);
    return point(x, y, z);
  }

int main ()
{
  auto f = FileReader::ReadFile("/Users/gyorgykatona/git/3dfileconverter/input/input.obj");
  STLParser parser;
  parser.ToData(f);
  // for(auto k : f)
  // {
  //   std::cout << "Material name: " << k.name_;
  //   for(auto t : k.faces_)
  //   {
  //     t.ToString();
  //   }
  // }

  // std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
  //   // copies all data into buffer
  //   std::ifstream stl_file("/Users/gyorgykatona/git/3dfileconverter/input/untitled.stl", std::ios::in | std::ios::binary);

  //   std::string buffer = std::string((std::istreambuf_iterator<char>(stl_file)), std::istreambuf_iterator<char>());
  //   stl_file.close();

  //   STLParser parser;
  //   parser.FromData(buffer);

  // std::ifstream stl_file("/Users/gyorgykatona/git/3dfileconverter/input/untitled.stl", std::ios::in | std::ios::binary);
  //   if (!stl_file) {
  //     std::cout << "ERROR: COULD NOT READ FILE" << std::endl;
  //     assert(false);
  //   }

  //   char header_info[80] = "";
  //   char n_triangles[4];
  //   stl_file.read(header_info, 80);
  //   stl_file.read(n_triangles, 4);
  //   std::string h(header_info);
  //   // stl_data info(h);
  //   std::vector<triangle> triangles;
  //   unsigned int* r = (unsigned int*) n_triangles;
  //   unsigned int num_triangles = *r;
  //   for (unsigned int i = 0; i < num_triangles; i++) {
  //     auto normal = parse_point(stl_file);
  //     auto v1 = parse_point(stl_file);
  //     auto v2 = parse_point(stl_file);
  //     auto v3 = parse_point(stl_file);
  //     triangles.push_back(triangle(normal, v1, v2, v3));
  //     char dummy[2];
  //     stl_file.read(dummy, 2);
  //   }

  // std::cout << triangles.size() << std::endl;
  // for(auto t : triangles) {
  //   t.ToString();
  // }

  return 0;
}