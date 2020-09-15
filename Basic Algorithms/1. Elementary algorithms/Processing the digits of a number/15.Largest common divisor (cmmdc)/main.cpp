/*
RO:     Se citesc de la tastatura doua numere a si b. Determinati si afisati pe ecran cel mai mare divizor comun al acestora.
ENG:    Two numbers a and b are read from the keyboard. Determine and display on the screen their largest common divisor.

Metode:
- scaderi repetate      <>  Algoritmul lui Euclid
- impartiri repetate    <>  Algoritmul lui Euclid
- recursiv (bazata pe impartiri)

*/


#include       <iostream>


void check(int &nr);
int    cmmdcDif(int &A, int &B);
int    cmmdcRat(int &A, int &B);
int    cmmdcRec(int &A, int B);

int main(){

   int a{};
   int b{};

   check(a);
   check(b);

//  se determina cel mai mic divizor comun prin scaderi repetate


//se afiseaza a (care memoreaza acum cmmdc-ul dintre cele 2 numere)
    std::cout<<"Cmmdc = " << cmmdcRec(a,b) << '\n' ;


    

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


//  scaderi repetate
int    cmmdDif(int &A, int &B)
{
    while (A != B){
        if (A > B){
            A = A - B;
        }
        else{
            B = B - A;
        }
    }

    return A;
}

//  impartiri repetate
int    cmmdcRat(int &A, int &B)
{
    int r;
    while (B > 0){
        r = A % B;
        A = B;
        B = r;
    }

    return A;
    
}


//  recursiv - impartit
int    cmmdcRec(int &A, int B)
{
    if  (!B){
        return A;
    }
    else{
        return cmmdcRec(B , A%B);
    }
}