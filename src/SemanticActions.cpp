#include "SemanticActions.hpp"

#include <algorithm>

Ast::program build_program_(std::vector<Ast::declaration> functions)
{
    return ((Ast::program) {functions});
}

Ast::declaration build_function_(Ast::identifier id,
                                 std::vector<Ast::declaration> params,
                                 Ast::body function_body)
{
    std::vector<Ast::identifier> params_correct;
    std::transform(params.begin(), params.end(), params_correct.begin(),
                   [](Ast::declaration arg)
    {
        auto dl = boost::get<Ast::declaration_local>(arg);
        return dl.name;
    });

    return ((Ast::declaration_function) {id, params_correct, function_body});
}

std::vector<Ast::identifier>
build_identifier_list_(Ast::identifier id, std::vector<Ast::identifier> ids)
{
    ids.insert(ids.begin(), id);
    return ids;
}

Ast::identifier build_identifier_(std::string id)
{
    return ((Ast::identifier) {id});
}

std::vector<Ast::declaration> build_decl_list_(std::vector<Ast::identifier> ids)
{
    std::vector<Ast::declaration> decl_list;
    for (Ast::identifier id : ids)
    {
        auto decl = ((Ast::declaration_local) {id});
        decl_list.push_back(decl);
    }
    return decl_list;
}
