#include <iostream>
using namespace std;

int main(){
    int students = 5, subjects = 4;
    int** marks = new int*[students];
    for(int i=0;i<students;i++){
        marks[i] = new int[subjects];
    }

    cout << "Enter marks of " << students << " students in " << subjects << " subjects: " << endl;
    for(int i=0;i<students;i++){
        cout << "Student " << i+1 << ":\n";
        for(int j=0;j<subjects;j++){
            cout << " | Subject " << j+1 << ": ";
            cin >> marks[i][j];
        }
    }

    int* studentTotal = new int[students];
    for(int i=0;i<students;i++){
        studentTotal[i] = 0;
        for(int j=0;j<subjects;j++){
            studentTotal[i] += marks[i][j];
        }
    }

    double* subjectAverage = new double[subjects];
    for(int j=0;j<subjects;j++){
        int sum = 0;
        for(int i=0;i<students;i++){
            sum += marks[i][j];
        }
        subjectAverage[j] = (double)sum / students;
    }

    int topperIndex = 0;
    for(int i=1;i<students;i++){
        if(studentTotal[i] > studentTotal[topperIndex]){
            topperIndex = i;
        }
    }

    cout << "\nTotal Marks of Each Student: " << endl;
    for(int i=0;i<students;i++){
        cout << "Student " << i+1 << ": " << studentTotal[i] << endl;
    }
    cout << "\nAverage Marks of Each Subject: " << endl;
    for(int j=0;j<subjects;j++){
        cout << "Subject " << j+1 << ": " << subjectAverage[j] << endl;
    }
    cout << "\nTopper Student: Student " << topperIndex+1 
         << " with total marks = " << studentTotal[topperIndex] << endl;

    for(int i=0;i<students;i++){
        delete[] marks[i];
    }
    delete[] marks;
    delete[] studentTotal;
    delete[] subjectAverage;

    return 0;
