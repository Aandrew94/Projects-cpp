#include    <iostream>

int main(){

    int number{};
    int lastDigit{};
    int sum{};

    std::cout<< "Get number:\t";
    std::cin >> number;

//  reverse the number
    while(number > 0){
        lastDigit = number % 10;
        sum = sum*10 + lastDigit;
        number /= 10;
    }



    while(sum >0){
        lastDigit = sum % 10;
        switch (lastDigit){
            case 9:
                std::cout<< "nine ";    break;
            case 8:
                std::cout<< "eight ";    break;                
            case 7:
                std::cout<< "seven ";    break;        
            case 6:
                std::cout<< "six ";    break;                
            case 5:
                std::cout<< "five ";    break; 
            case 4:
                std::cout<< "four ";    break;                
            case 3:
                std::cout<< "three ";    break;        
            case 2:
                std::cout<< "two ";    break;                
            case 1:
                std::cout<< "one ";    break;   
            case 0:
                std::cout<< "zero ";    break;                                                
        default:
                std::cout<< "X_X "; break;
        }
        
        sum /= 10;
    }
    return 0;
}