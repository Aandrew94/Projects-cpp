/*
RO:     Se citeste un numar n de la tastatura. Determinati daca numarul citit este prim si afisati un mesaj corespunzator.
ENG:    Read one number n from keyboard. Check if the number is prime or not.

Un numar este prim daca are doar divizori improprii. (daca este divizibil doar cu 1 si cu el insusi).
A number is prime if it has only improper divisors. (if it is divisible only by 1 and by itself).

Ex of prime numbers: 3, 11, 7, 51 etc.
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
    for(div=2; div < number; div++){    
        if (number % div == 0){
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


/*  Algoritmul pentru verificare unui numar prim recursiv

    bool ePrimRecursiv(int div, int n){ 
        if(n == 2) 
            return true; 

        if(n % div == 0 || n == 1) 
            return false; 

        if(div * div > n) 
            return true; 

        if(div == 2) 
            return ePrimRecursiv(3, n); 

        return ePrimRecursiv(div + 2, n); 
    }   
    
*/






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
