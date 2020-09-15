/*
NOTE:  https://invata.info/2017/03/24/matrice-patratica/
*/

#include    <iostream>
#include    <algorithm>

void check(int &nr);

int main(){


    //int array[3][3];        //  array[linie][coloana]
    int array[3][3]{
        1,2,3,
        4,5,6,
        7,8,9
    };
    int i,j;

    /*for (i=0;i < 3; i++){
        for (j=0; j< 3; j++){
            std::cin >>array[i][j];
        }
    }*/

    std::cout<< "\n\n";

//  Show the matrix
    for (i=0;i < 3; i++){
        for (j=0; j< 3; j++){
            std::cout<< array[i][j] << "  ";
        }
        std::cout << '\n';
    }

//  Sum and Pod of principal diagonal (a[0][0] - a[1][1] - a[2][2])
    int sum_dig_p{};
    int prod_dif_p{1};

    for (i=0;i < 3; i++){
        for (j=0; j< 3; j++){
        }
        sum_dig_p += array[i][i];
        prod_dif_p *= array[i][i];
    }
    std::cout<< "sum:\t" << sum_dig_p <<'\n';
    std::cout<< "prod:\t" << prod_dif_p <<'\n';
    std::cout<< "-----\n";

//  Sum and Pod of secondary diagonal (a[0][2] - a[1][1] - a[2][0])
    int sum_dig_s{};
    int prod_dif_s{1};

    for (i=0;i < 3; i++){
        for (j=0; j< 3; j++){
        }
        sum_dig_s += array[i][3-i-1];
        prod_dif_s *= array[i][3-i-1];
    }
    std::cout<< "sum:\t" << sum_dig_s <<'\n';
    std::cout<< "prod:\t" << prod_dif_s <<'\n';

//  transpusa -> replace lines with colons 

    for (i=0;i < 3; i++){
        for (j=0; j< 3; j++){
            std::cout<< array[j][i] << "  ";
        }
        std::cout << '\n';
    }

//  delete a line 
    std::cout<<"\n delete line:\t";
    int x; std::cin>> x;
    for(i = x ; i<3 ;i++){
        for(j=0;j<3;j++){
            array[i][j] = array[i+1][j];
        }
    }   //  print the matrix
    for (i=0;i <3-x; i++){
        for (j=0; j< 3; j++){
            std::cout<< array[i][j] << "  ";
        }
        std::cout << '\n';
    }

//  delete a colon    
    std::cout<<"\n delete colon:\t";
    int y; std::cin>> y;
    for(i = 0 ; i<3-x ;i++){
        for(j=y;j<3;j++){
            array[i][j] = array[i][j+1];
        }
    }   //  print the matrix
    for (i=0;i <3-x; i++){
        for (j=0; j< 3-y; j++){
            std::cout<< array[i][j] << "  ";
        }
        std::cout << '\n';
    }


    return 0;
}

/*
    for (i=0;i < 3; i++){
        for (j=0; j< 3; j++){
        }
        sum_dig_s += array[i][3-j+1];       // coloana mijloc
        prod_dif_s *= array[i][3-j+1];      // coloana mijloc
    }
*/


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
