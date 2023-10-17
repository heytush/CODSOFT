#include <iostream>

using namespace std;

int main() {
    char operation;
    double num1, num2, result;

    cout << "Enter the First Number: ";
    cin >> num1;

    cout << "Enter the Second Number: ";
    cin >> num2;
    cout << "Choose an Operation (+, -, *, /): ";
    cin >> operation;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } 
            else {
                cout<< "Error: Division by zero is not allowed." <<endl;
                return 1; // Exit the program with an error code
            }
            break;
        default:
            cout << "Error: Invalid Operator." << endl;
            return 1; // Exit the program with an error code
    }

    cout <<num1<<" "<<operation<<" "<<num2 <<" = "<<result<<endl;

    return 0;
}