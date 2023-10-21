#include <bitset>
#include <iostream>

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
	if (bits.test(3)){
		bits <<= 1;
		return bits.flip(0);
	}
	return bits <<= 1;
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << bits1 << '\n';
	std::cout << rotl(bits1) << '\n';
	
	std::bitset<4> bits2{ 0b1001 };
	std::cout << bits2 << '\n';
	std::cout << rotl(bits2) << '\n';

	return 0;
}
