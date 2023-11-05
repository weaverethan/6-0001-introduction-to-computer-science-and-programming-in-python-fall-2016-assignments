#include <iostream>


template <typename T>
T add(T x, T y) 
{
    return y + x;
}

// write your add function template here

int main()
{
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

	return 0;
}
