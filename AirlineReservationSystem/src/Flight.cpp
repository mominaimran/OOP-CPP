// Flight.cpp – Manages flight info and seat reservations ('0' = available, '1' = booked)
#include "Flight.h"
#include "ColorUtils.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

Flight::Flight()
{
    flightID = 0;
    strcpy(origin, "");
    strcpy(destination, "");
    strcpy(date, "");
    strcpy(time, "");
    totalSeats = 0;
    price = 0.0;

    // Initialize all seats as available ('0')
    for (int i = 0; i < 100; i++)
        seats[i] = '0';
}

Flight::Flight(int id, const char *ori, const char *dest, const char *d, const char *t, int seatsCount, double pr)
{
    flightID = id;
    strncpy(origin, ori, sizeof(origin) - 1);
    origin[sizeof(origin) - 1] = '\0';
    strncpy(destination, dest, sizeof(destination) - 1);
    destination[sizeof(destination) - 1] = '\0';
    strncpy(date, d, sizeof(date) - 1);
    date[sizeof(date) - 1] = '\0';
    strncpy(time, t, sizeof(time) - 1);
    time[sizeof(time) - 1] = '\0';
    totalSeats = seatsCount;
    price = pr;

    // Initialize seats
    for (int i = 0; i < 100; i++)
        seats[i] = '0';
}

// Setters
void Flight::setFlightID(int id) { flightID = id; }
void Flight::setOrigin(const char *ori)
{
    strncpy(origin, ori, sizeof(origin) - 1);
    origin[sizeof(origin) - 1] = '\0';
}
void Flight::setDestination(const char *dest)
{
    strncpy(destination, dest, sizeof(destination) - 1);
    destination[sizeof(destination) - 1] = '\0';
}
void Flight::setDate(const char *d)
{
    strncpy(date, d, sizeof(date) - 1);
    date[sizeof(date) - 1] = '\0';
}
void Flight::setTime(const char *t)
{
    strncpy(time, t, sizeof(time) - 1);
    time[sizeof(time) - 1] = '\0';
}
void Flight::setTotalSeats(int seats) { totalSeats = seats; }
void Flight::setPrice(double pr) { price = pr; }

// Getters
int Flight::getFlightID() const { return flightID; }
const char *Flight::getOrigin() const { return origin; }
const char *Flight::getDestination() const { return destination; }
const char *Flight::getDate() const { return date; }
const char *Flight::getTime() const { return time; }
int Flight::getTotalSeats() const { return totalSeats; }
double Flight::getPrice() const { return price; }

bool Flight::isSeatAvailable(int seatNumber) const
//'0' available, '1' booked
{
    if (seatNumber < 1 || seatNumber > totalSeats)
        return false; // if booked

    return seats[seatNumber - 1] == '0';
}

bool Flight::reserveSeat(int seatNumber)
{
    if (!isSeatAvailable(seatNumber))
        return false;

    seats[seatNumber - 1] = '1';
    return true;
}

bool Flight::cancelSeat(int seatNumber)
{
    if (seatNumber < 1 || seatNumber > totalSeats)
        return false;

    if (seats[seatNumber - 1] == '0')
        return false; // already free

    seats[seatNumber - 1] = '0';
    return true;
}

void Flight::displaySeatMap() const
{
    cout << BOLD_CYAN << "\n===== Seat Map for Flight " << flightID << " =====\n"
         << RESET;
    cout << GREEN << "[ ] Available  " << RED << "[X] Booked" << RESET << "\n";
    int seatsPerRow = 5;

    for (int i = 0; i < totalSeats; i++)
    {
        int row = (i / seatsPerRow) + 1;

        if (i % seatsPerRow == 0)
            cout << BOLD_YELLOW << "Row " << row << " : " << RESET;

        if (seats[i] == '0') // seat available
        {
            cout << GREEN << "[" << i + 1 << "] " << RESET;
        }
        else // seat booked
        {
            cout << RED << "[ X ] " << RESET;
        }

        if ((i + 1) % seatsPerRow == 0)
            cout << endl;
    }

    cout << BOLD_YELLOW << "\n=====================================\n"
         << RESET;
}

// Display FLights
void Flight::printHeader()
{
    const int w1 = 8, w2 = 12, w3 = 12, w4 = 18, w5 = 6, w6 = 10;
    cout << BOLD_CYAN;
    cout << "════════════════ ✈️  AVAILABLE FLIGHTS ✈️  ════════════════\n";
    cout << RESET;
    cout << BOLD_YELLOW;
    cout << "+" << string(w1, '-') << "+" << string(w2, '-') << "+"
         << string(w3, '-') << "+" << string(w4, '-') << "+"
         << string(w5, '-') << "+" << string(w6, '-') << "+\n";

    cout << "| " << setw(w1) << left << "Flight"
         << "| " << setw(w2) << left << "Origin"
         << "| " << setw(w3) << left << "Destination"
         << "| " << setw(w4) << left << "Date & Time"
         << "| " << setw(w5) << left << "Seats"
         << "| " << setw(w6) << left << "Price"
         << "|\n";

    cout << "+" << string(w1, '-') << "+" << string(w2, '-') << "+"
         << string(w3, '-') << "+" << string(w4, '-') << "+"
         << string(w5, '-') << "+" << string(w6, '-') << "+\n";
    cout << RESET;
}

void Flight::display() const
{
    const int w1 = 8, w2 = 12, w3 = 12, w4 = 18, w5 = 6, w6 = 10;
    cout << BOLD_CYAN;
    cout << "| " << setw(w1) << left << BOLD_GREEN << flightID << RESET BOLD_CYAN << "| " << setw(w2) << left << origin
         << "| " << setw(w3) << left << destination
         << "| " << setw(w4) << left << (string(date) + " " + time)
         << "| " << setw(w5) << left << totalSeats
         << "| " << setw(w6) << left << price
         << "|\n";
    cout << RESET;
}

void Flight::printFooter()
{
    const int w1 = 8, w2 = 12, w3 = 12, w4 = 18, w5 = 6, w6 = 10;
    cout << BOLD_YELLOW;
    cout << "+" << string(w1, '-') << "+" << string(w2, '-') << "+"
         << string(w3, '-') << "+" << string(w4, '-') << "+"
         << string(w5, '-') << "+" << string(w6, '-') << "+\n";
    cout << RESET;
}
