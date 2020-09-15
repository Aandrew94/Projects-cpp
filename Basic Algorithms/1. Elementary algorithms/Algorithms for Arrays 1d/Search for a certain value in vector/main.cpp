/*

Search for a certain value inside a vector.

*/



#include    <iostream>

void check(int &nr);

int main(){

    int array[5] = {-2,2,3,1,5};
    int search;
    check(search);


    for(int i=0; i < 100; i++){
        if (search == array[i]){
            std::cout<<"Am gasit:\t"<<array[i]<<'\n';
            break;
        }
        else continue;
        
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
