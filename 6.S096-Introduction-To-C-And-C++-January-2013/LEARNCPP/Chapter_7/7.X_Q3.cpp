#include <iostream>


int accumulate(int x){
	static int total{};
	total = total + x;
	return total;

}




int main()
{
    std::cout << accumulate(4) << '\n'; 
    std::cout << accumulate(3) << '\n'; 
    std::cout << accumulate(2) << '\n'; 
    std::cout << accumulate(1) << '\n'; 

    return 0;
}
