#include <iostream>

auto mult(auto x, auto y){

	return x*y;
}



int main()
{
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	return 0;
}
