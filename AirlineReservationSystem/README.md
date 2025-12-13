# Airline Reservation System ✈️

A **console-based Airline Reservation System** built in C++ that allows Admins and Passengers to manage flights and bookings efficiently.

---

## Features

### For Admins
- Add, view, and delete flights.
- Manage flight seat availability.
- Validate and create admin accounts.

### For Passengers
- View available flights.
- Book, update, and cancel tickets.
- Check seat availability and booked tickets.

---

## File Handling
- **Binary files** used for storing Flight, Passenger, and Ticket data (`.dat` files) for safe storage.
- Admin credentials stored in a **text file** (`admin.txt`).
- Temp files are used for updating/deleting records to prevent data corruption.

---

## Classes

1. **Passenger**
   - Stores passenger info (name, CNIC, phone).
   - Handles booking, updating, and canceling tickets.

2. **Ticket**
   - Stores flight booking info with unique PNR.
   - Generates PNR automatically.

3. **Flight**
   - Stores flight details and seat map.
   - Reserve/cancel seats and display seat map.

4. **FileManager**
   - Handles all file I/O operations (static methods).
   - Binary file storage for tickets, flights, passengers.

---

## How to Run

1. Clone or download the repo.
2. Compile all `.cpp` files together:
```bash
g++ main.cpp Passenger.cpp Ticket.cpp Flight.cpp FileManager.cpp -o AirlineSystem
```
3. Run the executable:
```bash
./AirlineSystem.exe
```

---

**Note**: This is a console-based application, and it's not intended for a production environment.

---

## Author
**Momina**  
*Always learning and evolving.*

---
Happy Flying! ✈️😊

