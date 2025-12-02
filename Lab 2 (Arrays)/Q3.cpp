// Heh, jagged arrays

#include <iostream>
using namespace std;

int main(){
    int depts;
    cout << "Enter number of departments: ";
    cin >> depts;

    int* students = new int[depts];
    int*** marks = new int**[depts];

    for(int d=0;d<depts;d++){
        cout << "\nEnter number of students in department " << d+1 << ": ";
        cin >> students[d];
        marks[d] = new int*[students[d]];
        for(int s=0;s<students[d];s++){
            marks[d][s] = new int[5];
            cout << "Student " << s+1 << " marks (5 subs): ";
            for(int sub=0;sub<5;sub++){
                cin >> marks[d][s][sub];
            }
        }
    }

    for(int d=0;d<depts;d++){
        int highest = -1, lowest = 1e9, sum = 0;
        for(int s=0;s<students[d];s++){
            int total = 0;
            for(int sub=0;sub<5;sub++){
                total += marks[d][s][sub];
            }
            if(total > highest) highest = total;
            if(total < lowest) lowest = total;
            sum += total;
        }
        double avg = (double)sum / students[d];
        cout << "\nDepartment " << d+1 << " Results:" << endl;
        cout << "Highest: " << highest << endl;
        cout << "Lowest: " << lowest << endl;
        cout << "Average: " << avg << endl;
    }
    for(int d = 0; d < depts ; d++){
        for(int s = 0; s < students[d]; s++){
            delete[] marks[d][s];
        }
        delete[] marks[d];
    }
    delete[] marks;
    delete[] students;

    return 0;
}
