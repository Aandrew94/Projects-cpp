#include    <iostream>


int main(){

    int a = 3;
    int b = 20;

    std::cout<< "Before swap: a = " << a << ", b = " << b << '\n';

    a = a + b;
    b = a - b;
    a = a - b;

    std::cout<< "After swap: a = " << a << ", b = " << b << '\n';


    int x = 5;
    int y = 10;


    std::cout<< "Before swap: x = " << x << ", y = " << y << '\n';

    x = x * y;
    y = x / y;
    x = x / y;

    std::cout<< "After swap: x = " << x << ", y = " << y << '\n';

    return 0;
}