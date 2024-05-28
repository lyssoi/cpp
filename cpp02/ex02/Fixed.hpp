#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed{
    private:
        int value;
        static const int fracbit = 8;
    public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed(const int num);
        Fixed(const float num);
        Fixed& operator=(const Fixed& other);
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
        static Fixed& min(Fixed &other1, Fixed &other2);
        static const Fixed& min(const Fixed &other1, const Fixed &other2);
        static Fixed& max(Fixed &other1, Fixed &other2);
        static const Fixed& max(const Fixed &other1, const Fixed &other2);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};


#endif