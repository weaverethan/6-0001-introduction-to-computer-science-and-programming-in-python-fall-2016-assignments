#include <iostream>
#include <string>


double  getDouble(){
	std::cout << "Enter a Double:";
	double input{};
	std::cin >> input;
	return input;
	
}

char getOperator(){
	std::cout << "/ , * , + , -\n";
	std::cout << "Enter an Operator:";
	char input{};
	std::cin >> input;
	return input;
}



int main(){
	
	double first{getDouble()};
	double second{getDouble()};
	char operation{getOperator()};
	
	if (operation == '*'){
		std::cout << first << " " << operation << " " << second << " = " << first*second << "\n";
	} else if (operation == '/'){
		std::cout << first << " " << operation << " " << second << " = " << first/second << "\n";
	} else if (operation == '+'){
		std::cout << first << " " << operation << " " << second << " = " << first+second << "\n";
	} else if (operation == '-'){
		std::cout << first << " " << operation << " " << second << " = " << first-second << "\n";
	} else {
		std::cout << "not valid operator\n";
	}
	return 0;
}
