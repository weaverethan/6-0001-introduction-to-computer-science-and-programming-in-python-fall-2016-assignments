#include <iostream>


int fractal(int x){
	int total{0};
	for (int i{1}; i<=x; ++i){
		total += i;
	}
	return total;
}




int main(){
	std::cout << fractal(5) << "\n";


	return 0;
}
