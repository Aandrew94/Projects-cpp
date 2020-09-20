#include    <iostream>


int factorial (const int &value);

int main(void) {  

//  Factorial Program using loop  
    
    int number{};
    int fact{1};
    std::cout<< "Get number:\t";
    std::cin >> number;


    std::cout<< "!" << number << " = ";
    for (int i=1; i<=number;i++){
        fact = fact * i;
    }

    std::cout<< fact <<"\n\n";

//  Factorial Program using recursion    
    int result{};
    result = factorial(number);
    std::cout<< "Factorial is:\t" << result << std::endl;

return 0;  
}  


int factorial(const int &value)
{
    if (value < 0)
        return -1;      //  Wrong value
    else if (value == 0){
        return 1;       //  Finish condition
    }
    else{
        return value*(factorial(value-1));
    }
}