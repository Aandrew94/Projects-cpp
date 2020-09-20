

#include    <iostream>
#include    <math.h>

int main(){

    int number{};
    int tempNumber{};
    int powerOrder{};
    int lastDigit{},sum{};

    std::cout<< "Get number:\t" << '\n';
    std::cin >> number;

    tempNumber = number;

    while(tempNumber > 0){
        powerOrder++;
        tempNumber /= 10;
    }
    std::cout<< "powerOrder:\t" << powerOrder << '\n';

    tempNumber = number;

    while(number > 0){
        lastDigit = number % 10;
        sum = sum + pow(lastDigit,powerOrder);
        number = number / 10;
    }

    if (tempNumber == sum){
        std::cout << "Armstrong number\n";
    }
    else std::cout << "Not Armstrong number\n";

    return 0;
}