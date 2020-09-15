/*

    Occurrences of an element in a vector

*/



#include    <iostream>

void check(int &nr);

int main(){

    int array[5] = {-2,2,3,2,5};
    int search;
    check(search);
    int count{};


    for(int i=0; i < 100; i++){
        if (search == array[i]){
            //std::cout<<"Am gasit:\t"<<array[i];
            count++;
        }
        
    }
    std::cout<<"Gasit de  " << count <<" ori"<<'\n';




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
