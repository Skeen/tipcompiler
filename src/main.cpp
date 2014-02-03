#include "ast.hpp"
#include "ast_generate.hpp"

#include <iostream>
#include <fstream>
#include <string>

std::string read_from_file(std::string infile)
{
    std::ifstream instream(infile);
    if (!instream.is_open()) {
        std::cerr << "Couldn't open file: " << infile << std::endl;
        exit(-1);
    }
    instream.unsetf(std::ios::skipws);      // No white space skipping!
    return std::string(std::istreambuf_iterator<char>(instream.rdbuf()),
                       std::istreambuf_iterator<char>());
}

int main(int /*argc*/, char* argv[])
{
    std::string file = argv[1];
    std::cout << "Input file is: " << file << std::endl;

    // If we reach this, we've got arguments!
    // So let's read the file into a string;
    std::string file_contents = read_from_file(file);

    Ast::program ast = Ast::generate_ast(file_contents);

    return 0;
}
