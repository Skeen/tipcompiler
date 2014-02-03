#ifndef _TOKENS_HPP
#define _TOKENS_HPP

#include "Boost_Spirit_Config.hpp"
#include <boost/spirit/include/lex_lexertl.hpp>

namespace lex = boost::spirit::lex;

enum TypesStart
{
    // 256 elements in each container
    Delimiters          = (lex::min_token_id + 0x0100) & 0xFF00,
    Identifier          = Delimiters         + 0x0100
};

enum DelimitersType
{
    Delimiters_Start = Delimiters,
    // Values
    LEFT_PARENTHESE,    // "("
    RIGHT_PARENTHESE,   // ")"
    LEFT_BRACE,         // "{"
    RIGHT_BRACE,        // "}"
    COMMA,              // ","
};

enum IdentifierType
{
    Identifier_Start = Identifier,
    // Values
    IDENTIFIER   // Pretty much, consumes everything else
};

#endif //_TOKENS_HPP
