#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Reservation {
private:
    string type;
    int rate;
    bool availability;
public:
    Reservation(string t, int r, bool a) {
        type = t;
        rate = r;
        availability = a;
    }

    string getType() {
        return type;
    }

    int getRate() {
        return rate;
    }

    bool isAvailable() {
        return availability;
    }

    void setAvailability(bool a) {
        availability = a;
    }
};

class AirlineReservation : public Reservation {
private:
    string section;
public:
    AirlineReservation(string t, int r, bool a, string s) : Reservation(t, r, a) {
        section = s;
    }

    string getSection() {
        return section;
    }
};

class HotelReservation : public Reservation {
private:
    string roomType;
    int roomNumber;
public:
    HotelReservation(string t, int r, bool a, string rt, int rn) : Reservation(t, r, a) {
        roomType = rt;
        roomNumber = rn;
    }

    string getRoomType() {
        return roomType;
    }

    int getRoomNumber() {
        return roomNumber;
    }
};

class ReservationSystem {
private:
    vector<AirlineReservation> airlineReservations;
    vector<HotelReservation> hotelReservations;
public:
    ReservationSystem() {
        // Initialize reservations
    }

    void bookAirlineReservation(string type, int rate, string section) {
        bool available = true;

        for (int i = 0; i < airlineReservations.size(); i++) {
            if (airlineReservations[i].getType() == type &&
                airlineReservations[i].getRate() == rate &&
                airlineReservations[i].getSection() == section &&
                airlineReservations[i].isAvailable()) {
                airlineReservations[i].setAvailability(false);
                available = false;
                cout << "Reservation booked successfully." << endl;
                break;
            }
        }

        if (available) {
            AirlineReservation reservation(type, rate, true, section);
            airlineReservations.push_back(reservation);
            cout << "Reservation booked successfully." << endl;
        }
    }

    void bookHotelReservation(string type, int rate, string roomType, int roomNumber) {
        bool available = true;

        for (int i = 0; i < hotelReservations.size(); i++) {
            if (hotelReservations[i].getType() == type &&
                hotelReservations[i].getRate() == rate &&
                hotelReservations[i].getRoomType() == roomType &&
                hotelReservations[i].getRoomNumber() == roomNumber &&
                hotelReservations[i].isAvailable()) {
                hotelReservations[i].setAvailability(false);
                available = false;
                cout << "Reservation booked successfully." << endl;
                break;
            }
        }

        if (available) {
            HotelReservation reservation(type, rate, true, roomType, roomNumber);
            hotelReservations.push_back(reservation);
            cout << "Reservation booked successfully." << endl;
        }
    }

    void printAirlineReservations() {
        for (int i = 0; i < airlineReservations.size(); i++) {
            cout << "Reservation #" << i + 1 << ":" << endl
