/*
The maximum and minimum of a vector

*/



#include    <iostream>
#include   <algorithm>



void check(int &nr);

int main(){

    int array[5] = {-2,2,3,2,1};
    int max = *array;
    int min = *array;
    std::cout<< "1st:\t" << max <<std::endl;
    std::cout<< "5st:\t" << *(array+std::size(array)-1) <<std::endl;
    std::cout<< "Size of array:\t" << std::size(array) << '\n';
    std::cout<< "Total size of array:\t" << sizeof(array) << '\n';

    for ( size_t i=0; i < std::size(array); i++){
        if (array[i] > max){
            max = array[i];
        }

        if (array [i] < min){
            min = array[i];
        }
    }

    std::cout<< "Max:\t" << max <<'\n';
    std::cout<< "Min:\t" << min <<'\n';


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
