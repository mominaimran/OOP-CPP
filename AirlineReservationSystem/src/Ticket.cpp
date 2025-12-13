// Represents a passenger’s ticket with flight, seat, and unique PNR, providing safe access and display methods.
#include "Ticket.h"
#include "ColorUtils.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;

// Constructors
Ticket::Ticket()
{
    passengerName[0] = '\0';
    flightID = 0;
    seatNumber = 0;
    PNR[0] = '\0';
}

Ticket::Ticket(const char *pname, int fid, int seat)
{
    strncpy(passengerName, pname, sizeof(passengerName) - 1);
    passengerName[sizeof(passengerName) - 1] = '\0';

    flightID = fid;
    seatNumber = seat;

    generatePNR();
}

// setters
void Ticket::setSeatNumber(int newSeat)
{
    seatNumber = newSeat;
}

void Ticket::setPNR(const char *p)
{
    strcpy(PNR, p);
}

// Getters
const char *Ticket::getPassengerName() const { return passengerName; }
int Ticket::getFlightID() const { return flightID; }
int Ticket::getSeatNumber() const { return seatNumber; }
const char *Ticket::getPNR() const { return PNR; }

// Generates a unique ticket PNR in the format FL12345 using a random 5-digit number.
void Ticket::generatePNR()
{
    srand(time(nullptr));
    int randNum = 10000 + rand() % 90000;
    // Safely writes "FL" + random number into PNR array, preventing overflow.
    snprintf(PNR, sizeof(PNR), "FL%d", randNum);
}

// Display ticket
void Ticket::display() const
{
    const int w1 = 12, w2 = 16;
    cout << "| " << setw(w1 - 1) << left << "Passenger"
         << "| " << setw(w2 - 1) << left << passengerName << "|\n";
    cout << "| " << setw(w1 - 1) << left << "Flight ID"
         << "| " << setw(w2 - 1) << left << flightID << "|\n";
    cout << "| " << setw(w1 - 1) << left << "Seat No"
         << "| " << setw(w2 - 1) << left << seatNumber << "|\n";
    cout << "| " << setw(w1 - 1) << left << "PNR"
         << "| " << setw(w2 - 1) << left << PNR << "|\n";
}
