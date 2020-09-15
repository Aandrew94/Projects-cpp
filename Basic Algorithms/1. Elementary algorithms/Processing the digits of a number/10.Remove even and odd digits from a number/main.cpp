/*
RO:     Se citeste un numar n de la tastatura. Eliminati cifrele pare/impare ale acestuia si afisati numarul astfel obtinut.
ENG:    Read one number n from keyboard. Remove the even/odd digits and print the number.
*/

#include       <iostream>


void check(int &nr);

int main(){

    int number{};
    int numar_cifre_pare{};
    int numar_cifre_impare{};
    int power_imp{1};
    int power_par{1};
    check(number);

    while(number != 0){

        if ( (number % 10) % 2 != 0){
            numar_cifre_impare += (number % 10)*power_imp;
            power_imp *= 10;
        }
        else{
            numar_cifre_pare += (number % 10)*power_par;
            power_par *= 10;
        }

        number /= 10;

    }

    std::cout<< "numar_cifre_impare:\t" << numar_cifre_impare << '\n';
    std::cout<< "numar_cifre_pare:\t" << numar_cifre_pare << '\n';

    

    return 0;
}

void check(int &nr){
//  sent the parameter through reference(&) because it is 
//  possible to modify it and it does not make a coppy of it
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