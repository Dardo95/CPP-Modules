#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
    private:
        ScalarConverter();                                          // (1)
        ScalarConverter(const ScalarConverter &src);               // (2)
        ScalarConverter &operator=(const ScalarConverter &src);    // (3)
        ~ScalarConverter();                                        // (4)

    public:
        static void convert(const std::string &literal);          // (5)
};

#endif