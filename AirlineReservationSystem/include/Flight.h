#ifndef FLIGHT_H
#define FLIGHT_H

class Flight
{
private:
    int flightID;
    char origin[50];
    char destination[50];
    char date[12];   
    char time[6];   
    int totalSeats;
    double price;
    //seat-map
    char seats[100];

public:
    Flight();
    Flight(int id, const char* ori, const char* dest, const char* d, const char* t, int seats, double pr);

    // Setters
    void setFlightID(int id);
    void setOrigin(const char* ori);
    void setDestination(const char* dest);
    void setDate(const char* d);
    void setTime(const char* t);
    void setTotalSeats(int seats);
    void setPrice(double pr);

    // Getters
    int getFlightID() const;
    const char* getOrigin() const;
    const char* getDestination() const;
    const char* getDate() const;
    const char* getTime() const;
    int getTotalSeats() const;
    double getPrice() const;

    // Seat-related methods
    bool reserveSeat(int seatNumber);      
    bool cancelSeat(int seatNumber);       
    bool isSeatAvailable(int seatNumber) const;
    void displaySeatMap() const;

    // Display
    static void printHeader();
    void display() const;
    static void printFooter();
};

#endif

