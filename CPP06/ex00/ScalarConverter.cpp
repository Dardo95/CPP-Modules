#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>

void ScalarConverter::convert(const std::string &literal)
{
    
}

static bool isChar(const std::string &s)
{ 
    return (s.length() == 3 && s[0] == '\'' && s[2] == '\'' );
}

static bool isInt(const std::string &s)
{ 
    int i = 0;
    if (s[0] == '-')
        i = 1;
    if (s.length() == 0 || (i == 1 && s.length() == 1))
        return false;
    for (; i < (int)s.length(); i++)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

static bool isFloat(const std::string &s)
{

}
static bool isDouble(const std::string &s)
{

}
static bool isPseudoFloat(const std::string &s)
{

}
static bool isPseudoDouble(const std::string &s)
{

}