#include "Passenger.h"
#include "FileManager.h"
#include "ColorUtils.h"
#include "Ticket.h"
#include <windows.h>
#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

/*
=>NOTE:
 Char arrays are used instead of std::string because this project
 uses binary file handling. std::string stores data dynamically,
 which makes direct binary read/write unsafe, while char arrays
 have a fixed memory layout and are safe for binary storage.
*/

// Initializes all character arrays as empty strings
Passenger::Passenger()
{
    name[0] = '\0';
    cnic[0] = '\0';
    phone[0] = '\0';
}

// Safely copies input values into fixed-size character arrays
Passenger::Passenger(const char *nm, const char *c, const char *ph)
{
    strncpy(name, nm, sizeof(name) - 1);
    // ensures null termination
    name[sizeof(name) - 1] = '\0';
    strncpy(cnic, c, sizeof(cnic) - 1);
    cnic[sizeof(cnic) - 1] = '\0';
    strncpy(phone, ph, sizeof(phone) - 1);
    phone[sizeof(phone) - 1] = '\0';
}

// Copies input string into fixed-size array and prevents overflow
void Passenger::setName(const char *nm)
{
    strncpy(name, nm, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}
void Passenger::setCNIC(const char *c)
{
    strncpy(cnic, c, sizeof(cnic) - 1);
    cnic[sizeof(cnic) - 1] = '\0';
}
void Passenger::setPhone(const char *ph)
{
    strncpy(phone, ph, sizeof(phone) - 1);
    phone[sizeof(phone) - 1] = '\0';
}

const char *Passenger::getName() const { return name; }
const char *Passenger::getCNIC() const { return cnic; }
const char *Passenger::getPhone() const { return phone; }

void Passenger::bookFlight()
{
    cout << BOLD_CYAN << "\n══════════ ✈ BOOK A FLIGHT ✈ ══════════\n"
         << RESET;
    // --- Passenger Info ---
    char nm[50], c[15], ph[15];

    cout << BOLD_YELLOW << "Enter your name: " << RESET;
    cin.getline(nm, 50);

    cout << BOLD_YELLOW << "Enter CNIC (no dashes): " << RESET;
    cin.getline(c, 15);

    cout << BOLD_YELLOW << "Enter phone number: " << RESET;
    cin.getline(ph, 15);

    Passenger p(nm, c, ph);
    FileManager::savePassenger(p);

    // --- Load all flights ---
    vector<Flight> flights = FileManager::getAllFlights();
    if (flights.empty())
    {
        cout << BOLD_RED << "No flights available at the moment.\n"
             << RESET;
        return;
    }

    int flightID;
    cout << BOLD_GREEN << "\nEnter Flight ID to book: " << RESET;
    cin >> flightID;

    Flight selectedFlight;
    bool found = false;
    for (auto &f : flights)
    {
        if (f.getFlightID() == flightID)
        {
            selectedFlight = f;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << BOLD_RED << "❌ Flight ID not found.\n"
             << RESET;
        Beep(400, 300);
        return;
    }
    // --- Show seat map ---
    selectedFlight.displaySeatMap();
    // --- Select Seat ---
    int seatNo;
    cout << BOLD_GREEN << "Enter seat number to reserve: " << RESET;
    cin >> seatNo;

    if (!selectedFlight.reserveSeat(seatNo))
    {
        cout << BOLD_RED << "❌ Seat not available or invalid.\n"
             << RESET;
        return;
    }
    // --- Update seat in file ---
    if (!FileManager::updateFlightSeats(selectedFlight))
    {
        cout << BOLD_RED << "❌ Error updating seat information.\n"
             << RESET;
        return;
    }

    // --- Create Ticket ---
    Ticket t(p.getName(), flightID, seatNo);
    FileManager::saveTicket(t);

    // Animation stuff
    cout << MAGENTA << "Processing" RESET;
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        Sleep(500);
    }
    cout << endl;

    // --- Booking confirmation ---
    Beep(800, 200);
    cout << BOLD_CYAN << "\n🛫 Flight booking completed!" << RESET << endl;
    cout << BOLD_YELLOW << "Please save your PNR: " << BOLD_CYAN << t.getPNR() << RESET << "\n";
    cout << BOLD_CYAN << "Thank you for booking with OUR Airlines ✈️\n"
         << RESET;
    cout << BOLD_YELLOW << "-------------------------------------------\n"
         << RESET;
}

void Passenger::viewAllFlights()
{
    vector<Flight> flights = FileManager::getAllFlights();
    if (flights.empty())
    {
        cout << "No flights available.\n";
    }
    else
    {
        Flight::printHeader();
        for (const auto &f : flights)
            f.display();
        Flight::printFooter();
    }
}

void Passenger::viewBookedTicket()
{
    string pnr;
    cout << BOLD_YELLOW << "🔎 Enter your PNR: " << RESET;
    cin >> pnr;

    vector<Ticket> tickets = FileManager::getAllTickets();
    bool found = false;
    Ticket userTicket;

    for (const auto &t : tickets)
    {
        if (t.getPNR() == pnr)
        {
            userTicket = t;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << BOLD_RED << "❌ Ticket NOT found! (PNR: " << pnr << ")\n"
             << RESET;
        return;
    }

    // Display Ticket Details
    Beep(800, 200);
    cout << BOLD_CYAN << "\n==============================\n";
    cout << "        🎟️  YOUR TICKET        \n";
    cout << "==============================\n"
         << RESET;
    userTicket.display();
    cout << BOLD_CYAN << "==============================\n"
         << RESET;
}

// Lets a passenger safely change their booked seat, updating both ticket and flight files.
void Passenger::updateBooking()
{
    cout << BOLD_YELLOW << "\n══════════ ✈ UPDATE BOOKING ✈ ══════════\n"
         << RESET;

    string pnr;
    cout << BOLD_YELLOW << "Enter your PNR: " << RESET;
    cin >> pnr;

    // --- Load all tickets ---
    vector<Ticket> tickets = FileManager::getAllTickets();
    Ticket userTicket;
    bool found = false;

    for (auto &t : tickets)
    {
        if (t.getPNR() == pnr)
        {
            userTicket = t;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << BOLD_RED << "❌ No ticket found for this PNR.\n"
             << RESET;
        return;
    }

    int flightID = userTicket.getFlightID();

    // --- Load all flights ---
    vector<Flight> flights = FileManager::getAllFlights();
    Flight userFlight;
    bool flightFound = false;

    for (auto &f : flights)
    {
        if (f.getFlightID() == flightID)
        {
            userFlight = f;
            flightFound = true;
            break;
        }
    }

    if (!flightFound)
    {
        cout << BOLD_RED << "❌ Flight not found!\n"
             << RESET;
        return;
    }

    cout << BOLD_YELLOW << "\n--- Current Booking Details ---\n"
         << RESET;
    cout << BOLD_CYAN << "Passenger Name: " << RESET << userTicket.getPassengerName() << "\n";
    cout << BOLD_CYAN << "Flight ID: " << RESET << userFlight.getFlightID() << "\n";
    cout << BOLD_CYAN << "Old Seat: " << RESET << userTicket.getSeatNumber() << "\n";

    cout << BOLD_YELLOW << "\n--- Available Seats ---\n"
         << RESET;
    userFlight.displaySeatMap();

    // --- Unreserve old seat ---
    userFlight.cancelSeat(userTicket.getSeatNumber());

    int newSeat;
    cout << BOLD_GREEN << "\nEnter new seat number to update: " << RESET;
    cin >> newSeat;

    if (!userFlight.reserveSeat(newSeat))
    {
        cout << BOLD_RED << "❌ Seat not available! Reverting to old seat...\n"
             << RESET;
        userFlight.reserveSeat(userTicket.getSeatNumber()); // restore old seat
        return;
    }

    // --- Update flight seats in file ---
    if (!FileManager::updateFlightSeats(userFlight))
    {
        cout << BOLD_RED << "❌ Error updating seat map!\n"
             << RESET;
        return;
    }

    // --- Update ticket info ---
    Ticket updated(userTicket.getPassengerName(), flightID, newSeat);
    updated.setPNR(userTicket.getPNR());

    if (!FileManager::updateTicket(updated))
    {
        cout << BOLD_RED << "❌ Ticket update failed!\n"
             << RESET;
        return;
    }

    // --- Success Message ---
    cout << BOLD_CYAN << "\n💺 Seat updated successfully! 🎉\n"
         << RESET;
    cout << BOLD_YELLOW << "Old Seat: " << RESET << BOLD_RED << userTicket.getSeatNumber() << RESET << "\n";
    cout << BOLD_YELLOW << "New Seat: " << RESET << BOLD_GREEN << newSeat << RESET << "\n";
    cout << BOLD_CYAN << "Thank you for choosing OUR Airlines ✈️\n"
         << RESET;
    cout << BOLD_YELLOW << "-------------------------------------------\n"
         << RESET;
}

// Cancels a passenger's booking by freeing the seat and removing the ticket from files.
void Passenger::cancelBooking()
{
    cout << BOLD_CYAN << "\n══════════ ✈  CANCEL BOOKING ✈ ══════════\n"
         << RESET;

    string pnr;
    cout << BOLD_YELLOW << "Enter your PNR to cancel: " << RESET;
    cin >> pnr;

    // --- Find the ticket ---
    vector<Ticket> tickets = FileManager::getAllTickets();
    Ticket foundTicket;
    bool found = false;

    for (const auto &t : tickets)
    {
        if (string(t.getPNR()) == pnr)
        {
            foundTicket = t;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << BOLD_RED << "❌ No ticket found with PNR: " << pnr << "\n"
             << RESET;
        return;
    }

    int flightID = foundTicket.getFlightID();
    int seatNo = foundTicket.getSeatNumber();

    // --- Find the flight ---
    vector<Flight> flights = FileManager::getAllFlights();
    Flight flightToUpdate;
    bool flightFound = false;

    for (auto &f : flights)
    {
        if (f.getFlightID() == flightID)
        {
            flightToUpdate = f;
            flightFound = true;
            break;
        }
    }

    if (!flightFound)
    {
        cout << BOLD_RED << "❌ Associated flight (ID " << flightID << ") not found.\n"
             << RESET;
        return;
    }

    // --- Cancel seat in memory ---
    if (!flightToUpdate.cancelSeat(seatNo))
    {
        cout << BOLD_RED << "❌ Seat " << seatNo << " was already free or invalid.\n"
             << RESET;
        return;
    }

    // --- Update flight seat in file ---
    if (!FileManager::updateFlightSeats(flightToUpdate))
    {
        cout << BOLD_RED << "❌ Failed to update flight seats in file. Cancellation aborted.\n"
             << RESET;
        return;
    }

    // --- Delete ticket record ---
    if (!FileManager::deleteTicket(pnr))
    {
        cout << BOLD_RED << "❌ Failed to remove ticket record from file. Please contact admin.\n"
             << RESET;
        return;
    }

    // --- Success message ---
    cout << BOLD_GREEN << "\n✅ Booking canceled successfully! ✅\n"
         << RESET;
    cout << BOLD_YELLOW << "Seat " << RESET << BOLD_CYAN << seatNo << RESET
         << BOLD_YELLOW << " is now available on flight " << RESET
         << BOLD_CYAN << flightID << "\n"
         << RESET;
}

// Passenger Menu
void Passenger::showMenu()
{
    int choice;
    do
    {
        cout << BOLD_CYAN;
        cout << "╔══════════════════════════════╗\n";
        cout << "║      🧍 PASSENGER MENU       ║\n";
        cout << "╚══════════════════════════════╝\n";
        cout << RESET;

        cout << " 1️⃣   View All Flights\n";
        cout << " 2️⃣   Book a Flight\n";
        cout << " 3️⃣   View Booked Ticket\n";
        cout << " 4️⃣   Update Booking\n";
        cout << " 5️⃣   Cancel Booking\n";
        cout << " 0️⃣   Exit\n";

        cout << BOLD_YELLOW;
        cout << "--------------------------------\n";
        cout << "👉 Enter your choice: ";
        cout << RESET;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            viewAllFlights();
            break;
        case 2:
            bookFlight();
            break;
        case 3:
            viewBookedTicket();
            break;
        case 4:
            updateBooking();
            break;
        case 5:
            cancelBooking();
            break;
        case 0:
            cout << BOLD_MAGENTA << "🚪 Exiting Passenger Menu...\n"
                 << RESET;
            break;
        default:
            cout << BOLD_RED << "❌ Invalid choice! Try again.\n"
                 << RESET;
            Beep(400, 300);
        }
    } while (choice != 0);
}
