#include <iostream>

int main()
{
	std::cout << "ENTER A NUMBER:";

	int input{};
	std::cin >> input;

	std::cout << "DOUBLE " << input <<" is: " << input *2  << '\n';
	std::cout << "TRIPLE " << input <<" is: " << input *3  << '\n';

	
	
	return 0;
}