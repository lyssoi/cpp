#include "Fixed.hpp"

Fixed::Fixed(void)
{
    value = 0;
}

Fixed::Fixed(const int num)
{
    value = num << fracbit;
}

Fixed::Fixed(const float num)
{
    value = roundf(num * (1 << fracbit));
}

Fixed::Fixed(const Fixed& other)
{
	value = other.getRawBits();
}

Fixed::~Fixed(void)
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		value = other.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed& other) const
{
    return (getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
    return (getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (Fixed(toFloat() / other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed(toFloat() * other.toFloat()));
}

Fixed& Fixed::operator++(void)
{
    value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    const Fixed temp(*this);

    value++;
    return (temp);
}

Fixed& Fixed::operator--(void)
{
    value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    const Fixed temp(*this);

    value--;
    return (temp);
}

Fixed& Fixed::min(Fixed &other1,Fixed &other2)
{
    if (other1 <= other2)
        return other1;
    return other2;
}

const Fixed& Fixed::min(const Fixed &other1, const Fixed &other2)
{
    if (other1 <= other2)
        return other1;
    return other2;
}

Fixed& Fixed::max(Fixed &other1,Fixed &other2)
{
    if (other1 >= other2)
        return other1;
    return other2;
}

const Fixed& Fixed::max(const Fixed &other1, const Fixed &other2)
{
    if (other1 >= other2)
        return other1;
    return other2;
}

int Fixed::getRawBits(void) const
{
    return (value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(value) / (1 << fracbit));
}

int Fixed::toInt(void) const
{
    return (static_cast<int>(value) >> fracbit);
}

std::ostream& operator <<(std::ostream& out, const Fixed& other)
{
    out << other.toFloat();
    return out; 
}