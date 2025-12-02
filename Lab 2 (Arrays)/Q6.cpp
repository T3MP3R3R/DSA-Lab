#include <iostream>
#include <string>
using namespace std;

int main(){
    int rows;
    cout << "Enter number of rows in hall: ";
    cin >> rows;
    int* seats = new int[rows];
    string** seating = new string*[rows];

    for(int i = 0; i < rows; i++){
        cout << "Enter number of seats in row " << i+1 << ": ";
        cin >> seats[i];
        seating[i] = new string[seats[i]];
    }

    cout << "\nEnter attendee name for each seat:" << endl;
    for(int i = 0; i < rows; i++){
        cout << "Row " << i+1 << ": " << endl;
        for(int j = 0; j < seats[i]; j++){
            cout << " | Seat " << j+1 << ":";
            cin >> seating[i][j];
        }
    }

    cout << "\nSeating Chart:" << endl;
    for(int i = 0; i < rows; i++){
        cout << "Row " << i+1 << ": ";
        for(int j = 0; j < seats[i]; j++){
            cout << seating[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++){
        delete[] seating[i];
    }
    delete[] seating;
    delete[] seats;

    return 0;
}
