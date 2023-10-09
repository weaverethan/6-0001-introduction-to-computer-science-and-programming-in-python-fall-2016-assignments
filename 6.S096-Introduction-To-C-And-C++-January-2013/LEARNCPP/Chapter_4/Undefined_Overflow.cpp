#include <iostream>

int main()
{
    // assume 4 byte integers
    int x { 2'147'483'647 }; // the maximum value of a 4-byte signed integer
    std::cout << x << '\n';

    ++x; // integer overflow, undefined behavior
    std::cout << x << '\n';

    return 0;
}
