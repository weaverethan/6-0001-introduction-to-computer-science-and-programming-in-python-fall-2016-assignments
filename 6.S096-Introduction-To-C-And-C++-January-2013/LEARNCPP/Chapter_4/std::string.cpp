#include <iostream>
#include <string>

int main(){

	std::cout << "enter your full name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	std::cout << "enter your age: ";
	int age{};
	std::cin >> age;
	std::cout << "Your name is " << name << " and you age is " << age << "\n";
	int namelen { static_cast<int>(name.length()) };	
	std::cout << "Your age + length of name is: " << namelen + age;






}



















