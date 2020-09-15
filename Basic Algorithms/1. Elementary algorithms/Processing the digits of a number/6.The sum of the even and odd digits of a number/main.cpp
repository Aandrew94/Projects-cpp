/*
RO:     Se citeste un numar n de la tastatura. Determinati suma cifrelor pare si suma celor impare ale acestuia.
ENG:    Read one number n from keyboard, calculate the sum of odd and even digits of the number.
*/


#include       <iostream>


void check(int &nr);

int main(){

    int number{};
    int sum_par{};
    int sum_imp{};
    check(number);
    while(number != 0){
        if ((number % 10) % 2 == 0){
            sum_par += (number % 10);
        }
        else if ((number % 10) % 2 != 0){
            sum_imp += (number % 10);
        }
        number /= 10;
    }

    std::cout<< "sum_par:\t"<<sum_par<<'\n';
    std::cout<< "sum_imp:\t"<<sum_imp<<'\n';
    

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