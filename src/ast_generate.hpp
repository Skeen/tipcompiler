#ifndef _AST_GENERATE_HPP
#define _AST_GENERATE_HPP

#include "ast.hpp"

#include <string>

namespace Ast
{
    Ast::program generate_ast(std::string file_contents);
}

#endif //_AST_GENERATE_HPP
