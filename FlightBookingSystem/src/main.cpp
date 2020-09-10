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


void welcomeMsg()
{
    std::cout<< "\n\n\t*** " << UNDL("Flight Booking System") << " ***\n\n";
    std::cout<< "Let's add one flight together:\n";
    std::cout<< "-> first we will need to add the capacity of our flight\n";
    std::cout<< "--> second we will need to add the reserved seats number\n";
    std::cout<< "---> third, go to the menu and list the flights\n\n\n";
    std::cout<< BOLD(FWHT("[INFO]")) << " \t To get to the menu - write:\t menu\n";
    std::cout<< BOLD(FWHT("[INFO]")) << " \t To exit the program - write:\t quit\n";
}


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

void    printMenu()
{
    std::cout<< '\n';
    std::cout<< "\t\t\t\t " << BOLD(FWHT(UNDL( "MAIN MENU\n\n")));
    std::cout<< "\t|  " << "1. Show the menu:\t\t\t"    << FGRN("menu")     << '\n';
    std::cout<< "\t|  " << "2. Create flight:\t\t\t"    << FGRN("create")   << FCYN("  <id>    <capacity>\n");
    std::cout<< "\t|  " << "3. Delete flight:\t\t\t"    << FGRN("delete")   << FCYN("  <id>\n");
    std::cout<< "\t|  " << "4. Add seats:\t\t\t"        << FGRN("add")      << FCYN("\t<at_id> <seats_nr>\n");
    std::cout<< "\t|  " << "5. Remove seats:\t\t\t"     << FGRN("cancel ")  << FCYN(" <at_id> <seats_nr>\n");
    std::cout<< "\t|  " << "6. List all the flights:\t\t"<< FGRN ("list")   << '\n';
    std::cout<< "\t|  " << "7. Quit the program:\t\t\t" << FGRN("quit")     << '\n';
    std::cout<< "\t|\n\t|\n";
    std::cout<< "\t|  " << "Legend :\t";
    std::cout<< BOLD(FGRN(" |- ")) << "commands\t\t";
    std::cout<< BOLD(FCYN(" |- ")) << "numbers\n";
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
    int number;
    bool flag = true;
    std::cout<< "\n\n> Generate more flights\n\n";
    std::cout<< BOLD(UNDL("\t | Get number of flights | \n"));
    checkVal(number);
    

    for (int i=0; i<number; i++){
        std::cout<<flys.size()<<"\t"<<number<<"\t"<<i<<'\n';
        flys.push_back(generateOneFlight());
    }
    

//  check for same ID
size_t count{};
    for (size_t i=0; i<flys.size(); i++){
        
        for(size_t j=i+1;j<flys.size();j++){
            if (flys[i]->getId() == flys[j]->getId()){

                count++;
                flys[j]->setId(flys.size() * number + count);
                std::cerr<< BOLD(FYEL("[WARNING]")) << "\t Two or more flights with the same ID - Changing ID.\n";
                std::cerr<< BOLD(FYEL("[Status]:")) << "\t Entered flight id [" << flys[i]->getId() 
                         << "]\t changed to flight id ["<<flys[j]->getId()<<"]\n";
                flag = false;
                
            }
        }
    }
    
    if (flag){
        std::cout<< BOLD(FWHT("[INFO]")) << "\t Job Done.\n";
    }
    else{
        std::cout<< BOLD(FYEL("[WARNING]")) << "\t Job Done - by changing the ID.\n";
    }
    

}


void    deleteFlight(std::vector<FlightBooking*> &flys)
{
    int deleteIndexFly{};
    bool flag = false;
    std::cout<< "\n\n> Delete flights\n\n"; 
    std::cout<< BOLD(UNDL("\t | Get flight id number you wold like to delete | \n"));
    checkVal(deleteIndexFly);


    for( size_t i=0; i<flys.size(); i++){

        if (deleteIndexFly == flys[i]->getId()){
            flys.erase(flys.begin() + i);
            flag = true;
        }
    }

    if (flag){
        std::cout<< BOLD(FWHT("[INFO]")) << "\t Job Done.\n";
    }
    else{
        std::cerr<< BOLD(FRED("[ERROR]")) << "\t Job Fail.\n";
    }

}



void addToFly(std::vector<FlightBooking*> &flys)
{
    int id{};
    bool flag = false;
    std::cout<< "\n\n> Add seats to flights\n\n"; 
    std::cout<< BOLD(UNDL("\t | Get id number you wold like to add seats | \n"));
    checkVal(id);

    for (size_t i=0; i<flys.size();i++){
        if ( id == flys[i]->getId()){
            flys[i]->addReserveSeats();
            flag = true;
        }
    }

    if (flag){
        std::cout<< BOLD(FWHT("[INFO]")) << "\t Job Done.\n";
    }
    else{
        std::cerr<< BOLD(FRED("[ERROR]")) << "\t Job Fail.\n";
    }
}


void cancelFromFly(std::vector<FlightBooking*> &flys)
{
    int id{};
    bool flag = false;
    std::cout<< "\n\n> Cancel seats from flights\n\n"; 
    std::cout<< BOLD(UNDL("\t | Get id number you wold like to cancel seats | \n"));
    checkVal(id);

    for (size_t i=0; i<flys.size();i++){
        if ( id == flys[i]->getId()){
            flys[i]->cancelReserveSeats();
            flag = true;
        }
    }

    if (flag){
        std::cout<< BOLD(FWHT("[INFO]")) << "\t Job Done.\n";
    }
    else{
        std::cerr<< BOLD(FRED("[ERROR]")) << "\t Job Fail.\n";
    }
}

void swap(FlightBooking* &a,FlightBooking* &b)
{
    FlightBooking* temp = a;
    a = b;
    b = temp;
}


void    list(std::vector<FlightBooking*> &flys)
{  
    std::cout<< "\n\n> Listing flights\n\n"; 

//  Arrange flights
    for (size_t i=0; i<flys.size(); i++){
        for(size_t j=i+1;j<flys.size();j++){

            if (flys[i]->getId() > flys[j]->getId()){
                swap(flys[i],flys[j]);
            }
        }
    }

    for ( size_t i=0;i<flys.size();i++){
        flys[i]->printStatus();
    }
}





