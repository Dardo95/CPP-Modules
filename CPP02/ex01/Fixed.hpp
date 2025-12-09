#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_value;
	static const int	_fractionalBits;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	Fixed(int n);
	Fixed(float f);

	float 	toFloat(void) const;
	int		toInt(void) const;

	int		getRawBits (void) const;
	void	setRawBits	(int const raw);
};

std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

#endif