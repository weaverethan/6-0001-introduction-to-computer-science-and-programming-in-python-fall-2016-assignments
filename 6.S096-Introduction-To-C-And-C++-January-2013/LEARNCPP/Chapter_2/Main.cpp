#include <iostream>


int ReadNumber();

void WriteAnswer(int num1, int num2);



int main(){
    WriteAnswer(ReadNumber(), ReadNumber());
    return 0;
}
