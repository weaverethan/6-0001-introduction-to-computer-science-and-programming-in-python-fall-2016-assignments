#include <iostream>



struct Fraction{
	int numerator{};
	int denominator{};
};


Fraction getFraction(){
	Fraction input{};
	std::cout << "Enter the numerator:";
	std::cin >> input.numerator;
	std::cout << "Enter the denominator:";
	std::cin >> input.denominator;
	return input;
}


Fraction multiplyFraction(const Fraction& a,const Fraction& b){
	return {a.numerator*b.numerator, a.denominator*b.denominator};
}

void printFraction(const Fraction& x){
	std::cout << x.numerator << "/" << x.denominator;
}


int main(){
	Fraction first{getFraction()};
	Fraction second{getFraction()};
	std::cout << "Your Fractions Multiplied Together: ";
       	printFraction(multiplyFraction(first, second));
	std::cout << "\n";

	return 0;
}
