#ifndef _LEXER_HPP
#define _LEXER_HPP

#include "Boost_Spirit_Config.hpp"
#include <boost/spirit/include/lex_lexertl.hpp>

#include "Tokens.hpp"

namespace lex = boost::spirit::lex;
/*
namespace Lexer
{
*/
    template<typename Lexer>
    struct tip_tokens : lex::lexer<Lexer>
    {
        lex::token_def<std::string> identifier;

        lex::token_def<lex::omit> line_terminator;
        lex::token_def<lex::omit> whitespace;
        lex::token_def<std::string> line_comment;
        lex::token_def<std::string> block_comment;

        tip_tokens()
        {
            // Define regex macros
            this->self.add_pattern
                ("LINE_FEED",       "\n")
                ("CARRIAGE_RETURN", "\r")
                ("SPACE",           " ")
                ("HORIZONTAL_TAB",  "\t")
                ("LETTER",          "[A-Z]|[a-z]")
                ("TIP_LETTER",      "{LETTER}|_|{DIGIT}")
                ;

        // Define the tokens' regular expressions
        identifier      = "{LETTER}{TIP_LETTER}*";

        line_terminator = "{LINE_FEED}|{CARRIAGE_RETURN}|{CARRIAGE_RETURN}{LINE_FEED}";
        whitespace      = "{SPACE}|{HORIZONTAL_TAB}";
        line_comment    = "\\/\\/[^\r\n]*";
        block_comment   = "\\/\\*[^(\\*\\/)]*\\*\\/";

        this->self += whitespace      [ lex::_pass = lex::pass_flags::pass_ignore ]
                    | line_terminator [ lex::_pass = lex::pass_flags::pass_ignore ]
                    | line_comment    [ lex::_pass = lex::pass_flags::pass_ignore ]
                    | block_comment   [ lex::_pass = lex::pass_flags::pass_ignore ]
                   ;

        this->self.add
            // Delimiters
            ('(',           LEFT_PARENTHESE)
            (')',           RIGHT_PARENTHESE)
            ('{',           LEFT_BRACE)
            ('}',           RIGHT_BRACE)
            (',',           COMMA)
            // Comsume rest as identifiers
            (identifier,    IDENTIFIER)
        ;
    }
    };

namespace Lexer
{
    // This is our input type (the type, used to expose the underlying input stream)
    using lexer_iterator_type = std::string::iterator;
    // This is a list of all the attributes that the lexer exposes
    using lexer_exposed_types = boost::mpl::vector<std::string>;
    // This is our token type
    using lexer_token_type = lex::lexertl::token<lexer_iterator_type, lexer_exposed_types, boost::mpl::false_>;
    // This is the general form type of our lexer
    using lexer_type = lex::lexertl::actor_lexer<lexer_token_type>;
    // This is our final lexer type (which can be used)
    using lexer = tip_tokens<lexer_type>;
    // This is the output (iterator) type of our lexer
    using lexer_iterator = lexer::iterator_type;
}

#endif //_LEXER_HPP

