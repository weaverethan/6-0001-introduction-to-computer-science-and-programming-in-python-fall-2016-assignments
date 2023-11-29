#include <iostream>

class Fraction {
private:
    int m_numerator{0};
    int m_denominator{1};

public:
    Fraction() = default;
    Fraction(int num, int den) : m_numerator{num}, m_denominator{den} {}

    void print() {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    Fraction multiply(Fraction other) {
        return {m_numerator * other.m_numerator, m_denominator * other.m_denominator};
    }
};

Fraction makeFraction() {
    int numerator{};
    int denominator{};
    std::cout << "Enter a value for numerator: ";
    std::cin >> numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> denominator;
    std::cout << '\n';

    return {numerator, denominator}; // Added a semicolon here
}

int main() {
    Fraction f1{makeFraction()};
    Fraction f2{makeFraction()};

    std::cout << "Your fractions multiplied together: ";

    f1.multiply(f2).print();

    return 0;
}

