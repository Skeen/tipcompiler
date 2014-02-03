#include "ast_generate.hpp"

#include "Parser.hpp"
#include "Lexer.hpp"

#include "Boost_Spirit_Config.hpp"
#include <boost/spirit/include/lex_lexertl.hpp>

namespace lex = boost::spirit::lex;

namespace Ast
{
    Ast::program generate_ast(std::string file_contents)
    {
        // We'll instance our lexer
        Lexer::lexer lexi;
        // And our parser, based upon our lexer
        Parser::parser<Lexer::lexer_iterator> parsi(lexi);
        // Then we'll prepare an output variable
        Ast::program program;
        // And we'll prepare our input iterators
        Lexer::lexer_iterator_type begin = file_contents.begin();
        Lexer::lexer_iterator_type end   = file_contents.end();
    
        // Now let's run the lexer, and pipe it into the parser, to generate the source_file node.
        bool b = lex::tokenize_and_parse(begin, end, lexi, parsi, program);
        // If we were able to lex and parse
        std::cout << "lex & parse: ";
        if(b)
        {
            std::cout << "succes" << std::endl;
            // Return the parsed ast node
            return program;
        }
        // Unable to lex and parse == error
        else
        {
            std::cout << "failure" << std::endl;
            exit(-1);
        }
    }
}
