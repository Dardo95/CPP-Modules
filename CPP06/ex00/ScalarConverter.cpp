#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

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
    int i = 0;
    if (s[0] == '-')
        i = 1;
    if (s.length() == 0 || (i == 1 && s.length() == 1))
        return false;
    for (; i < (int)s.length() && isdigit(s[i]); i++);
    if (s[i] != '.')
        return false;
    i++;
    for (; i < (int)s.length() && isdigit(s[i]); i++);
    if (s[i] != 'f' || i + 1 != (int)s.length())
        return false;
    return true;
}

static bool isDouble(const std::string &s)
{
    int i = 0;
    if (s[0] == '-')
        i = 1;
    if (s.length() == 0 || (i == 1 && s.length() == 1))
        return false;
    for (; i < (int)s.length() && isdigit(s[i]); i++);
    if (s[i] != '.')
        return false;
    i++;
    for (; i < (int)s.length() && isdigit(s[i]); i++);
    if (i != (int)s.length())
        return false;
    return true;
}

static bool isPseudoFloat(const std::string &s)
{
    return (s == "-inff"|| s == "+inff"||s == "nanf");
}

static bool isPseudoDouble(const std::string &s)
{
    return (s == "-inf"|| s == "+inf"||s == "nan");
}

void ScalarConverter::convert(const std::string &literal)
{
    std::cout << std::fixed << std::setprecision(1);
    if (isChar(literal))
    {
        char c = literal[1];
        std::cout << "char: ";
        if (c >= 32 && c < 127)
            std::cout << "'" << c << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
    else if (isPseudoFloat(literal))
    {
        float f = strtof(literal.c_str(), NULL);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else if (isPseudoDouble(literal))
    {
        double d = strtod(literal.c_str(), NULL);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    else if (isInt(literal))
    {
       long n = strtol(literal.c_str(), NULL, 10);

      std::cout << "char: ";
      if (n < 0 || n > 127)
          std::cout << "impossible" << std::endl;
      else if (n < 32 || n == 127)
          std::cout << "Non displayable" << std::endl;
      else
          std::cout << "'" << static_cast<char>(n) << "'" << std::endl;

      std::cout << "int: ";
      if (n < INT_MIN || n > INT_MAX)
          std::cout << "impossible" << std::endl;
     else
         std::cout << static_cast<int>(n) << std::endl;

         
      std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
      std::cout << "double: " << static_cast<double>(n) << std::endl;
    }
    else if (isFloat(literal))
    {
        float f = strtof(literal.c_str(), NULL);
    
        std::cout << "char: ";
        if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
            std::cout << "impossible" << std::endl;
        else if (static_cast<int>(f) < 32 || static_cast<int>(f) == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    
        std::cout << "int: ";
        if (std::isnan(f) || std::isinf(f) || f > INT_MAX || f < INT_MIN)
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(f) << std::endl;
    
        std::cout << "float: " << f << "f" << std::endl;
    
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else if (isDouble(literal))
    {
        double d = strtod(literal.c_str(), NULL);
    
        std::cout << "char: ";
        if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
            std::cout << "impossible" << std::endl;
        else if (static_cast<int>(d) < 32 || static_cast<int>(d) == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    
        std::cout << "int: ";
        if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(d) << std::endl;
    
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    
        std::cout << "double: " << d << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}