#include<iostream>
#include<cstdlib> // Provides rand() and srand() functions.
#include<ctime>   // Provides time() function.
using namespace std;

int main()
{
    srand(time(0));  /*Uses the current time as a seed for the random number generator.
   A seed is an initial value used to generate a sequence of pseudo-random numbers.*/

    int n = rand() % 100 + 1;  // Generate a random number between 1 and 100
    int guess;
    int attempt=0;
    cout<< " enter a number between 1 and 100: ";
    cin>>guess;
    while( guess != n)
    {
        attempt++;
        if ( guess < 1 || guess > 100)
        {
            cout<< " your guess is out of range, try again: ";
        }
        else if(guess < n)
            cout<< " your guess is too low, try again: ";

        else if(guess > n)
            cout<< " your guess is too high, try again: ";

        cin>>guess;
    }
    attempt++;
    cout<< " \n congratulations! you guessed the number " << endl;
    cout<< " \n Total attempts: " << attempt << endl;

    return 0;
}