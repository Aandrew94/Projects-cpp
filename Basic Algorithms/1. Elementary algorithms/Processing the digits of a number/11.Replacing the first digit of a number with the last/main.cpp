/*
RO:     Se citeste un numar n de la tastatura. Determinati si afisati numarul format prin inlocuirea primei cifre a numarului cu ultima cifra a sa.
ENG:    Read one number n from keyboard. Replace the first digit of the number with the last digit.
*/


#include       <iostream>


void check(int &nr);

int main(){

    int number{};
    int init_number{};
    int lastDigit{};
    int new_number{};
    check(number);


    lastDigit = number % 10;    //  save last digit
    init_number = number;       //  save original number;
    int p{1};                   //  init the power of 10

    while( number > 9 ){

        p *= 10;                //  increase the power
        number /= 10;           //  remove the last digit

    }

/*  lastDigit * p       ->  last digit take the first position  +
    init_number % p     ->  add the rest of digits to the new number
    /10)*10             ->  remove the last digit to replace it with the first
    +number             ->  first digit become the first beeing memorated in number;

*/
    new_number = ((lastDigit * p + init_number % p)/10)*10+number;
    std::cout<< "result:\t" << new_number<<'\n';

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