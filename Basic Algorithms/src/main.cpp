#include    <iostream>
//using namespace std;
int main(){


    int i,j;

    int number{};
    std::cout<< "get limit:\t";
    std::cin >> number;

    for(i = 0; i < number; i++){
        for(j=0;j<number - i;j++){
            std::cout<< " ";
        }

        for(int k = 0; k < i; k++){
            std::cout<<k;
        }

        for(int l=i-1;l>=1;l--){
            std::cout<<l;
        }
        std::cout<<'\n';
    }


    return 0;
}