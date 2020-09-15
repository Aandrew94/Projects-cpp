/*
METHOD_1:    Sorting a vector by interchange

Additional names: Selection sort
Additional names: Bubble sort


METHOD_2:   Sorting a vector by using sort() fct from <algorithm>
*/



#include    <iostream>
#include   <algorithm>



void check(int &nr);

int main(){

    int array[5] = {-2,2,3,2,1};
    int max = *array;
    std::cout<< "1st:\t" << max <<std::endl;
    std::cout<< "5st:\t" << *(array+std::size(array)-1) <<std::endl;
    std::cout<< "Size of array:\t" << std::size(array) << '\n';
    std::cout<< "Total size of array:\t" << sizeof(array) << '\n';

//  Method_1
    for(size_t i=0; i < std::size(array)-1; i++){
        for(size_t j = i+1; j < std::size(array); j++){

            if (array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }           
    }


//  Method_2
    std::sort(array,array+std::size(array));

    for(size_t i=0; i <std::size(array); i++){
        std::cout << "Pozitie: " << i << " -> " << array[i] <<'\n';
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
