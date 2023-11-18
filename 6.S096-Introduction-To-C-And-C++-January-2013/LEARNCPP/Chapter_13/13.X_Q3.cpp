#include <iostream>


template <typename T>
struct Triad{
	T one{};
	T two{};
	T three{};
};


template <typename T>
void print(Triad<T> triad){
	std::cout << "[" << triad.one << ", ";
	std::cout << triad.two << ", ";
	std::cout << triad.three << "]\n";
}






int main()
{
	Triad t1{ 1, 2, 3 }; // note: uses CTAD to deduce template arguments
	print(t1);

	Triad t2{ 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
	print(t2);

	return 0;
}
