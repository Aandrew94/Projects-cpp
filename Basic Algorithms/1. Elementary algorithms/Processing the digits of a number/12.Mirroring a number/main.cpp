/*
RO:     Se citeste un numar n de la tastatura. Determinati si afisati oglinditul/inversul acestuia.
ENG:    Read one number n from keyboard. Print the mirror/inverse of the number.
*/

#include       <iostream>


void check(int &nr);

int main(){

    int number{};
    int inv{};
    check(number);

    while(number != 0){
        inv = inv*10 + number%10;
        number /= 10;
    }
    
    std::cout<< "number:\t" << number << '\n';
    std::cout<< "inv:\t" << inv << '\n';

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