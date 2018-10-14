#pragma once
#include <utility>
#include <vector>
#include "Material.h"
#include "OBJParser.h"

namespace parser 
{
    template<typename T>
    struct is_parser
    {
        template <class, class, class> class checker;

        template <typename C>
        static std::true_type test(checker<C, decltype(&C::FromData), decltype(&C::ToData)> *);

        template <typename C>
        static std::false_type test(...);

        typedef decltype(test<T>(nullptr)) type;
        static const bool value = std::is_same<std::true_type, decltype(test<T>(nullptr))>::value;

        static std::vector<Material> parse(const T& t, const std::string& data, std::true_type) {
            return t.FromData(data);
        }

        static std::vector<Material> parse(const T&, const std::string&, std::false_type){
            return {};      
        }

        static std::vector<Material> parse(const T& t, const std::string& data) {
            return parse(t, data, type());
        }

        static std::string parse(const T& t, const std::vector<Material>& data, std::true_type) {
            return t.ToData(data);
        }

        static std::string parse(const T&, const std::vector<Material>&, std::false_type){
            return {};      
        }

        static std::string parse(const T& t, const std::vector<Material>& data) {
            return parse(t, data, type());
        }
    };

    template<typename T>
    std::vector<Material> parse(const T& parser, const std::string& data)
    {
        return is_parser<T>::parse(parser, data);
    }

    template<typename T>
    std::string parse(const T& parser, const std::vector<Material>& data)
    {
        return is_parser<T>::parse(parser, data);
    }
};

