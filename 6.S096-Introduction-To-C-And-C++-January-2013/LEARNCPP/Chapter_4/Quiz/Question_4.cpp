#include <iostream>
#include <string>


float GRAVITY{9.8};



double distFallen(int seconds){	
	return GRAVITY*seconds*seconds/2;
}

void dispFall(int seconds, int height){
	if (distFallen(seconds)<=height){
		std::cout << "At " << seconds << " seconds, the ball is at height: " << height - distFallen(seconds) << " meters\n";		
	} else {
		std::cout << "At " << seconds << " the ball is on the ground.\n";
	}
}
	

int main(){
	std::cout << "Enter the height of the tower in meters:";
	int height{};
	std::cin >> height;

	dispFall(0, height);	
	dispFall(1, height);	
	dispFall(2, height);	
	dispFall(3, height);	
	dispFall(4, height);	
	dispFall(5, height);	
	
	return 0;
}
