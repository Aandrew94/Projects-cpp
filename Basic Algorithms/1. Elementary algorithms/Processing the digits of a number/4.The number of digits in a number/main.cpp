/*
RO:     Se citeste un numar n de la tastatura. Determinati si afisati cate cifre are numarul.
ENG:    Read one number n from keyboard, find and print how many digits has the number.
*/


#include       <iostream>


void check(int &nr);

int main(){

    int number{};
    int count{};
    check(number);
    while(number != 0){
        number /= 10;
        count++;
    }

    std::cout<< "cifre:\t"<<count<<'\n';
    

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