#include <iostream>
#include <string>
using namespace std;

/*
    Class: Product
    Demonstrates friend function and menu-driven program
*/
class Product {
private:
    string name;
    float price;
    float discount_percentage;

    // Friend function declaration
    friend float applyDiscount(Product);

public:
    // Function to take product details
    void getData() {
        cin.ignore();
        cout << "Enter product name: ";
        getline(cin, name);

        cout << "Enter price before discount: ";
        cin >> price;

        cout << "Enter discount percentage: ";
        cin >> discount_percentage;
    }

    // Function to display product details
    void display() {
        cout << "\nProduct Name : " << name << endl;
        cout << "Original Price : " << price << endl;
        cout << "Discount (%) : " << discount_percentage << endl;
        cout << "Final Price After Discount : "
             << applyDiscount(*this) << endl;
    }
};

/*
    Friend Function
    Calculates discounted price
*/
float applyDiscount(Product p) {
    return p.price - (p.price * p.discount_percentage / 100);
}

int main() {
    Product p;
    int choice;

    do {
        cout << "\n------ MENU ------\n";
        cout << "1. Enter Product Details\n";
        cout << "2. Display Product Details\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.getData();
                break;

            case 2:
                p.display();
                break;

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
