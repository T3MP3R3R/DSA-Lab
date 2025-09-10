#include <iostream>
using namespace std;

int main(){
    int depts = 4;
    int courses[4] = {3,4,2,1};
    string deptNames[4] = {"SE","AI","CS","DS"};

    double** gpa = new double*[depts];
    for(int i = 0; i < depts; i++){
        gpa[i] = new double[courses[i]];
    }

    for(int i = 0; i < depts; i++){
        cout << "Enter GPA for " << deptNames[i] << " (" << courses[i] << " courses):" << endl;
        for(int j = 0; j < courses[i]; j++){
            cout << " | Course " << j+1 << ": ";
            cin >> gpa[i][j];
        }
    }

    cout << "\nGPAs of Core Courses by Department:" << endl; // Coreses, no pun intended
    for(int i = 0; i < depts; i++){
        cout << deptNames[i] << ": ";
        for(int j = 0; j < courses[i]; j++){
            cout << gpa[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < depts; i++){
        delete[] gpa[i];
    }
    delete[] gpa;

    return 0;
}
