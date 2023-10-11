#include <iostream>





int main() {
   	char x{}; 
	std::cout << "Enter a single character: ";
	std::cin >> x;
	std::cout << "you entered ascii char " << static_cast<int>(x) << "\n";
	
	
	
	return 0;
}







