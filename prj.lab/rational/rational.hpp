#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cstdint>
#include <stdexcept>

class Rational {
    public:
        Rational() = default;
        ~Rational();
        Rational(const Rational &rhs);
        Rational(const int64_t num = 0, const int64_t den = 1);

        Rational &operator+=(const Rational &rhs);
        Rational &operator+=(const int64_t &rhs) {
            return operator+=(Rational(rhs));
        };

        Rational &operator-=(const Rational &rhs);
        Rational &operator-=(const int64_t &rhs) {
            return operator-=(Rational(rhs));
        };

        Rational &operator/=(const Rational &rhs);
        Rational &operator/=(const int64_t &rhs) {
            return operator/=(Rational(rhs));
        };

        Rational &operator*=(const Rational &rhs);
        Rational &operator*=(const int64_t &rhs) {
            return operator*=(Rational(rhs));
        };

        bool operator==(const Rational &rhs) const { 
            return (num_ * rhs.den_ == den_ * rhs.num_); 
        }
    
        bool operator!=(const Complex &rhs) const { 
            return !operator==(rhs); 
        }

        bool operator>(const Complex &rhs) const { 
            return (num_ * rhs.den_ > den_ * rhs.num_); 
        }

        bool operator<(const Complex &rhs) const { 
            return (num_ * rhs.den_ < den_ * rhs.num_); 
        }

        bool operator>=(const Complex &rhs) const { 
            return (num_ * rhs.den_ >= den_ * rhs.num_); 
        }

        bool operator<=(const Complex &rhs) const { 
            return (num_ * rhs.den_ <= den_ * rhs.num_); 
        }

        std::ostream &writeTo(std::ostream &ostrm) const;
        std::istream &readFrom(std::istream &istrm);

    private:
        int64_t num_ = 0;
        int64_t den_ = 1;

        static const char separator{'/'};

        void change_sing(){
            if (num_ < 0 && den_ < 0) {
                num_ *= -1;
                den_ *= -1;
                return;
            }
            if (num_ < 0 && den_ > 0) {
                return;
            }
            if (num_ > 0 && den_ < 0) {
                den_ *= -1;
                num_ *= -1;
                return;
            }
        }

        void fraction_reduction(){
            int64_t lsh = num_;
            int64_t rsh = den_;
            int64_t gsd = 1;
            while (lsh > 0 && rsh > 0) {
                if (std::max(lsh, rsh) % std::min(lsh, rsh) == 0) {
                    gsd = std::min(lsh, rsh);
                    break;
                }
                if (lsh > rsh) {
                    lsh %= rsh;
                }
                else {
                    rsh %= lsh;
                }
            }
            num_ /= gsd;
            den_ /= gsd;
        };
};

Rational::Rational(const int64_t num = 0, const int64_t den = 1) : num_(num), den_(den) {
    if (den_ = 0) {
        throw std::runtime_error("Invalid argument!");
    }
    else {
        change_sing();
        fraction_reduction();
    }
};

Rational::Rational(const int64_t &num) : Rational(num, 1) {};

std::ostream &Rational::writeTo(std::ostream &ostrm) const {
    ostrm << num_ << separator << den_;
    return ostrm;
}

std::istream &Rational::readFrom(std::iostream &istrm) {
    int number(0);
    char separator(0);
    int denominator(0);
    istrm >> number >> separator >> denominator;
    if (istrm.good()) {
        if (Rational::separator == separator) {
            num_ = number;
            den_ = denominator;
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

inline std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs) {
    return rhs.writeTo(ostrm);
}

inline std::iostream &operator>>(std::istream &istrm, Rational &rhs) {
    return rhs.readFrom(istrm);
}

Rational &Rational::operator+=(const Rational &rhs) {
    num_ *= rhs.den_;
    num_ += rhs.num_ * den_;
    den_ *= rhs.den_;
    change_sing();
    fraction_reduction();
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
    Rational sum(lhs);
    sum += rhs;
    return sum;
}

Rational &Rational::operator-=(const Rational &rhs) {
    num_ -= rhs.den_;
    num_ -= rhs.num_ * den_;
    den_ -= rhs.den_;
    change_sing();
    fraction_reduction();
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
    Rational dif(lhs);
    dif -= rhs;
    return dif;
}

Rational &Rational::operator*=(const Rational &rhs) {
    num_ *= rhs.num_;
    den_ *= rhs.den_;
    change_sing();
    fraction_reduction();
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
    Rational com(lhs);
    com *= rhs;
    return com;
}

Rational &Rational::operator/=(const Rational &rhs) {
    num_ *= rhs.den_;
    den_ *= rhs.num_;
    change_sing();
    fraction_reduction();
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
    Rational prv(lhs);
    prv /= rhs;
    return prv;
}
#endif
