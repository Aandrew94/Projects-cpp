/*
Eliminarea unui element, din index dintr-un vector
*/

#include    <iostream>
#include   <algorithm>

void check(int &nr);

int main(){

    int array[5] = {-2,4,3,2,1};
    int element{};
    check(element);
    
    bool flag;
    //std::cout<< "5st:\t" << *(array+std::size(array)-1) <<std::endl;
    //std::cout<< "Size of array:\t" << std::size(array) << '\n';
    //std::cout<< "Total size of array:\t" << sizeof(array) << '\n';

    for( size_t i = 0; i < std::size(array); i++){
        if (array[i] == element){
            flag = true;
        }
    }

    for ( int i = element; i <= std::size(array)-1; i++){
        array[i] = array[i+1];
    }


//  Print the vector
    for(size_t i=0; i <std::size(array)-1; i++){
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
