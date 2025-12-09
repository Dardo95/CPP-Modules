#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractionalBits;
}

Fixed::Fixed(float f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

int		Fixed::getRawBits (void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}
void	Fixed::setRawBits	(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	os << fixed.toFloat();
	return (os);
}