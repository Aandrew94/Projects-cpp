/*
Definitia unui an bisect: Un an bisect este un an care are 366 zile (in loc de 365).

Exemplu: 2000, 2004, 2400 – sunt ani bisecti. 
Dar 1800, 1900, 2200, 2300 si 2500 sunt ani normali.

*/



#include    <iostream>

void check(int &nr);

int main(){

    int year{};
    check(year);

    if( ((year % 4 == 0) && (year % 100 != 0 )) || (year % 400 == 0) ){
        std::cout<< "Anul: " << year << " este bisect\n";
    }  
    else
    {
        std::cout<< "Anul: " << year << " nu este bisect\n";
    }





    std::cout << "Hey:)\n"; 

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
