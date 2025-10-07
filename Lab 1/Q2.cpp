#include <iostream>
#include <string>
using namespace std;

class Exam {
private:
    string studentName;
    string examDate;
    float score;

public:
    Exam(string name, string date, float s) {
        studentName = name;
        examDate = date;
        score = s;
    }

    void setStudentName(string name) {
        studentName = name;
    }

    void setExamDate(string date) {
        examDate = date;
    }

    void setScore(float s) {
        score = s;
    }

    void display() const {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }
};

int main() {
    Exam exam1("Alice", "2025-09-01", 85.5);
    cout << "Original Exam1 details:\n";
    exam1.display();

    Exam exam2 = exam1;
    cout << "\nCopied Exam2 details:\n";
    exam2.display();

    exam2.setStudentName("Bob");
    exam2.setExamDate("2025-09-02");
    exam2.setScore(92.0);

    cout << "\nAfter modifying Exam2:\n";
    cout << "Exam2 details:\n";
    exam2.display();

    cout << "\nExam1 details (after modifying Exam2):\n";
    exam1.display();
    return 0;

}
