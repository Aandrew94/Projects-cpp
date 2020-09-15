/*
RO:     Se citeste un numar n de la tastatura. Determinati si afisati media aritmetica a cifrelor acestuia.
ENG:    Read one number n from keyboard, calculate arithmetic mean of digits of the number.
*/

#include       <iostream>


void check(int &nr);

int main(){

    int number{};
    int sum{};
    int count{};
    check(number);

    while(number != 0){
        sum += number % 10;
        number /= 10;
        count++;
    }
    std::cout<< "sum:\t"<<sum<<'\n';
    std::cout<< "count:\t"<< count <<'\n';
    std::cout<< "med:\t"<<static_cast<float>(sum)/count<<'\n';
    std::cout<< "med:\t"<<double(sum)/count<<'\n';
    

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