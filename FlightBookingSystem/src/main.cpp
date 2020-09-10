#include            <iostream>
#include            <vector>
#include            "include/system.h"
#include            "include/base.h"
#include            "include/color.h"





/****************************** 
 *      BEGIN OF MAIN         *
 ******************************/

int main(){

    int reserved{};
    int capacity{};
    std::string command{};

    welcomeMsg();

    std::cout << UNDL( "\n\t | Provide flight capacity | \n");
    checkVal(capacity);
    
    std::cout << UNDL( "\n\t | Provide reserved seats | \n");
    checkVal(reserved);
    

    std::vector<FlightBooking*>  flights;
    FlightBooking booking(1, capacity, reserved);
    flights.push_back(&booking);
    printMenu();

    while( command != "quit" ){
        std::cout<< "\n\nGet command:\t";
        std::cin>>command;

        if ( command == "menu"){
            printMenu();
        }
        else if ( command == "create" ){                   //  generate more flights
            generateMore(flights);
        }
        else if ( command == "delete"){
            deleteFlight(flights);                      //  delete one flight based on it's index
        }
        else if ( command == "add"){                    //  add [id] [n] - add n reservations to flight [id]
            addToFly(flights);
        }
        else if ( command == "cancel"){                 //  cancel [id] [n] - cancel n reservations to flight [id]
            cancelFromFly(flights);
        }
        else if ( command == "list"){                    //  list all flights
            list(flights);
        }

    }

    return 0;
}

/**************************** 
 *      END OF MAIN         *
 ****************************/


