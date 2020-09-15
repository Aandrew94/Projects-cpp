/*
RO:     Se citeste un numar n de la tastatura. Determinati si afisati oglinditul/inversul acestuia.
ENG:    Read one number n from keyboard. Check if the number is a palindrom or not.

Palindrom = numar care scris invers este egal cu el insusi. 
Palindrom = number that written backwards is equal to itself.

Ex of palindrom numbers: 121, 12344321, 100001 etc.
*/

#include       <iostream>


void check(int &nr);

int main(){

    int number{};
    int inv{};
    check(number);
    int init_nr = number;

    while(number!=0){
// make the opposite of number
        inv = inv * 10 + number % 10;
        number /= 10;
    }

    if (init_nr == inv){
        std::cout<< "number = "<< init_nr << "= inv = "<< inv << "-> is palindrom \n";
    }
    else{
        std::cout<< "number = "<< init_nr << "= inv = "<< inv << "-> not palindrom \n";
    }
    

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