#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <vector>
#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"

class FileManager
{
public:
    // Static functions allow direct file operations without creating a FileManager object.
    // ---------------- Admin ----------------
    static bool validateAdmin(const std::string &username, const std::string &password);
    static bool createAdminAccount(const std::string &username, const std::string &password);

    // ---------------- Flight ----------------
    static void addFlight(const Flight &flight);
    static std::vector<Flight> getAllFlights();
    static bool deleteFlight(int flightID);

    // ---------------- Passenger ----------------
    static void savePassenger(const Passenger &passenger);

    // ---------------- Ticket ----------------
    static void saveTicket(const Ticket &ticket);
    static std::vector<Ticket> getAllTickets();
    static bool deleteTicket(const std::string &pnr);
    static bool updateTicket(const Ticket &updatedTicket);

    // ---------------- Flight Seat Updates ----------------
    static bool updateFlightSeats(const Flight &flight); // After booking
};

#endif
