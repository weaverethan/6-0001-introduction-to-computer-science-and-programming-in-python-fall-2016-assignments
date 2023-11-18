#include <iostream>


enum class Animal{
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,
};



std::string_view getAnimalName(Animal animal){
	using enum Animal;
	switch(animal){
		case pig: return "pig";
		case chicken: return "chicken";
		case goat: return "goat";
		case cat: return "cat";
		case dog: return "dog";
		case duck: return "duck";
		default: return "non";
	}
}


int NumberOfLegs(Animal animal){
	using enum Animal;
	switch(animal){
		case pig: return 4;
		case chicken: return 2;
		case goat: return 4;
		case cat: return 4;
		case dog: return 4;
		case duck: return 2;
		default: return 0;
	}	
}

int main(){
	
	Animal first{Animal::cat};
	std::cout << "A " << getAnimalName(first) << " has " << NumberOfLegs(first) << " legs\n"; 
	Animal second{Animal::chicken};
	std::cout << "A " << getAnimalName(second) << " has " << NumberOfLegs(second) << " legs\n"; 
	
	
	return 0;
}
