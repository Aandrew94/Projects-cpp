/*

RO:     Se citeste de la tastatura un numar n. Determinati si afisati pe ecran descompunerea in factori primi ai acestuia.
ENG:    A number n is read from the keyboard. Determine and display on the screen its prime factorization.


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
    int div{2};              //  determina divizorii proprii
    int power{};

    while(number > 1){
// initial 0 pentru a afla puterea la care apare factorul prim
        power = 0;

        while(number % div == 0){
            power++;                //contorizeaza puterea
            number /= div;      // imparte pt a putea continua impartirea si identificarea puterii
        }
//daca numarul div se imparte macar o data la number se afiseaza div
// , alaturi de puterea la care apare in descompunere
        if( power > 0){
            std::cout << div << '^' << power << ' ';
        }
        div = div + 1;
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
