#ifndef TICKET_H
#define TICKET_H
#include <string>

class Ticket {
private:
    char passengerName[50];
    int flightID;
    int seatNumber;
    char PNR[10]; // Unique ticket identifier (alphanumeric)

    void generatePNR(); // Private helper function to automatically create a unique PNR
public:
    Ticket();
    Ticket(const char* pname, int fid, int seat);

    // Getters
    const char* getPassengerName() const;
    int getFlightID() const;
    int getSeatNumber() const;
    const char* getPNR() const;

    // Setters
    void setSeatNumber(int newSeat);
    void setPNR(const char* p);

    // Display ticket info
    void display() const;
};

#endif

