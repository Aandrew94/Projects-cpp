#include            <iostream>
#include            <vector>
#include            "include/system.h"
#include            "include/color.h"



void              printMenu();
void              checkVal(int &number);

FlightBooking* generateOneFlight();
void    generateMore(std::vector<FlightBooking*> &flys);
void    deleteFlight(std::vector<FlightBooking*> &flys);
void    list(std::vector<FlightBooking*>  &flys);

void    addToFly(std::vector<FlightBooking*> &flys);
void    cancelFromFly(std::vector<FlightBooking*> &flys);


/****************************** 
 *      BEGIN OF MAIN         *
 ******************************/

int main(){

    int FLY_LIMIT   =   10;
    int reserved = 0, capacity = 0;
    
    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;
    
    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;


//  Command start
    std::string command{};
    std::cout<< "\nTo get to the menu - write:\t menu";
    std::cout<< "\nTo exit - write:\t quit\n";

//  The vector
    std::vector<FlightBooking*>  flights;
    FlightBooking booking(1, capacity, reserved);
    flights.push_back(&booking);


    while( command != "quit" ){
        std::cout<< "\n\n";
        std::cin>>command;

        if ( command == "menu"){
            printMenu();
        }
        else if ( command == "create one"){                    //  generate one flight
            std::cout<<"\nGenerate ONE FLIGHT\n";
            flights.push_back(generateOneFlight());
        }
        else if ( command == "create" ){                   //  generate more flights
            std::cout<<"\nGenerate more FLIGHT\n";
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

void    printMenu()
{
    std::cout<< '\n';
    std::cout<< "\t\t " << BOLD(FWHT(UNDL( "MAIN MENU\n\n")));
    std::cout<< "\t|  " << "1. Show the menu:\t\t\t" << FGRN("menu") << '\n';
    std::cout<< "\t|  " << "2. Create flight:\t\t\t" << FGRN("create") <<"  <id>   <capacity>\n";
    std::cout<< "\t|  " << "3. Delete flight:\t\t\t" << FGRN("delete") <<"  <id>\n";
    std::cout<< "\t|  " << "4. Add seats:\t\t\t" << FGRN("add") << "\t<at_id> <seats_nr>\n";
    std::cout<< "\t|  " << "5. Remove seats:\t\t\t" << FGRN("cancel ") <<" <at_id> <seats_nr>\n";
    std::cout<< "\t|  " << "6. List all the available flights:\t" << FGRN ("list") << '\n';
    std::cout<< "\t|  " << "7. Quit the program:\t\t\t" << FGRN("quit") << '\n';
    std::cout<< "\t|\n\t|\n";
    std::cout<< "\t|  " << "Legend : . . . \n";
    std::cout<< "\t" << "\\____________________________________________________________________/\n";
}

void checkVal(int &number)
{
    while(1){
    
        std::cout << "Provide the new value:\t";
        std::cin >> number;  

        if( number < 0 || !number ){       

            std::cout << BOLD(FRED("\n[ERROR]")) << BOLD(FWHT("\tPositive Numbers only !\n"));
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else break;
    }
}


FlightBooking* generateOneFlight()
{
    int     id          =   0;
    int     capacity    =   0;
    int     reserved    =   0;

    std::cout<< BOLD(UNDL("\t | Get new ID | \n"));
    checkVal(id);

    std::cout<< BOLD(UNDL("\t | Get new capacity | \n"));
    checkVal(capacity);

    return new FlightBooking(id, capacity, reserved);

}


void    generateMore(std::vector<FlightBooking*> &flys)
{
    //std::cout<<flys.size()<<std::endl;


    int number;
    std::cout<< BOLD(UNDL("\t | Get number of flights | \n"));
    checkVal(number);
    
    //flys.resize(number);
    //std::cout<<"\n"<<flys.size()<<"\n";

    for (int i=0; i<number; i++){
        std::cout<<flys.size()<<"\t"<<number<<"\t"<<i<<'\n';
        flys.push_back(generateOneFlight());
    }

/*  Listing the flygtsh just to see if it works
    for (unsigned int i=0; i<=flys.size(); i++){
        flys[i]->printStatus();
    }  
*/
    

}


void    deleteFlight(std::vector<FlightBooking*> &flys)
{
    std::cout<<"Delete option\n";
    int deleteIndexFly{};
    std::cout<< BOLD(UNDL("\t | Get flight id number you wold like to delete | \n"));
    checkVal(deleteIndexFly);


    for( size_t i=0; i<flys.size(); i++){

        if (deleteIndexFly == flys[i]->getId()){
            flys.erase(flys.begin() + i);

        }
    }

}



void addToFly(std::vector<FlightBooking*> &flys)
{
    int id{};
    std::cout<< BOLD(UNDL("\t | Get id number you wold like to add seats | \n"));
    checkVal(id);

    for (size_t i=0; i<flys.size();i++){
        if ( id == flys[i]->getId()){
            flys[i]->addReserveSeats();
        }
    }
}


void cancelFromFly(std::vector<FlightBooking*> &flys)
{
    int id{};
    std::cout<< BOLD(UNDL("\t | Get id number you wold like to cancel seats | \n"));
    checkVal(id);

    for (size_t i=0; i<flys.size();i++){
        if ( id == flys[i]->getId()){
            flys[i]->cancelReserveSeats();
        }
    }
}




void    list(std::vector<FlightBooking*> &flys)
{  

    std::cout<<"\nLIST\n";
    for ( size_t i=0;i<flys.size();i++){
        flys[i]->printStatus();
    }


}





