#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));
    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;

    do {
        cout << "Enter your guess between 1 and 100 : ";
        cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the correct number " << secretNumber << " in " << attempts << " tries!!" <<endl;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." <<endl;
        } else {
            cout << "Too high! Try again." <<endl;
        }

    } while (true);

    return 0;
}