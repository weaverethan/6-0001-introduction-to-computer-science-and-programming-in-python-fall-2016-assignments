#include <iostream>

int numberinput(){
	int value{};
	std::cout << "Enter a Number:";
	std::cin >> value;
	return value;
}


int getoperandcalculate(int first, int second){
	char oper{};
	std::cout << "enter an operator /,*,+,-,%:";
	std::cin >> oper;
	switch(oper){
		case '-':
			return first - second;
		case '+':
			return first + second;
		case '/':
			return first/second;
		case '*':
			return first*second;
		case '%':
			return first%second;	
		default:
			std::cout << "Not a Valid Operator!\n";
			return 0;
	}
}

int main(){
	int first{numberinput()};
	int second{numberinput()};	
	int ans{getoperandcalculate(first, second)};
	
	std::cout << "The Answer is " << ans << "\n";
	

	return 0;
}
