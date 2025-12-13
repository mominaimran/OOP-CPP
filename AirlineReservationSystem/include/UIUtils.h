#ifndef UIUtils_H
#define UIUtils_H

#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>
#include "colorUtils.h"
using namespace std;

inline void typeWriter(const string &text, int delay = 60)
{
    for (char c : text)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

inline void printHeader()
{
    cout << BOLD_CYAN << "\n";
    // Upper & lower borders
    cout << "════════════════════════════════════════════════\n";
    cout << "                                                \n";
    cout << "════════════════════════════════════════════════\n";

    // Typewriter header in middle
    cout << "\033[2A"; // move up 2 lines
    cout << "\033[6C"; // adjust spacing
    typeWriter("✈️   AIRLINE RESERVATION SYSTEM  ✈️", 70);
    cout << "\033[2B"; // move back down after typing
    cout << RESET;
    Beep(750, 200);

    // Left-aligned tagline
    cout << "\r";
    cout << "   • Smart Console for Airline Reservations •" << endl;
    cout << CYAN << "════════════════════════════════════════════════\n" << RESET;
}

inline void printSystemFooter()
{
    cout << BOLD_CYAN << "═══════════════════════════════\n" RESET;
    cout << "Thank you for using the system.\n";
    cout << BOLD_CYAN << "═══════════════════════════════\n" RESET;
}

#endif
