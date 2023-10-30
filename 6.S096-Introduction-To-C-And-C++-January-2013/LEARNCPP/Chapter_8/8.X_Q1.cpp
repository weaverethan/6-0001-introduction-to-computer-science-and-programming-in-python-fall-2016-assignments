#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void calculateAndPrintHeight(double initialHeight, int time)
{
    std::cout << "At " << time << " seconds, the ball is at height: " << calculateHeight(initialHeight, time) << '\n';
}

int main()
{
	std::cout << "Enter the initial height of the tower in meters: ";
	double initialHeight {};
	std::cin >> initialHeight;

	int x{0};
	while (calculateHeight(initialHeight, x) != 0.0){
		calculateAndPrintHeight(initialHeight, x);
		++x;
	}
	calculateAndPrintHeight(initialHeight, x);
	return 0;
}
