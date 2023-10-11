#include <iostream>

int implicit(char x){	
	return x;

}



int main() {
   	char x{}; 
	std::cout << "Enter a single character: ";
	std::cin >> x;
	std::cout << "you entered ascii char " << implicit(x) << "\n";
	
	
	
	return 0;
}







