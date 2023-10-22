#include <iostream>
#include <string>

int main(){
	
	std::cout << "Enter an Unsigned Int:";
	int decint{};
	std::string binaryString{};
	std::cin >> decint;
	 
	if (decint  == 0) {
	    binaryString = "0"; // Special case when the input is 0
	} else {
	    while (decint > 0) {
	        int remainder = decint % 2;
	        binaryString = std::to_string(remainder) + binaryString;
	        decint /= 2;
	    }
	}

	std::cout << "Binary representation: " << binaryString << std::endl;




	return 0;
}
