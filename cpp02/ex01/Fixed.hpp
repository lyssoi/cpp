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
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};
std::ostream& operator<<(std::ostream& out, const Fixed& other);

#endif