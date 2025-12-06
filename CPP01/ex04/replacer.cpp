#include "Replacer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

bool replaceInFile(const std::string &filename,
                   const std::string &s1,
                   const std::string &s2)
{
    std::ifstream in(filename.c_str());
    if (!in)
    {
        std::cerr << "Error: could not open input file: " << filename << std::endl;
        return false;
    }

    std::string outname = filename + ".replace";
    std::ofstream out(outname.c_str());
    if (!out)
    {
        std::cerr << "Error: could not create output file: " << outname << std::endl;
        return false;
    }

    std::ostringstream buffer;
    buffer << in.rdbuf();
    std::string content = buffer.str();

    std::string result;
    result.reserve(content.size());

    std::size_t pos = 0;
    std::size_t found;

    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }

    result.append(content, pos, content.length() - pos);

    out << result;

    return true;
}
