#ifndef PASSENGER_H
#define PASSENGER_H

class Passenger {
private:
    char name[50];
    char cnic[15];   
    char phone[15]; 

public:
    Passenger();
    Passenger(const char* nm, const char* c, const char* ph);

    // Setters
    void setName(const char* nm);
    void setCNIC(const char* c);
    void setPhone(const char* ph);

    // Getters
    const char* getName() const;
    const char* getCNIC() const;
    const char* getPhone() const;

    //Passenger features
    void viewAllFlights();
    void bookFlight();
    void viewBookedTicket();   
    void updateBooking();   
    void cancelBooking();  

    void showMenu();
};

#endif
