#ifndef _COMPILER_AST_HPP
#define _COMPILER_AST_HPP

#include <string>
#include <vector>

#include "Match/algebraic_datatype.hpp"

namespace Ast
{
    struct declaration_function;
    struct declaration_local;

    using declaration = algebraic_datatype<
        declaration_function,
        declaration_local
        >;

    struct identifier
    {
        std::string identifier_string;
    };

    struct statement final
    {
    };
    using body = std::vector<statement>;

    struct declaration_function
    {
        identifier name;
        std::vector<identifier> arguments;
        body function_body;
    };

    struct declaration_local
    {
        identifier name;
    };

    struct program
    {
        std::vector<Ast::declaration> function_environment;
    };
}

#endif //_COMPILER_AST_HPP
