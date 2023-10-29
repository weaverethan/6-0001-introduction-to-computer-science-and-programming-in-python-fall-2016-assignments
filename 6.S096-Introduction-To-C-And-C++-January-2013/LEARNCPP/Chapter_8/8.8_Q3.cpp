#include <iostream>

int main()
{
    
    int outer{ 5 };
    while (outer >= 1)
    {
        

        
        int inner{ 1 };
        while (inner <= outer)
        {
            std::cout << inner << ' ';
            ++inner;
        }

        
        std::cout << '\n';
        --outer;
    }

    return 0;
}
