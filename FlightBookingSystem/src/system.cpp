#include            "include/system.h"
#include            "include/color.h"
#include            <iostream>
#include            "math.h"




FlightBooking::FlightBooking(int a_id, int a_capacity, int a_reserved)
             :flyId(a_id), flyCapacity(a_capacity), flyReserved(a_reserved)
{
    

    //  check for negative values 
    if( this->flyReserved < 0 ){
        std::cerr<< BOLD(FRED("[ERROR]\t")) << BOLD(FWHT( "Negative number for reservation option - new value = 0\n\n"));
        this->flyReserved = 0;
    }
    if( this->flyCapacity < 0){
        std::cerr<< BOLD(FRED("[ERROR]\t")) << BOLD(FWHT( "Negative number for capacity size - new value = 100\n\n"));
        this->flyCapacity = maxRatio - 5;
    }


//  check the max limit for reservation of the total capacity.
    while(1){

        double flyPercentage = ratioFly();

        if ( flyPercentage < maxRatio ){
            
            break;
        }
        else{
            std::cout<< '\n';
            std::cout<< BOLD(FYEL( "[WARNING]")) << "\t" << BOLD(FWHT("Maximum number of reserved seats was reached.\n"));
            std::cout<< BOLD(FYEL( "[WARNING]")) << "\t" << BOLD(FWHT("Setting the maximum number of possible reserved seats\n"));

            while ( flyPercentage > maxRatio ){

                --this->flyReserved;
                flyPercentage = ratioFly();

            }
            std::cout<< BOLD(FYEL( "[WARNING]")) << "\t" << BOLD(FWHT("For actual capacity of "<< this->flyCapacity 
                     << ", maximum number of possible reserved seats is: "<< flyReserved << "\n\n" << ));

            
            break;
        }
        
    }
    //printStatus();

}



int    FlightBooking::getId()
{
    return this->flyId;
}

void FlightBooking::setId(int const newId)
{
    this->flyId = newId;
}



double  FlightBooking::ratioFly()
{
    return double(this->flyReserved*100)/this->flyCapacity;
}

void    FlightBooking::printStatus()
{   
    std::cout<< "Flight [" << this->flyId << "] : " << this->flyReserved << "/" << this->flyCapacity << " (" << ratioFly() << "%) seats reserved" <<'\n';
}



bool        FlightBooking::checkCapacity()
{
    double flyPercentage = ratioFly();

    if ( flyPercentage < maxRatio ){
        std::cout << BOLD(FWHT("[INFO]")) << BOLD(FWHT( "\t\tMaximum is not reached.\n"));
        return true;
    }
    else{
        std::cout << BOLD(FWHT("[INFO]")) << BOLD(FWHT( "\t\tMaximum capacity reached.\n"));
        return false;
    }
}


void    FlightBooking::addReserveSeats()
{
    int seatsNumber = 0;

    while(1){
    
        std::cout<< "Seats number you like to add:\t";
        std::cin>> seatsNumber;

        if( seatsNumber < 0 ||  !seatsNumber){       

            std::cout << BOLD(FRED("\n[ERROR]")) << BOLD(FWHT("\tPositive Numbers only !\n"));
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        else break;
    }

    this->flyReserved += seatsNumber;

    if( checkCapacity() ){
    }
    else{
        cutReservation(this->flyReserved);
    }

}



void  FlightBooking::cutReservation(int &reservation)
{
    double flyPercentage = ratioFly();

    int i;
    for(i=0; flyPercentage > maxRatio; i++){
        --reservation;
        flyPercentage = double(reservation*100)/this->flyCapacity;
    }

    if (i != 0){
        std::cout<< BOLD(FYEL( "[WARNING]")) << "\t" BOLD(FWHT( << i << " places were automaticaly removed.\n"));
    }
}




void    FlightBooking::cancelReserveSeats()
{
    int seatsNumber{0};
    while(1){
    
        std::cout<< "Seats number you like to cancel:\t";
        std::cin>> seatsNumber;

        if( seatsNumber < 0 ||  !seatsNumber){       

               std::cout << BOLD(FRED("\n[ERROR]")) << BOLD(FWHT("\tPositive Numbers only !\n"));
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               continue;
        }
        else if(    this->flyReserved - seatsNumber <= 0    ){
                std::cout << BOLD(FYEL("\n[WARNING]")) << BOLD(FWHT("\tAll reserved seats are now canceled !\n"));
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                this->flyReserved = 0;
                break;
        }

    else break;
    }

    if ( this->flyReserved <= 0 ){
        this->flyReserved =  0;
    }
    else{
        this->flyReserved -= seatsNumber;
    }
    
}

