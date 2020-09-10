#ifndef         BASE_H
#define         BASE_H


void        welcomeMsg();
void        printMenu();
void        checkVal(int &number);

FlightBooking* generateOneFlight();

void        generateMore(std::vector<FlightBooking*> &flys);
void        deleteFlight(std::vector<FlightBooking*> &flys);
void        list(std::vector<FlightBooking*>  &flys);
void        addToFly(std::vector<FlightBooking*> &flys);
void        cancelFromFly(std::vector<FlightBooking*> &flys);



#endif          //SYSTEM_H