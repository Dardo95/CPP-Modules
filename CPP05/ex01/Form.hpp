#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(std::string const & name, int gradeToSign, int gradeToExecute);
        Form(Form const & src);
        Form & operator=(Form const & src);
        ~Form();

        std::string const & getName() const;
        bool                getIsSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;

        void    beSigned(Bureaucrat const & b);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _gradeToSign;
        int const           _gradeToExecute;
};

std::ostream & operator<<(std::ostream & o, Form const & f);

#endif