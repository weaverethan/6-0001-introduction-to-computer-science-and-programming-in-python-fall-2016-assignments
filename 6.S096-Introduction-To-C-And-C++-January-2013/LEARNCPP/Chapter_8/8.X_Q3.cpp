#include <iostream>
#include <random>




int getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}


int getGuess(){
	static int guessnum{1};
	int guess{};
	std::cout << "Guess #" << guessnum << ":";
	std::cin >> guess;
	++guessnum;
	return guess;

}

		
int main(){
	
	int secret_number{getRandomNumber(1, 100)};	
	std::cout << "Let's play a game. I'm thinking of a number between 1 and 100.\n";
	std::cout << "You have 7 tries to guess what it is.\n";
	
	for (int i{1}; i<=7; ++i){
		if (getGuess() == secret_number){
			std::cout << "Correct! You win!\n";
			return 0;
		} 

	}	

	std::cout << "no more guess's you loose\n";


	return 0;
}
