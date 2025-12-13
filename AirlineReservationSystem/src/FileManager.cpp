// Handles all file operations for Admin, Flight, Passenger, and Ticket using binary I/O for safe storage.
#include "FileManager.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

// Validate Admin
bool FileManager::validateAdmin(const string &username, const string &password)
{
    ifstream file("data/admin.txt");
    if (!file)
    {
        cout << "Error: admin.txt not found!" << endl;
        return false;
    }
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string fileUser, filePass;
        iss >> fileUser >> filePass;

        if (username == fileUser && password == filePass)
        {
            return true;
        }
    }
    return false;
}

// create Admin Account
bool FileManager::createAdminAccount(const string &username, const string &password)
{
    ofstream file("data/admin.txt", ios::app);
    if (!file)
    {
        cout << "Error: File not found!";
    }
    file << username << " " << password << '\n';
    return true;
}

// Flight Handling
void FileManager::addFlight(const Flight &flight)
{
    ofstream outFile("data/flights.dat", ios::binary | ios::app);
    if (!outFile)
    {
        cerr << "Error opening flights.dat!" << endl;
        return;
    }
    outFile.write(reinterpret_cast<const char *>(&flight), sizeof(Flight));
    outFile.close();
}

vector<Flight> FileManager::getAllFlights()
{
    vector<Flight> flights;
    ifstream inFile("data/flights.dat", ios::binary);
    if (!inFile)
    {
        cerr << "Error opening flights.dat!" << endl;
        return flights;
    }

    Flight flight;
    while (inFile.read(reinterpret_cast<char *>(&flight), sizeof(Flight)))
    {
        flights.push_back(flight);
    }
    inFile.close();
    return flights;
}

bool FileManager::deleteFlight(int flightID)
{
    ifstream inFile("data/flights.dat", ios::binary);
    if (!inFile)
    {
        cerr << "Error opening flights.dat!" << endl;
        return false;
    }

    ofstream outFile("data/temp.dat", ios::binary);
    if (!outFile)
    {
        cerr << "Error creating temp file!" << endl;
        inFile.close();
        return false;
    }

    Flight flight;
    bool found = false;
    while (inFile.read(reinterpret_cast<char *>(&flight), sizeof(Flight)))
    {
        if (flight.getFlightID() == flightID)
        {
            found = true;
            continue; // Skips the one matching flightID (effectively deleting it).
        }
        outFile.write(reinterpret_cast<const char *>(&flight), sizeof(Flight));
    }

    inFile.close();
    outFile.close();
    remove("data/flights.dat");
    rename("data/temp.dat", "data/flights.dat");

    return found;
}

bool FileManager::updateFlightSeats(const Flight &flight)
{
    ifstream inFile("data/flights.dat", ios::binary);
    if (!inFile)
        return false;

    ofstream outFile("data/temp.dat", ios::binary);
    if (!outFile)
    {
        inFile.close();
        return false;
    }

    Flight f;
    bool updated = false;
    while (inFile.read(reinterpret_cast<char *>(&f), sizeof(Flight)))
    {
        if (f.getFlightID() == flight.getFlightID())
        {
            outFile.write(reinterpret_cast<const char *>(&flight), sizeof(Flight));
            updated = true;
        }
        else
        {
            outFile.write(reinterpret_cast<const char *>(&f), sizeof(Flight));
        }
    }

    inFile.close();
    outFile.close();
    remove("data/flights.dat");
    rename("data/temp.dat", "data/flights.dat");

    return updated;
}

// Passenger Handling
void FileManager::savePassenger(const Passenger &passenger)
{
    ofstream outFile("data/passengers.dat", ios::binary | ios::app);
    if (!outFile)
    {
        cerr << "Error opening passengers.dat!" << endl;
        return;
    }
    outFile.write(reinterpret_cast<const char *>(&passenger), sizeof(Passenger));
    outFile.close();
}

// Ticket Handling
void FileManager::saveTicket(const Ticket &ticket)
{
    ofstream outFile("data/tickets.dat", ios::binary | ios::app);
    if (!outFile)
    {
        cerr << "Error opening tickets.dat!" << endl;
        return;
    }
    outFile.write(reinterpret_cast<const char *>(&ticket), sizeof(Ticket));
    outFile.close();
}

vector<Ticket> FileManager::getAllTickets()
{
    vector<Ticket> tickets;
    ifstream inFile("data/tickets.dat", ios::binary);
    if (!inFile)
    {
        cerr << "Error opening tickets.dat!" << endl;
        return tickets;
    }

    Ticket ticket;
    while (inFile.read(reinterpret_cast<char *>(&ticket), sizeof(Ticket)))
    {
        tickets.push_back(ticket);
    }
    inFile.close();
    return tickets;
}

bool FileManager::deleteTicket(const std::string &pnr)
{
    std::ifstream inFile("data/tickets.dat", std::ios::binary);
    if (!inFile)
    {
        std::cerr << "Error opening tickets.dat!" << std::endl;
        return false;
    }

    std::ofstream outFile("data/temp_tickets.dat", std::ios::binary);
    if (!outFile)
    {
        std::cerr << "Error creating temp file for tickets!" << std::endl;
        inFile.close();
        return false;
    }

    Ticket ticket;
    bool found = false;
    while (inFile.read(reinterpret_cast<char *>(&ticket), sizeof(Ticket)))
    {
        // Compare PNR strings safely
        std::string tpnr = ticket.getPNR();
        if (tpnr == pnr)
        {
            found = true;
            // skip writing this ticket -> deletes it
            continue;
        }
        outFile.write(reinterpret_cast<const char *>(&ticket), sizeof(Ticket));
    }

    inFile.close();
    outFile.close();

    if (!found)
    {
        // remove temp file if nothing removed
        remove("data/temp_tickets.dat");
        return false;
    }

    // Replace original file
    remove("data/tickets.dat");
    rename("data/temp_tickets.dat", "data/tickets.dat");
    return true;
}

bool FileManager::updateTicket(const Ticket &updatedTicket)
{
    std::vector<Ticket> tickets = getAllTickets();
    bool found = false;

    for (auto &t : tickets)
    {
        if (std::string(t.getPNR()) == std::string(updatedTicket.getPNR()))
        {
            t = updatedTicket; // overwrite old record
            found = true;
            break;
        }
    }

    if (!found)
        return false;

    // rewrite file
    std::ofstream file("data/tickets.dat", std::ios::binary | std::ios::trunc);
    if (!file)
        return false;

    for (const auto &t : tickets)
    {
        file.write((char *)&t, sizeof(Ticket));
    }

    file.close();
    return true;
}
