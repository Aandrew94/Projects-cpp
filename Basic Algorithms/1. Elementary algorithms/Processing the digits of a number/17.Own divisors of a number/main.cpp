/*
RO:     Se citeste de la tastatura un numar n. Determinati si afisati divizorii proprii ai acestuia in caz ca exista.
ENG:    A number n is read from the keyboard. Determine and display its own divisors in case they exist.

Un numar n poate avea divizori proprii si improprii.
->  Divizorii improprii ai unui numar sunt 1 si numarul insusi.
->  Divizorii proprii sunt restul numerelor care divid pe n, cuprinse intre [n, n/2]. 
*/


#include       <iostream>
#include        <math.h>


void check(int &nr);


int main(){

    int number{};
    check(number);
    int div{};              //  determina divizorii proprii
    int count_div{};        //  numara divizorii propii a lui 'number

    //for (d=2; d <= number/2; d++){
    //for(d=2; d <= sqrt(number); d++){
    for(div=2; div < number/2; div++){    
        if (number % div == 0){
            std::cout<< "Divizorii proprii ai lui sunt: " << div <<'\n';
            count_div++;
        }

    }

    if (count_div == 0){
        std::cout << number << " is prime\n";
    }
    else{
        std::cout << number << " is not prime\n";
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
