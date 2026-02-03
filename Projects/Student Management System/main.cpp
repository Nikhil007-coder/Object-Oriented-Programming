// /*
//     Title: Student Management System
//     Language: C++
//     Description:
//     A menu-driven console application developed to manage
//     student records using object-oriented programming.
//     The project is under progressive development.
// */

#include <iostream>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

// Function declarations
int getValidatedInt();
float getValidatedFloat();
int getValidatedRollNo();
string uppercase(string s);

// Student class
class Student {
private:
    string name;
    int rollno;
    string degree;
    string hostel;
    float cgpa;

public:
    void addDetails(Student students[],int count);
    void updateDetails();
    void updateCGPA();
    void updateHostel();
    void display();
    int getrollno();
};

// Getter
int Student::getrollno() {
    return rollno;
}

// Add student details
void Student::addDetails(Student students[], int count)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter name: ";
    getline(cin, name);

    rollno = getValidatedRollNo();
    for(int i=count-1;i>=0;i--){
        if(students[i].getrollno()==rollno){
            cout<<"Roll No. Already Exists"<<endl;
            rollno = getValidatedRollNo();
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter degree: ";
    getline(cin, degree);

    cout << "Enter hostel: ";
    getline(cin, hostel);

    cout << "Enter CGPA: ";
    cgpa = getValidatedFloat();

    while (cgpa < 0 || cgpa > 10) {
        cout << "Invalid CGPA. Enter again: ";
        cgpa = getValidatedFloat();
    }
}


// Display details
void Student::display() {
    cout << "\nStudent Details:\n";
    cout << "Name: " << uppercase(name) << "\n";
    cout << "Roll No: " << rollno << "\n";
    cout << "Degree: " << uppercase(degree) << "\n";
    cout << "Hostel: " << uppercase(hostel) << "\n";
    cout << "CGPA: " << cgpa << "\n";
}


// Update all details
void Student::updateDetails() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter new name: ";
    getline(cin, name);

    cout << "Enter new degree: ";
    getline(cin, degree);

    cout << "Enter new hostel: ";
    getline(cin, hostel);

    cout << "Enter new CGPA: ";
    cgpa = getValidatedFloat();

    while (cgpa < 0 || cgpa > 10) {
        cout << "Invalid CGPA. Enter again: ";
        cgpa = getValidatedFloat();
    }

    cout << "Details updated successfully!\n";
}

// Update CGPA only
void Student::updateCGPA() {
    cout << "Enter new CGPA: ";
    cgpa = getValidatedFloat();

    while (cgpa < 0 || cgpa > 10) {
        cout << "Invalid CGPA. Enter again: ";
        cgpa = getValidatedFloat();
    }
}

// Update hostel only
void Student::updateHostel() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter new hostel: ";
    getline(cin, hostel);
}

// Integer validation
int getValidatedInt() {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input. Enter an Integer: ";
        } else {
            return value;
        }
    }
}

// Roll number validation
int getValidatedRollNo() {
    int rollno;
    cout << "Enter roll no: ";
    rollno = getValidatedInt();

    while (rollno < 0) {
        cout << "Roll number cannot be negative. Enter again: ";
        rollno = getValidatedInt();
    }

    return rollno;
}

// Float validation
float getValidatedFloat() {
    float value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input. Enter a number: ";
        } else {
            return value;
        }
    }
}

// Convert string to uppercase
string uppercase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

// Main function
int main() {
    const int MAX = 100;
    Student students[MAX];
    int count = 0;
    int option;

    do {
        cout << "\n\nYou can do the following:\n";
        cout << "Enter appropriate number\n";
        cout << "\n1 : Add New Student";
        cout << "\n2 : Update Details";
        cout << "\n3 : Update CGPA";
        cout << "\n4 : Update Hostel";
        cout << "\n5 : Display Details";
        cout << "\n6 : Quit";
        cout << "\nEnter Your Option: ";

        option = getValidatedInt();

        switch (option) {

        case 1:
            if (count < MAX) {
                students[count].addDetails(students,count);
                count++;
            } else {
                cout << "Student limit reached...";
            }
            break;

        case 2: {
            int rollno = getValidatedRollNo();
            bool found = false;

            for (int i = 0; i < count; i++) {
                if (students[i].getrollno() == rollno) {
                    students[i].updateDetails();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found...";
            break;
        }

        case 3: {
            int rollno = getValidatedRollNo();
            bool found = false;

            for (int i = 0; i < count; i++) {
                if (students[i].getrollno() == rollno) {
                    students[i].updateCGPA();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found...";
            break;
        }

        case 4: {
            int rollno = getValidatedRollNo();
            bool found = false;

            for (int i = 0; i < count; i++) {
                if (students[i].getrollno() == rollno) {
                    students[i].updateHostel();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found...";
            break;
        }

        case 5: {
            int rollno = getValidatedRollNo();
            bool found = false;

            for (int i = 0; i < count; i++) {
                if (students[i].getrollno() == rollno) {
                    students[i].display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found...";
            break;
        }

        case 6:
            cout << "Exiting program...";
            break;

        default:
            cout << "Invalid option. Try again.";
        }

    } while (option != 6);

    return 0;
}
