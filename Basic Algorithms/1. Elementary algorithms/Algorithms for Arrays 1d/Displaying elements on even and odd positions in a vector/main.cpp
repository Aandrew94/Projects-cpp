/*
Displaying elements on even and odd positions in a vector
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
        if (i % 2 == 0){
            std::cout<< "i="<< i <<"-Pozitie para,element:\t" << array[i]<<'\n';
            count_par++;
        }
        else{
            std::cout<< "i="<< i <<"-Pozitie impara,element:\t" << array[i]<<'\n';
            count_imp++;
        }
    }

    std::cout<< "Avem "<< count_par << " pozitii pare\n";
    std::cout<< "Avem "<< count_imp << " pozitii impare\n";
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
