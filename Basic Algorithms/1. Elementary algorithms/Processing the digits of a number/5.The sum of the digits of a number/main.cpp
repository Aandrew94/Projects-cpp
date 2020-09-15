/*
RO:     Se citeste un numar n de la tastatura. Determinati suma cifrelor acestuia.
ENG:    Read one number n from keyboard, calculate the sum of digits of the number.
*/


#include       <iostream>


void check(int &nr);

int main(){

    int number{};
    int sum{};
    check(number);
    while(number != 0){
        sum = sum + number % 10;
        number /= 10;
    }

    std::cout<< "sum:\t"<<sum<<'\n';
    

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