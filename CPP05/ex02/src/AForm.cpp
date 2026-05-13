#include "AForm.hpp"

// TODO: Constructor — inicializa todos los atributos, valida los dos grados
AForm::AForm(std::string const & name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
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
AForm::AForm(AForm const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}


// TODO: Assignment operator — solo copia _isSigned (el resto son const)
AForm &AForm::operator=(AForm const & src)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &src)
        this->_isSigned = src._isSigned;
    return *this;
}

// TODO: Destructor
AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

// TODO: getName()
std::string const & AForm::getName() const
{
    return _name;
}

// TODO: getIsSigned()
bool AForm::getIsSigned() const
{
    return _isSigned;
}

// TODO: getGradeToSign()
int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

// TODO: getGradeToExecute()
int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

// TODO: beSigned() — firma el formulario si el grado del burócrata es suficiente
void AForm::beSigned(Bureaucrat const & b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (_isSigned != true)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

// TODO: GradeTooHighException::what()
const char * AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too High";
}

// TODO: GradeTooLowException::what()
const char * AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too Low";
}

const char * AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

// TODO: operator<< — imprime toda la información del formulario
std::ostream & operator<<(std::ostream & o, AForm const & f)
{
    o << "AForm: " << f.getName()
        << " Form is signed: " << f.getIsSigned()
        << " Bureaucrat can sign " << f.getGradeToSign()
        << " Bureaucrat can execute " <<f.getGradeToExecute();
    return (o);
}
