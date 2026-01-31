// /*
//     Title: Student Management System
//     Language: C++
//     Description:
//     A menu-driven console application developed to manage
//     student records using object-oriented programming.
//     The project is under progressive development.
// */

#include<iostream>
#include<limits>
#include<string>
#include<algorithm>
using namespace std;
int getValidatedInt();
string uppercase(string s);
class Student{
    private:
    string name;
    int rollno;
    string degree;
    string hostel;
    float cgpa;
    public:
    void addDetails();
    void updateDetails();
    void updateCGPA();
    void updateHostel(); 
    void display();
    int getrollno();
};
int Student:: getrollno(){
    return rollno;
}
void Student::addDetails(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter roll no: ";
    rollno = getValidatedInt();
    while (rollno < 0) {
    cout << "Roll number cannot be negative. Enter again: ";
    rollno = getValidatedInt();
}

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter degree: ";
    getline(cin, degree);

    cout << "Enter hostel: ";
    getline(cin, hostel);

    cout << "Enter CGPA: ";
    cin >> cgpa;

    while (cgpa < 0 || cgpa > 10) {
        cout << "Invalid CGPA. Enter again: ";
        cin >> cgpa;
    }
}

void Student::display() {
    cout << "\nStudent Details:\n";
    cout << "Name: " << uppercase(name) << "\n";
    cout << "Roll No: " << rollno << "\n";
    cout << "Degree: " << uppercase(degree) << "\n";
    cout << "Hostel: " << uppercase(hostel) << "\n";
    cout << "CGPA: " << cgpa << "\n";
}
void Student::updateDetails() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter new name: ";
    getline(cin, name);

    cout << "Enter new degree: ";
    getline(cin, degree);

    cout << "Enter new hostel: ";
    getline(cin, hostel);

    cout << "Enter new CGPA: ";
    cin >> cgpa;

    while (cgpa < 0 || cgpa > 10) {
        cout << "Invalid CGPA. Enter again: ";
        cin >> cgpa;
    }

    cout << "Details updated successfully!\n";
}

void Student::updateCGPA(){
    cout<<"Enter new CGPA:";
    cin>>cgpa;

    while (cgpa < 0 || cgpa > 10) {
    cout << "Invalid CGPA. Enter again: ";
    cin >> cgpa;
    }
}
void Student::updateHostel(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter new hostel: ";
    getline(cin, hostel);
}
int getValidatedInt(){
    int value;
    while(true){
        cin >> value;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<("Invalid Input.Enter an Integer:");
        }else{
            return value;
        }
    }
}
string uppercase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}
int main(){
const int MAX=100;
Student students[MAX];
int option;
int count=0;
do{
cout << "\n\nYou can do the following:\n";
cout << "Enter appropriate number\n";
        cout<<"\n1 : Add New Student.";
        cout<<"\n2 : Update Details.";
        cout<<"\n3 : Update CGPA.";
        cout<<"\n4 : Update Hostel.";
        cout<<"\n5 : Display Details.";
        cout<<"\n6 : Quit.";
        cout<<"\nEnter Your Option.";
        option=getValidatedInt();
        switch(option){
            case 1:{
            if(count<100){
                students[count].addDetails();
                count++;
            }
            else{
                cout<<"Students limit reached...";
            }
            break;
            }

            case 2:{
            int rollno;
            cout<<"Enter roll no:";
            rollno = getValidatedInt();
            while (rollno < 0) {
            cout << "Roll number cannot be negative. Enter again: ";
            rollno = getValidatedInt();
}
            bool found=false;
            for(int i=0;i<count;++i){
                if(students[i].getrollno()==rollno){
                    students[i].updateDetails();
                    found=true;
                    break;
                }
                }
            if(!found){
                cout<<"Student not found...";
            }
            break;
            }

            case 3:{
            int rollno;
            cout<<"Enter roll no:";
            rollno = getValidatedInt();
            while (rollno < 0) {
            cout << "Roll number cannot be negative. Enter again: ";
            rollno = getValidatedInt();
}
            bool found=false;
            for(int i=0;i<count;++i){
                if(students[i].getrollno()==rollno){
                    students[i].updateCGPA();
                    found=true;
                    break;
                }
                }
            if(!found){
                cout<<"Student not found...";
            }
            break;
            }
            case 4:{
            int rollno;
            cout<<"Enter roll no:";
            rollno = getValidatedInt();
            while (rollno < 0) {
            cout << "Roll number cannot be negative. Enter again: ";
            rollno = getValidatedInt();
}
            bool found=false;
            for(int i=0;i<count;++i){
                if(students[i].getrollno()==rollno){
                    students[i].updateHostel();
                    found=true;
                    break;
                }
                }
            if(!found){
                cout<<"Student not found...";
            }
            break;
            }
            case 5:{
            int rollno;
            cout<<"Enter roll no:";
            rollno = getValidatedInt();
            while (rollno < 0) {
            cout << "Roll number cannot be negative. Enter again: ";
            rollno = getValidatedInt();
}
            bool found=false;
            for(int i=0;i<count;++i){
                if(students[i].getrollno()==rollno){
                    students[i].display();
                    found=true;
                    break;
                }
                }
            if(!found){
                cout<<"Student not found...";
            }
            break;
            }

            case 6:
                cout<<"Exiting program...";
            
            break;
            default: cout<<"Input Error ,Try Again....";

        }
}
while(option!=6);
    return 0;
}
