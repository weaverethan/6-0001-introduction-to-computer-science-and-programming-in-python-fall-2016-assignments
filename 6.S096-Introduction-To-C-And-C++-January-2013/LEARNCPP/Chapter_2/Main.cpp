#include <iostream>



int ReadNumber(){
    int number = {0};
    std::cout << "ENTER A NUMBER:";
    std::cin >> number;
    return number;
}



void WriteAnswer(int num1,int num2){
    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
}





int main(){
    WriteAnswer(ReadNumber(), ReadNumber());
    return 0;
}