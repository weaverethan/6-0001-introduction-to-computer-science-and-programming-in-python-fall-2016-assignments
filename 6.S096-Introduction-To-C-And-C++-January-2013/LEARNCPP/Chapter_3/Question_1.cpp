#include <iostream>

int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int main()
{
	int x {};
	int y {};
	y = readNumber(x);
	x = readNumber(x);
	writeAnswer(x+y);

	return 0;
}



