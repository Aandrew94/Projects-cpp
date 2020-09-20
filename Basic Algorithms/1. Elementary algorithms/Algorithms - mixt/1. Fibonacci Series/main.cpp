#include    <iostream>


void printFib(const int &n) ;  

int main(void) {  

//  without recursion    
    int n0{0};
    int n1{1};
    int n2{};

    int stop{};
    std::cout<<"Where to stop ?\n";
    std::cin>>stop;

    std::cout<<"Series:\t0, 1, ";
    for (int i = 1; i <= stop; i++){
        n2 = n0 + n1;
        n0 = n1;
        n1 = n2;
        std::cout<< n2 << ", ";
    }

//  recursive fct call
    std::cout<<"\nSeries:\t0, 1, ";
    printFib(stop);

    std::cout<<'\n';

    

return 0;  
}  


void printFib(const int &n)
{
    static int n0{0};
    static int n1{1};
    static int n2{};
    if (n > 0){
        n2 = n1 + n0;
        n0 = n1;
        n1 = n2;
        std::cout<< n2 << ", ";
        printFib(n-1);
    }
}