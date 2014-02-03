#ifndef _PARSER_HPP
#define _PARSER_HPP

#include "Boost_Spirit_Config.hpp"

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>

namespace phx = boost::phoenix;
namespace qi  = boost::spirit::qi;

#include "Tokens.hpp"
#include "ast.hpp"

#include "SemanticActions.hpp"

namespace Parser
{
    template <typename Iterator>
        struct tip_grammar : qi::grammar<Iterator, Ast::program()>
    {
        template <typename TokenDef>
            tip_grammar(TokenDef const& tok)
            : tip_grammar::base_type(start)
            {
                start = program > qi::eoi
                      ;
                
                program = (*function)
                       [ qi::_val = build_program(qi::_1) ]
                      ;

                function = (identifier >> function_params >> function_body)
                        [ qi::_val = build_function(qi::_1, qi::_2, qi::_3) ]
                      ;

                function_params = (qi::raw_token(LEFT_PARENTHESE) >> formal_parameter_list >> qi::raw_token(RIGHT_PARENTHESE))
                      ;

                formal_parameter_list = -decl_list
                      ;

                function_body = (qi::raw_token(LEFT_BRACE) >> qi::raw_token(RIGHT_BRACE))
                        [ qi::_val = phx::construct<std::vector<Ast::statement>>() ]
                      ;

                identifier_list = (identifier >> *(qi::raw_token(COMMA) >> identifier))
                        [ qi::_val = build_identifier_list(qi::_1, qi::_2) ]
                                ;

                decl_list = (identifier_list)
                    [ qi::_val = build_decl_list(qi::_1) ]
                          ;

                identifier = tok.identifier
                           ;
            }  

        template<typename PRODUCE>
        using rule = qi::rule<Iterator, PRODUCE()>;

        rule<Ast::program> start;
        rule<Ast::program> program;
        rule<Ast::declaration> function;
        rule<std::vector<Ast::declaration>> function_params;
        rule<std::vector<Ast::declaration>> formal_parameter_list;
        rule<Ast::body> function_body;
        rule<std::vector<Ast::identifier>> identifier_list;
        rule<std::vector<Ast::declaration>> decl_list;
        rule<Ast::identifier> identifier;
    };

    template<typename T>
    using parser = tip_grammar<T>;
}

#endif // _PARSER_HPP
