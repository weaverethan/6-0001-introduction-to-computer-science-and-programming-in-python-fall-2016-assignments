#include <iostream>



int main(){
	
	int letter{97};
	while (letter<(97+26)){
		std::cout << static_cast<char>(letter);
		letter++;
	}	
	std::cout << "\n";


	return 0;
}
