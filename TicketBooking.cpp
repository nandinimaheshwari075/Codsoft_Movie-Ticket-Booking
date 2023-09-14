#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Constants
const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;

// Function to display the seating arrangement
void displaySeating(vector<vector<char>>& seating) {
    cout << "   ";
    for (int col = 1; col <= NUM_COLS; col++) {
        cout << setw(3) << col;
    }
    cout << endl;

    for (int row = 0; row < NUM_ROWS; row++) {
        cout << static_cast<char>('A' + row) << "  ";
        for (int col = 0; col < NUM_COLS; col++) {
            cout << setw(3) << seating[row][col];
        }
        cout << endl;
    }
}

// Function to book seats
void bookSeats(vector<vector<char>>& seating, int numTickets) {
    int bookedCount = 0;

    while (bookedCount < numTickets) {
        cout << "Enter seat (e.g., A1): ";
        string seat;
        cin >> seat;

        if (seat.length() != 2 || !isalpha(seat[0]) || !isdigit(seat[1])) {
            cout << "Invalid seat format. Please enter a valid seat (e.g., A1)." << endl;
            continue;
        }

        int row = toupper(seat[0]) - 'A';
        int col = seat[1] - '0' - 1;

        if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS || seating[row][col] == 'X') {
            cout << "Invalid seat or seat already booked. Please select another seat." << endl;
        } else {
            seating[row][col] = 'X'; // Mark the seat as booked
            bookedCount++;
            cout << "Seat " << seat << " booked successfully." << endl;
        }
    }
}

int main() {
    vector<vector<char>> seating(NUM_ROWS, vector<char>(NUM_COLS, '-'));

    cout << "Welcome to the Movie Ticket Booking System" << endl;
    cout << "------------------------------------------" << endl;

    int numTickets;
    cout << "Enter the number of tickets to book: ";
    cin >> numTickets;

    cout << "Movie Seating Arrangement:" << endl;
    displaySeating(seating);

    cout << "Book your seats:" << endl;
    bookSeats(seating, numTickets);

    // Calculate the total cost
    double totalCost = numTickets * TICKET_PRICE;

    cout << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;

    return 0;
}
