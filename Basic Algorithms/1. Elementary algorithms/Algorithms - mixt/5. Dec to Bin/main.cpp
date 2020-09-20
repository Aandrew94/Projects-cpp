#include        <iostream>

int main(){

    int number{};

    std::cout<< "Get number:\t";
    std::cin >>number;

//  dynamic -> from heap; *a on stack
//  int *a = new int[number];   

    int a[number];
    int i{};
    for(i=0;number > 0;i++){
        a[i] = number % 2;
        number /= 2;
    }

    for(i=i-1;i>=0;i--){
        std::cout << a[i] << " ";
    }

    return 0;
}





