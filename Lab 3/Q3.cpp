#include <iostream>
#include <string>
using namespace std;

struct Passenger{
    string name;
    Passenger* next;
    Passenger(string n) : name(n), next(NULL) {}
};

struct Flight{
    string flightNumber;
    Passenger* passengers;
    Flight* next;
    Flight(string fn) : flightNumber(fn), passengers(NULL), next(NULL) {}
};

class AirlineSystem{
private:
    Flight* flights;
public:
    AirlineSystem() : flights(NULL) {}

    Flight* findFlight(string fn){
        Flight* temp = flights;
        while (temp){
            if (temp->flightNumber == fn) return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void addFlight(string fn){
        if (findFlight(fn)) return;
        Flight* newFlight = new Flight(fn);
        newFlight->next = flights;
        flights = newFlight;
    }

    void reserveTicket(string fn, string name){
        Flight* flight = findFlight(fn);
        if (!flight){
            addFlight(fn);
            flight = findFlight(fn);
        }
        Passenger* newPassenger = new Passenger(name);
        if (!flight->passengers || flight->passengers->name > name){
            newPassenger->next = flight->passengers;
            flight->passengers = newPassenger;
            return;
        }
        Passenger* temp = flight->passengers;
        while (temp->next && temp->next->name < name){
            temp = temp->next;
        }
        newPassenger->next = temp->next;
        temp->next = newPassenger;
    }

    void cancelReservation(string fn, string name){
        Flight* flight = findFlight(fn);
        if (!flight || !flight->passengers) return;
        Passenger* temp = flight->passengers;
        if (temp->name == name){
            flight->passengers = temp->next;
            delete temp;
            return;
        }
        Passenger* prev = NULL;
        while (temp && temp->name != name){
            prev = temp;
            temp = temp->next;
        }
        if (temp){
            prev->next = temp->next;
            delete temp;
        }
    }

    bool checkReservation(string fn, string name){
        Flight* flight = findFlight(fn);
        if (!flight) return false;
        Passenger* temp = flight->passengers;
        while (temp){
            if (temp->name == name) return true;
            temp = temp->next;
        }
        return false;
    }

    void displayPassengers(string fn){
        Flight* flight = findFlight(fn);
        if (!flight){
            cout << "No such flight" << endl;
            return;
        }
        Passenger* temp = flight->passengers;
        if (!temp){
            cout << "No passengers" << endl;
            return;
        }
        cout << "Passengers on flight " << fn << ": ";
        while (temp){
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    AirlineSystem system;
    system.reserveTicket("ER404", "Saim");
    system.reserveTicket("ER404", "Areeb");
    system.reserveTicket("ER404", "Bob");
    system.displayPassengers("ER404");
    cout << "Is Areeb reserved? " << (system.checkReservation("ER404", "Areeb") ? "Yes" : "No") << endl;
    system.cancelReservation("ER404", "Bob");
    cout << "After canceling Bob:" << endl;
    system.displayPassengers("ER404");
    return 0;
}