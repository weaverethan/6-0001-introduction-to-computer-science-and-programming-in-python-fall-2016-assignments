#include <iostream>
#include <random>




int getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}


int getUserGuess() {
    static int guessNum{1};
    int userGuess;
    bool isValid = false;

    while (!isValid) {
        std::cout << "Guess #" << guessNum << ":";
        if (std::cin >> userGuess) {
            if (userGuess >= 1 && userGuess <= 100) {
                // Check if the input is an integer (no fractional part)
                if (std::cin.peek() == '\n') {
                    isValid = true;
                } else {
                    std::cout << "Please enter an integer, not a floating-point number." << std::endl;
                    std::cin.clear();  // Clear error flags
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
                }
            } else {
                std::cout << "Please enter a number between 1 and 100." << std::endl;
                std::cin.clear();  // Clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            }
        } else {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();  // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
        }
    }
    ++guessNum;
    return userGuess;
}




int main(){
	
	int secret_number{getRandomNumber(1, 100)};	
	std::cout << "Let's play a game. I'm thinking of a number between 1 and 100.\n";
	std::cout << "You have 7 tries to guess what it is.\n";
	
	for (int i{1}; i<=7; ++i){
		int guess{getUserGuess()};
		if (guess == secret_number){
			std::cout << "Correct! You win!\n";
			return 0;
		} else {
			std::cout << "Nope\n";
		} 

	}	

	std::cout << "no more guess's you loose\n";
	std::cout << "the number was " << secret_number << "\n";

	return 0;
}
