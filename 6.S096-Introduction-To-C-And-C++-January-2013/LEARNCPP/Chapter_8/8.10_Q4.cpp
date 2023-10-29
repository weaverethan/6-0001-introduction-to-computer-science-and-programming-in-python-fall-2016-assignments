#include <iostream>

void fizzbuzz(int x){

	for (int i{1}; i<=x; ++i){
		bool diz{false};
		if (i%3 == 0){
			std::cout << "fizz";
			diz = true;
		}
		if (i%5 == 0){
			std::cout << "buzz";
			diz = true;
		}
		if (i%7 == 0){
			std::cout << "pop";
			diz = true;
		}
		if (!diz){
			std::cout << i << "\n";
		} else {
			std::cout << "\n";
		}
	}

}



int main(){

	fizzbuzz(150);
	return 0;
}
