#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(std::string const & name, int gradeToSign, int gradeToExecute);
        AForm(AForm const & src);
        AForm & operator=(AForm const & src);
        virtual ~AForm();

        std::string const & getName() const;
        bool                getIsSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;

        void    beSigned(Bureaucrat const & b);
        void    execute(Bureaucrat const & executor) const;

        virtual void    executeAction() const = 0;

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

        class FormNotSignedException : public std::exception
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

std::ostream & operator<<(std::ostream & o, AForm const & f);

#endif