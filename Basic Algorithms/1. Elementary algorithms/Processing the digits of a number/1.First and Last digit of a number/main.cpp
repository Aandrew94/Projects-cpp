/*
RO:     Se citeste un numar n de la tastatura, afisati prima cifra a acestuia.
ENG:    Read one number n from keyboard, show the first digit of the number
*/


#include       <iostream>


void check(int &nr);

int main(){

    int number{};
    check(number);

    while(number > 9){
        number /= 10;
    }
    std::cout<< "First digit is:\t"<< number << '\n';
    

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