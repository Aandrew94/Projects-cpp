/*
RO:     Se citeste de la tastatura un numar n. Determinati si afisati divizorii proprii ai acestuia in caz ca exista.
ENG:    A number n is read from the keyboard. Determine if the number is a perfect square.


In matematica, un patrat perfect este un numar intreg (Z) care este patratul altui numar intreg. 

Exemplu: 4 este patrat perfect, deoarece poate fi scris ca si 2 * 2.
De exemplu, daca scriem sqrt(5), partea intreaga a radacinii este 2. Iar 2 nu este egal cu 2.23607 (radacina reala). 

In schimb, daca scriem sqrt(4), partea intreaga (2) este egala cu partea reala (2).
*/



#include    <iostream>
#include    <math.h>

void check(int &nr);

int main(){

    int number{};
    check(number);

    if ( sqrt(number) == static_cast<float>(sqrt(number))){
        std::cout<< "numarul: "<< number << " este patrat perfect\n";
    }
    else{
        std::cout<< "nu este\n";
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
