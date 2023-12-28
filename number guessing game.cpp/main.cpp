
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed for generating random numbers
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100

    int guess;
    int attempts = 0;

    cout << "------------------------------------" << endl;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "------------------------------------" << endl;
    cout << endl;

    do {
        // Ask the user to guess the number
        cout << "Enter your guess (between 1 and 100): ";
        cin >> guess;

        // Check if the guess is too high, too low, or correct
        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts + 1 << " attempts." << endl;
        }

        attempts++;

    } while (guess != secretNumber);

    return 0;
}
