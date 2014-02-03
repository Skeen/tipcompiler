#ifndef _TO_STRING_HPP
#define _TO_STRING_HPP

#include <string>
#include <sstream>

// TODO: Get rid of this, once cygwin fix the real std::to_string

template<typename T>
inline std::string to_string(T val)
{
    std::ostringstream ss;
    ss << val;
    return ss.str();
}

#endif // _TO_STRING_HPP
