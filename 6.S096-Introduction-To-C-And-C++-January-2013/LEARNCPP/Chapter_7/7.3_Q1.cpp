#include <iostream>



int main(){

	int smaller{};
	int larger{};

	std::cout << "enter an int:";
	std::cin >> smaller;
	std::cout << "enter a larger int:";
	std::cin >> larger;
	if (smaller > larger)
	{
		int swap{};
		swap = smaller;
		smaller = larger;
		larger = swap;
	}
	std::cout << smaller << " " << larger << "\n"; 


	return 0;
}
