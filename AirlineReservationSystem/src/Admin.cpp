// Everything an Admin can do in the Airline Reservation System is handled here.
#include "Admin.h"
#include "FileManager.h"
#include "Flight.h"
#include "ColorUtils.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <windows.h>
#include <limits>
using namespace std;

bool Admin::signup()
{
    // 🎨 Header
    cout << BOLD_YELLOW << "\n╔════════════════════════════╗\n";
    cout << "║       CREATE ACCOUNT       ║\n";
    cout << "╚════════════════════════════╝\n"
         << RESET;

    // 👤 Input username
    cout << BOLD_CYAN << "-> Enter Username(without spaces): " << RESET;
    cin >> username;

    // 👤 Input password
    cout << BOLD_CYAN << "-> Enter Password(without spaces): " << RESET;
    cin >> password;

    // ✅ Create account
    if (FileManager::createAdminAccount(username, password))
    {
        cout << GREEN << "✅ Account created successfully! Welcome, " << username << "!\n"
             << RESET;
        return true;
    }
    else
    {
        cout << RED << "❌ Error creating account. Please try again.\n"
             << RESET;
        return false;
    }
}

bool Admin::login()
{
    // 🎨 Header
    cout << BOLD_YELLOW << "\n╔════════════════════════════╗\n";
    cout << "║        ADMIN LOGIN         ║\n";
    cout << "╚════════════════════════════╝\n"
         << RESET;

    cout << BOLD_CYAN << "-> Enter Admin Username(without spaces): " << RESET;
    cin >> username;

    // 👤 Input password
    cout << BOLD_CYAN << "-> Enter Admin Password(without spaces): " << RESET;
    cin >> password;

    // ✅ Validate credentials
    if (FileManager::validateAdmin(username, password))
    {
        cout << GREEN << "✅ Login Successful! Welcome, " << username << "!\n"
             << RESET;
        return true;
    }
    else
    {
        cout << RED << "❌ Invalid Username or Password. Try again.\n"
             << RESET;
        cout << YELLOW << "⚠️ Don't have an account? Please Signup.\n"
             << RESET;
        return false;
    }
}

// Admin Features
void Admin::addFlight()
{
    int id, seats;
    char origin[50], destination[50], date[12], time[6];
    double price;

    cout << BOLD_YELLOW << "\n╔════════════════════════════╗\n";
    cout << "║         ADD NEW FLIGHT     ║\n";
    cout << "╚════════════════════════════╝\n"
         << RESET;

    // --- Flight ID input with duplicate check ---
    vector<Flight> flights = FileManager::getAllFlights();
    while (true)
    {
        cout << BOLD_CYAN << "-> Enter Flight ID(integers only): " << RESET;
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        bool exists = false;
        //(type variable : container)
        for (const auto &f : flights) // loop through all flights (read-only, reference)
        {
            if (f.getFlightID() == id)
            {
                exists = true;
                break;
            }
        }
        if (exists)
        {
            cout << RED << "❌ Error: Flight ID already exists! Try again.\n"
                 << RESET;
        }
        else
        {
            break; // valid ID
        }
    }

    cout << BOLD_CYAN << "-> Enter Origin: " << RESET;
    cin.getline(origin, 50);
    cout << BOLD_CYAN << "-> Enter Destination: " << RESET;
    cin.getline(destination, 50);
    cout << BOLD_CYAN << "-> Enter Date (e.g., 19-12-2025): " << RESET;
    cin.getline(date, 12);
    cout << BOLD_CYAN << "-> Enter Time (e.g., 16:30): " << RESET;
    cin.getline(time, 6);

    cout << BOLD_CYAN << "-> Enter Total Seats: " << RESET;
    cin >> seats;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << BOLD_CYAN << "-> Enter Price: " << RESET;
    cin >> price;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Flight flight(id, origin, destination, date, time, seats, price);
    FileManager::addFlight(flight);

    cout << GREEN << "✅ Flight added successfully!\n"
         << RESET;
    Beep(800, 200);
}

void Admin::viewFlights()
{
    vector<Flight> flights = FileManager::getAllFlights();

    cout << BOLD_YELLOW << "\n╔════════════════════════════╗\n";
    cout << "║       AVAILABLE FLIGHTS    ║\n";
    cout << "╚════════════════════════════╝\n"
         << RESET;

    if (flights.empty())
    {
        cout << BOLD_RED << "⚠️  No flights available.\n"
             << RESET;
    }
    else
    {
        Flight::printHeader(); // Table header
        for (const auto &f : flights)
            f.display();       // Each flight row
        Flight::printFooter(); // Table footer
    }
}

void Admin::deleteFlight()
{
    int id;
    cout << BOLD_YELLOW << "Enter Flight ID to delete: " << RESET;
    cin >> id;

    // Confirm deletion
    char confirm;
    cout << BOLD_CYAN << "Are you sure you want to delete Flight ID " << id << "? (y/n): " << RESET;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y')
    {
        if (FileManager::deleteFlight(id))
        {
            cout << BOLD_GREEN << "✅ Flight deleted successfully!\n"
                 << RESET;
        }
        else
        {
            cout << BOLD_RED << "❌ Flight ID not found!\n"
                 << RESET;
        }
    }
    else
    {
        cout << BOLD_MAGENTA << "⚠️ Deletion canceled by user.\n"
             << RESET;
    }
}

// Admin Menu
void Admin::showMenu()
{
    int choice;
    do
    {
        cout << BOLD_CYAN << "\n╔════════════════════════════╗\n";
        cout << "║    FLIGHT MANAGEMENT MENU  ║\n";
        cout << "╚════════════════════════════╝\n"
             << RESET;

        cout << GREEN << "1️⃣  Add Flight" << RESET << endl;
        cout << GREEN << "2️⃣  View All Flights" << RESET << endl;
        cout << GREEN << "3️⃣  Delete Flight" << RESET << endl;
        cout << GREEN << "0️⃣  Logout" << RESET << endl;

        cout << BOLD_CYAN << "-> Enter your choice: " << RESET;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addFlight();
            break;
        case 2:
            viewFlights();
            break;
        case 3:
            deleteFlight();
            break;
        case 0:
            cout << BOLD_CYAN << "👋 Logging out...\n"
                 << RESET;
            Beep(800, 200);
            break;
        default:
            cout << RED << "❌ Invalid choice! Try again.\n"
                 << RESET;
            Beep(400, 300);
        }
    } while (choice != 0);
}
