/*
RO:     Se citesc de la tastatura doua numere a si b. Determinati si afisati cel mai mic multiplu comun al acestora.
ENG:    Read from the keyboard two numbers a and b. Determine and display their least common multiple.

Basic formula: cmmmc = (a*b)/cmmdc
*/


#include       <iostream>


void check(int &nr);


int main(){

   int a{}; int x{};
   int b{}; int y{};

   check(a);
   check(b);

    x = a;
    y = b;

    while (a != b){
        if (a > b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }

    std::cout<< "cmmdc:\t" << a << '\n';
    std::cout<< "cmmmc:\t" << (x*y)/a << '\n';

    
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