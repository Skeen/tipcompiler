#ifndef _COMPILER_ALGEBRAIC_DATATYPE_HPP
#define _COMPILER_ALGEBRAIC_DATATYPE_HPP

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 30
#define BOOST_MPL_LIMIT_VECTOR_SIZE 30

#include <boost/variant.hpp>

template<typename... Ts>
using algebraic_datatype  = boost::variant<Ts...>;

template<typename T>
using algebraic_recursive = boost::recursive_wrapper<T>;

#endif //_COMPILER_ALGEBRAIC_DATATYPE_HPP
