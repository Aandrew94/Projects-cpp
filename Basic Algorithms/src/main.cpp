#include    <iostream>
//using namespace std;
int main(){

//int array[3][3];        //  array[linie][coloana]
    int n{3};   //linie
    int m{3};   //coloana
    int array[3][3]{
        1,2,3,
        4,5,6,
        7,8,9
    };

std::cout<< "Print status 2d array:\n";
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            std::cout<<array[i][j]<<" ";
        }
    std::cout<<'\n';
    }
    std::cout<<'\n';



std::cout<<"Elementele aflate sub diagonala principala:\n";
    for(int i=0;i<3;i++){
        for(int j=0;i>j ;j++){
            std::cout<<array[i][j]<<" ";

        }
    std::cout<<'\n';
    }
    std::cout<<'\n';



std::cout<<"Elementele aflate deasupra diagonala principala:\n";
    for(int i=0;i<3;i++){
        for(int j=i+1; j<3;j++){
            std::cout<<array[i][j]<<" ";

        }
    std::cout<<'\n';
    }
    std::cout<<'\n';

std::cout<<"Elementele aflate sub diagonala secundara:\n";
    for(int i=1;i<n;i++){
        for(int j=n-i; j<n;j++){
            std::cout<<array[i][j]<<" ";

        }
    std::cout<<'\n';
    }
    std::cout<<'\n';


std::cout<<"Elementele aflate deasupra diagonala secundara:\n";
    for(int i=1;i<=n;i++){
        for(int j=1; j<=n-i;j++){
            std::cout<<array[i-1][j-1]<<" ";

        }
    std::cout<<'\n';
    }
    std::cout<<'\n';

    return 0;
}