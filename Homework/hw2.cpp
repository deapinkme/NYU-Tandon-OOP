// Andrea M. Stojanovski
// HW2

#include <iostream>

using namespace std;

int main() {
  int secret = 6; // initialize and set the secret number
  int guess; // initalize the users guess

  for (int i=0; i <11; i++) {
    if (i == 10) {cout << "Game over! You ran out of tries. \n"; // first check that there are still rounds remaining, if not then the game is over
    } else { // continue if there are rounds remaining
      cout << "Guess the secret number! \n";
      cin >> guess;
      if (guess == secret) { // correct guess
        cout << "Horrayyy! You guessed it! \n";
        cout << "It took " << i+1 << " guesses to win. \n";
        break;
      } else if (guess > secret) { // print when too large
          cout << "Try a smaller number. \n";
      } else if (guess < secret) { // print when too small
          cout << "Try a higher number. \n";
      }
    }
  }
}

/*
NOTE: My program will print "Try a smaller/higher number." right before saying the game is over if the is the users last (tenth) guess. At first I though I should remove that, but I think it is valid that they get feedback of how they were off even in the final round
*/