#include<iostream>
#include<cstdlib> // Provides rand() and srand() functions.
#include<ctime>   // Provides time() function.
using namespace std;

int main(){
    srand(time(0));  /*Uses the current time as a seed for the random number generator.
   A seed is an initial value used to generate a sequence of pseudo-random numbers.*/
    
    int guess;
    int attempt=0;
    int score=0;
    int choice;
    int maxNumber;
    int lives;
    char playAgain;

    do {
        // Reset values for a new game
        attempt = 0;
        score = 0;

        // Difficulty level menu
        cout << "\nWelcome to the Number Quest!\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "\nChoose a difficulty level (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Easy level selected!\n";
                maxNumber = 50;
                lives = 10;
                break;

            case 2:
                cout << "Medium level selected!\n";
                maxNumber = 100;
                lives = 7;
                break;

            case 3:
                cout << "Hard level selected!\n";
                maxNumber = 200;
                lives = 5;
                break;

            default:
                cout << "Invalid choice!\n";
                return 0;
        }

        // Generate random number
        int n = rand() % maxNumber + 1;

        cout << "\nEnter a number between 1 and " << maxNumber << ": ";
        cin >> guess;

        // Guessing loop
        while (guess != n && lives > 0) {

            if (guess < 1 || guess > maxNumber) {
                cout << "Your guess is out of range, try again: ";
                cin >> guess;
            }
            else {
                attempt++;

                if (guess < n) {
                    cout << "Your guess is too low, try again: ";
                }
                else if (guess > n) {
                    cout << "Your guess is too high, try again: ";
                }

                lives--;

                cout << "\nRemaining lives: " << lives << endl;

                if (lives > 0) {
                    cin >> guess;
                }
            }
        }

        // Winning or Game Over
        if (guess == n) {
            attempt++;

            cout << "\nYou won!";
            cout << "\nCongratulations! You guessed the number.\n";

            if (attempt == 1) {
                score = 100;
            }
            else if (attempt == 2) {
                score = 80;
            }
            else if (attempt == 3) {
                score = 60;
            }
            else if (attempt == 4) {
                score = 40;
            }
            else if (attempt == 5) {
                score = 20;
            }
            else {
                score = 10;
            }
        }
        else {
            cout << "\nGame Over!";
            cout << "\nThe secret number was: " << n << endl;
        }

        // Final results
        cout << "\nTotal attempts: " << attempt << endl;
        cout << "Remaining lives: " << lives << endl;
        cout << "Your score: " << score << endl;

        // Play again option
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing!\n";

    return 0;
}
