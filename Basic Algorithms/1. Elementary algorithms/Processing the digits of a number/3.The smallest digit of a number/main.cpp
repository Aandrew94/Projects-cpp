/*
RO:     Se citeste un numar n de la tastatura, afisati cea mai mica cifra a unui numar.
ENG:    Read one number n from keyboard, print the smallest digit of the number.
*/


#include       <iostream>


void check(int &nr);

int main(){

    int number{};
    int min{};
    check(number);
    
//  set a min value - last digit
    min = number % 10;

    while (number != 0){
//  if last digit < our max value -> min will be updated
        if (number % 10 < min){
            min = number % 10;
        }
//  if this is not the case -> remove the last digit from the number
        number /= 10;

    }
    std::cout<< "Smallest digit:\t"<<min<<'\n';

    return 0;
}


void check(int &nr){

    while(1){
        std::cout<< "Get number:\t";
        std::cin >> nr;

        if ( nr < 0 || !nr ){
            std::cerr<< "[ERROR]\t Positive numbers only\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else
            break;

    }
    
}