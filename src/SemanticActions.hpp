#ifndef _SEMANTIC_ACTIONS_HPP
#define _SEMANTIC_ACTIONS_HPP

#include "ast.hpp"

#include <boost/phoenix/function/adapt_function.hpp>

Ast::program build_program_(std::vector<Ast::declaration> functions);
BOOST_PHOENIX_ADAPT_FUNCTION(Ast::program, build_program, build_program_, 1);

Ast::declaration build_function_(Ast::identifier id,
                                 std::vector<Ast::declaration> params,
                                 Ast::body function_body);
BOOST_PHOENIX_ADAPT_FUNCTION(Ast::declaration, build_function, build_function_, 3);

std::vector<Ast::identifier> build_identifier_list_(Ast::identifier id, std::vector<Ast::identifier> ids);
BOOST_PHOENIX_ADAPT_FUNCTION(std::vector<Ast::identifier>, build_identifier_list, build_identifier_list_, 2);

Ast::identifier build_identifier_(std::string id);
BOOST_PHOENIX_ADAPT_FUNCTION(Ast::identifier, build_identifier, build_identifier_, 1);

std::vector<Ast::declaration> build_decl_list_(std::vector<Ast::identifier> ids);
BOOST_PHOENIX_ADAPT_FUNCTION(std::vector<Ast::declaration>, build_decl_list, build_decl_list_, 1);

#endif //_SEMANTIC_ACTIONS_HPP
