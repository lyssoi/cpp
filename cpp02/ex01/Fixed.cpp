#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    value = num << fracbit;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(num * (1 << fracbit));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;

    value = other.getRawBits();
    return (*this);
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
    return (static_cast<float> (value) / (1 << fracbit));
}

int Fixed::toInt(void) const
{
    return (static_cast<int>(value) >> fracbit);
}