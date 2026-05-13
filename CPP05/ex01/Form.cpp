#include "Form.hpp"

// TODO: Constructor — inicializa todos los atributos, valida los dos grados
Form::Form(std::string const & name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    _isSigned = false;
    if (_gradeToSign < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150)
        throw GradeTooLowException();
    if (_gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToExecute > 150)
        throw GradeTooLowException();
}

// TODO: Copy constructor
Form::Form(Form const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}


// TODO: Assignment operator — solo copia _isSigned (el resto son const)
Form &Form::operator=(Form const & src)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &src)
        this->_isSigned = src._isSigned;
    return *this;
}

// TODO: Destructor
Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

// TODO: getName()
std::string const & Form::getName() const
{
    return _name;
}

// TODO: getIsSigned()
bool Form::getIsSigned() const
{
    return _isSigned;
}

// TODO: getGradeToSign()
int Form::getGradeToSign() const
{
    return _gradeToSign;
}

// TODO: getGradeToExecute()
int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

// TODO: beSigned() — firma el formulario si el grado del burócrata es suficiente
void Form::beSigned(Bureaucrat const & b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// TODO: GradeTooHighException::what()
const char * Form::GradeTooHighException::what() const throw()
{
    return "Grade is too High";
}

// TODO: GradeTooLowException::what()
const char * Form::GradeTooLowException::what() const throw()
{
    return "Grade is too Low";
}

// TODO: operator<< — imprime toda la información del formulario
std::ostream & operator<<(std::ostream & o, Form const & f)
{
    o << "Form: " << f.getName()
        << " Form is signed: " << f.getIsSigned()
        << " Bureaucrat can sign " << f.getGradeToSign()
        << " Bureaucrat can execute " <<f.getGradeToExecute();
    return (o);
}
