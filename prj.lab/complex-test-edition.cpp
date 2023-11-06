#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

struct Complex {
    Complex() {}
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);

    Complex &operator+=(const Complex &rhs);
    Complex &operator+=(const double rhs) { 
        return operator+=(Complex(rhs)); 
    }

    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs) {
        return operator-=(Complex(rhs)); 
    }

    Complex &operator*=(const Complex& rsh);
    Complex &operator*=(const double rhs) {
        return operator*=(Complex(rhs));
    };

    Complex &operator/=(const Complex& rsh);
    Complex &operator/=(const double rsh) {
        return operator/=(Complex(rsh));
    };

    bool operator==(const Complex &rhs) const { 
        return (re == rhs.re) && (im == rhs.im); 
    }
    
    bool operator!=(const Complex &rhs) const { 
        return !operator==(rhs); 
    }

    std::ostream &writeTo(std::ostream &ostrm) const;
    std::istream &readFrom(std::istream &istrm);

    double re{0.0};
    double im{0.0};

    static const char leftBrace{'{'};
    static const char separator{','};
    static const char rightBrace{'}'};
};

Complex::Complex(const double real) : Complex(real, 0.0) {}

Complex::Complex(const double real, const double imaginary) : re(real), im(imaginary) {}

std::istream &Complex::readFrom(std::istream &istrm) {
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaganary;
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

std::ostream &Complex::writeTo(std::ostream &ostrm) const {
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

inline std::ostream &operator<<(std::ostream &ostrm, const Complex &rhs) {
    return rhs.writeTo(ostrm);
}

inline std::istream &operator>>(std::istream &istrm, Complex &rhs) {
    return rhs.readFrom(istrm);
}

Complex &Complex::operator+=(const Complex &rhs) {
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex operator+(const Complex &lhs, const Complex &rhs) {
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator-(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex &Complex::operator*=(const Complex &rsh) {
    if (re == rsh.re && im == -1 * rsh.im) {
        re = pow(re, 2) + pow(im, 2);
        im = 0.0;
    }
    else {
        re = re * rsh.re - im * rsh.im;
        im = im * rsh.re + re * rsh.im;
    }
    return *this;
}

Complex operator*(const Complex &lhs, const Complex &rhs) {
    Complex product(lhs);
    product *= rhs;
    return product;
}

Complex &Complex::operator/=(const Complex &rsh) {
    if (rsh.re == 0 && rsh.im == 0){
        throw std::runtime_error("Division by zero!");
    }
    re = (re * rsh.re + im * rsh.im) / (rsh.re * rsh.re + rsh.im * rsh.im);
    im = (re * rsh.im - im * rsh.re) / (rsh.re * rsh.re + rsh.im * rsh.im);
    return *this;
}

Complex operator/(const Complex &lhs, const Complex &rhs) {
    Complex quotient(lhs);
    quotient /= rhs;
    return quotient; 
}

Complex pow (const Complex &lhs, const double rhs) {
    Complex product(lhs);
    double hypotenuse = pow((pow(lhs.re, 2) + pow(lhs.im, 2)), 0.5);
    double corner = abs(acos(lhs.im / pow(hypotenuse, 0.5)));
    hypotenuse = pow(hypotenuse, rhs);
    product.re = hypotenuse * cos(rhs * corner);
    product.im = hypotenuse * sin(rhs * corner);
    return product;
}

void testParse(const std::string &str) {
    std::istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        std::cout << "Read success: " << str << " -> " << z << std::endl;
    }
    else {
        std::cout << "Read error : " << str << " -> " << z << std::endl;
    }
}

void testBaseArimetic(const Complex &lhs, const Complex &rhs, const char &operation_type){
    std::cout<<lhs<<" "<<operation_type<<" "<<rhs<<" = ";
    switch (operation_type) {
        case '+':
            std::cout<<lhs + rhs;
            break;
        case '-':
            std::cout<<lhs - rhs;
            break;
        case '*':
            std::cout<<lhs * rhs;
            break;
        case '/':
            try {
                std::cout<<lhs / rhs;
            }
            catch(const std::exception& e) {
                std::cout<<"error ";
                std::cerr << e.what();
            }
            break;
    }
    std::cout<<std::endl;
}

void testPow(const Complex &lhs, const double &rhs){
    std::cout<<"pow("<<lhs<<", "<<rhs<<") = "<<pow(lhs, rhs)<<std::endl;
}

int main(){
    Complex a(13., 4.);
    Complex b(2.3, 4.7);
    Complex c(6.1, 3.9);
    Complex d(8.2, 0.9);
    Complex e(12.3, 2.3);
    Complex f(0);
    Complex g(6.1, -3.9);
    double first_number = 2;
    double second_number = 0.5;
    double third_number = 3.5;
    double fourth_number = 5;
    std::cout<<"Тестирование конвертации из строки в тип и вывода в консоль:"<<std::endl;
    testParse("{13, 6}");
    testParse("{13 , 6}");
    testParse("{13,6}");
    testParse("{13 ,6}");
    testParse("{13, 6");
    testParse("13, 6}");
    std::cout<<"Тестирование суммы"<<std::endl;
    testBaseArimetic(a, b, '+');
    std::cout<<"Тестирование вычитания"<<std::endl;
    testBaseArimetic(c, d, '-');
    std::cout<<"Тестирование умножения"<<std::endl;
    testBaseArimetic(a, b, '*');
    testBaseArimetic(c, g, '*');
    std::cout<<"Тестирование деления"<<std::endl;
    testBaseArimetic(e, d, '/');
    testBaseArimetic(e, f, '/');
    std::cout<<"Тестирование возведение в степень"<<std::endl;
    testPow(a, first_number);
    testPow(b, second_number);
    testPow(c, third_number);
    testPow(d, fourth_number);
}