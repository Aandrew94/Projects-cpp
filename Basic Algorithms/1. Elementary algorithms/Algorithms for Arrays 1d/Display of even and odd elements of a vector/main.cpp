/*
Display of even / odd elements of a vector
*/

#include    <iostream>
#include   <algorithm>

void check(int &nr);

int main(){

    int array[5] = {-2,4,3,2,1};
    int count_par{};
    int count_imp{};

    //std::cout<< "5st:\t" << *(array+std::size(array)-1) <<std::endl;
    //std::cout<< "Size of array:\t" << std::size(array) << '\n';
    //std::cout<< "Total size of array:\t" << sizeof(array) << '\n';

    for (size_t i=0; i< std::size(array); i++){
        if (array[i] % 2 == 0){
            std::cout<< "Element par:\t" << array[i]<<'\n';
            count_par++;
        }
        else{
            std::cout<< "Element impar:\t" <<array[i]<<'\n';
            count_imp++;
        }
    }

    std::cout<< "Avem "<< count_par << " elemente pare\n";
    std::cout<< "Avem "<< count_imp << " elemente impare\n";
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
