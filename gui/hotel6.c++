9#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const int MAX_ROOMS = 10;
int booked_rooms = 0;

struct room {
    int room_number;
    char guest_name[20];
    int days_stayed;
};

room hotel_rooms[MAX_ROOMS];

void display_available_rooms() {
    cout << "Available rooms: ";
    for(int i=0; i<MAX_ROOMS; i++) {
        if(hotel_rooms[i].room_number == 0) {
            cout << i+1 << " ";
        }
    }
    cout << endl;
}

void book_room() {
    if(booked_rooms == MAX_ROOMS) {
        cout << "All rooms are booked." << endl;
        return;
    }
    int room_number;
    cout << "Enter room number to book (1-" << MAX_ROOMS << "): ";
    cin >> room_number;
    if(room_number < 1 || room_number > MAX_ROOMS) {
        cout << "Invalid room number." << endl;
        return;
    }
    if(hotel_rooms[room_number-1].room_number != 0) {
        cout << "This room is already booked." << endl;
        return;
    }
    room new_booking;
    new_booking.room_number = room_number;
    cout << "Enter guest name: ";
    cin >> new_booking.guest_name;
    cout << "Enter days stayed: ";
    cin >> new_booking.days_stayed;
    hotel_rooms[room_number-1] = new_booking;
    booked_rooms++;
    cout << "Room " << room_number << " booked successfully." << endl;
}

void display_bookings() {
    cout << setw(15) << left << "Room Number" << setw(15) << left << "Guest Name" << setw(15) << left << "Days Stayed" << endl;
    for(int i=0; i<MAX_ROOMS; i++) {
        if(hotel_rooms[i].room_number != 0) {
            cout << setw(15) << left << hotel_rooms[i].room_number << setw(15) << left << hotel_rooms[i].guest_name << setw(15) << left << hotel_rooms[i].days_stayed << endl;
        }
    }
}

int main() {
    int choice;
    while(true) {
        cout << "1. Book a room\n2. View available rooms\n3. Display bookings\n4. Quit\nEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                book_room();
                break;
            case 2:
                display_available_rooms();
                break;
            case 3:
                display_bookings();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
    return 0;
}
