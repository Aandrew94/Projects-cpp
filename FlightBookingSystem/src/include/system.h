#ifndef         SYSTEM_H
#define         SYSTEM_H

class FlightBooking{
    
    private:
        int     flyId;
        int     flyCapacity;
        int     flyReserved;
        double  maxRatio = 105.0;

        
    public:
        FlightBooking(int a_id, int a_capacity, int a_reserved);
        virtual ~FlightBooking();
        

        double  ratioFly();
        void    printStatus();
        bool    checkCapacity();

        void    addReserveSeats();
        void    cutReservation(int &reservation);
        void    cancelReserveSeats();

        int     getId();
};

#endif          //SYSTEM_H


