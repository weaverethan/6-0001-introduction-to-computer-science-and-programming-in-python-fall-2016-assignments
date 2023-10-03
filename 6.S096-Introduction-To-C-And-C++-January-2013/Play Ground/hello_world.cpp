#include <iostream>
#include <vector>

int main() {
    // Initialize a vector with elements using initializer list and print them using a range-based for loop
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Numbers: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Use the spaceship operator (<=>) for three-way comparison
    int a = 10;
    int b = 5;
    auto result = a <=> b;

    std::cout << "Comparison result: ";
    if (result > 0) {
        std::cout << "a is greater than b";
    } else if (result < 0) {
        std::cout << "a is less than b";
    } else {
        std::cout << "a is equal to b";
    }
    std::cout << std::endl;

    return 0;
}