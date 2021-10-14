#include <iostream>
#include <exception>
#include <cmath>
using namespace std;
class FractionExeption:public exception{
private:
    std::string m_error;

public:
    FractionExeption(std::string error): m_error(error){}

    const char* what() const noexcept {
        return m_error.c_str();
    }
};
class Fraction{
public:
    Fraction(int numerator, int denominator){
        num = numerator;
        if (denominator == 0){
            throw FractionExeption("Denominator cannot be zero");
        }
        den = denominator;

    }
    Fraction(double fract, int accuracy){
        num = fract * pow(10, accuracy);
        den = pow(10, accuracy);
    }
    int getNumerator(){
        return num;
    }
    int getDenominator(){
        return den;
    }
    double getDecimal(){
        return (double)num/(double)den;
    }
    static double getDecimalForFraction(int numerator, int denominator){
        if (denominator == 0){
            throw FractionExeption("Denominator cannot be zero");
        }
        return (double)numerator/(double)denominator;
    }

    void setNumerator(int numerator){
        num = numerator;
    }
    void setDenominator(int denominator){
        if (denominator == 0){
            throw FractionExeption("Denominator cannot be zero ");
        }
       den = denominator;
    }
    Fraction getReducedFraction(){
        int comFact = gcd(abs(num), abs(den));
        return Fraction(num/comFact, den/comFact);
    }
    void setReducedFraction(){
        int comFact = gcd(abs(num), abs(den));
        num/=comFact;
        den/=comFact;
    }
    void display(){
            cout << num << "/" << den;
        }

private:
    int num;
    int den;

    int gcd(int a, int b) {
        while (b != 0) {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }

};
Fraction operator + (Fraction f, Fraction s){
    return Fraction(f.getNumerator() * s.getDenominator() + f.getDenominator()*s.getNumerator(),f.getDenominator()*s.getDenominator());
}
Fraction operator - (Fraction f, Fraction s){
    return Fraction(f.getNumerator() * s.getDenominator() - f.getDenominator()*s.getNumerator(),f.getDenominator()*s.getDenominator());
}
Fraction operator * (Fraction f, Fraction s){
    return Fraction(f.getNumerator() * s.getNumerator(), f.getDenominator() * s.getDenominator());
}
Fraction operator / (Fraction f, Fraction s){
 if (s.getNumerator() == 0){
    throw FractionExeption("Denominator cannot be zero ");
 }
 return Fraction(f.getNumerator() * s.getDenominator(), f.getDenominator() * s.getNumerator());
}

bool operator > (Fraction f, Fraction s){
    return (f.getNumerator() * s.getDenominator() > f.getDenominator()*s.getNumerator());
}
bool operator < (Fraction f, Fraction s){
    return (f.getNumerator() * s.getDenominator() < f.getDenominator()*s.getNumerator());
}
bool operator == (Fraction f, Fraction s){
    return (f.getNumerator() * s.getDenominator() == f.getDenominator()*s.getNumerator());
}
bool operator != (Fraction f, Fraction s){
    return !(f==s);
}

int main()
{
    Fraction f = Fraction(4,2);
    Fraction s = Fraction(2,3);
    cout << (f*s).getDecimal();
    cout << endl;
}
