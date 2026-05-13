#include "Bureaucrat.hpp"

// Constructor — inicializa _name y _grade, valida que el grado esté entre 1 y 150
Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & src)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &src)
        this->_grade = src._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string const & Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

    void    Bureaucrat::incrementGrade()
    {
        if (_grade == 1)
            throw GradeTooHighException();
        _grade--;
    }

    void    Bureaucrat::decrementGrade()
    {
        if (_grade == 150)
            throw GradeTooLowException();
        _grade++;
    }

    const char * Bureaucrat::GradeTooHighException::what() const throw()
    {
        return "Grade is too high";
    }
    
    const char * Bureaucrat::GradeTooLowException::what() const throw()
    {
        return "Grade is too low";
    }

// operator<< — imprime "<nombre>, bureaucrat grade <grado>."
    std::ostream & operator<<(std::ostream & os, Bureaucrat const & b)
    {
        os << b.getName() << ", Bureaucrat grade " << b.getGrade() << ".";
        return (os);
    }