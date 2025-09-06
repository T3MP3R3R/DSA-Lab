#include <iostream>
using namespace std;

class Box {
private:
    int* value;
public:
    Box(int v = 0) {
        value = new int(v);
        cout << "Constructor called. Value = " << *value << endl;
    }
    ~Box() {
        cout << "Destructor called. Deleting value = " << *value << endl;
        delete value;
    }
    Box(const Box& other) {
        value = new int(*other.value);
        cout << "Copy Constructor called. Copied value = " << *value << endl;
    }

    Box& operator=(const Box& other) {
        cout << "Copy Assignment Operator called.\n";
        if (this != &other) {
            delete value;
            value = new int(*other.value);
        }
        return *this;
    }
    void setValue(int v) {
        *value = v;
    }
    int getValue() const {
        return *value;
    }
    void display() const {
        cout << "Value = " << *value << " | Address = " << value << endl;
    }
};

int main() {
    cout << "\n--- Creating box1 ---\n";
    Box box1(10);
    box1.display();

    cout << "\n--- Copying box1 to box2 (Copy Constructor) ---\n";
    Box box2 = box1;
    box2.display();

    cout << "\n--- Modifying box2's value to 20 ---\n";
    box2.setValue(20);
    cout << "box1: ";
    box1.display();
    cout << "box2: ";
    box2.display();

    cout << "\n--- Creating box3 ---\n";
    Box box3(50);
    box3.display();

    cout << "\n--- Assigning box1 to box3 (Copy Assignment) ---\n";
    box3 = box1;
    box3.display();

    cout << "\n--- Modifying box3's value to 30 ---\n";
    box3.setValue(30);
    cout << "box1: ";
    box1.display();
    cout << "box3: ";
    box3.display();
    return 0;
}