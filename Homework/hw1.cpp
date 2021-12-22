//Andrea M. Stojanovski
// HW 1

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int test1, test2, test3;

  // prompt user for inputs
  cout << "Please enter 3 test scores (out of 100): \n";
  cout << "Test 1: ";
  cin >> test1;
  while (true) { // this will make sure that the input is with in range
    if (test1 > 0 && test1 < 101) break; // breaks if they entered a valid input
    cerr << "Invalid Input, must be a value between 0-100 \n"; // display error of invalid input
    cout << "Please try again: ";
    cin >> test1; // re-enter input
  }

  cout << endl << "Test 2: ";
  cin >> test2;
    while (true) { // this will make sure that the input is with in range
    if (test2 > 0 && test2 < 101) break; // breaks if they entered a valid input
    cerr << "Invalid Input, must be a value between 0-100 \n"; // display error of invalid input
    cout << "Please try again: ";
    cin >> test2; // re-enter input
  }

  cout << endl << "Test 3: ";
  cin >> test3;
  while (true) { // this will make sure that the input is with in range
    if (test3 > 0 && test3 < 101) break; // breaks if they entered a valid input
    cerr << "Invalid Input, must be a value between 0-100 \n"; // display error of invalid input
    cout << "Please try again: ";
    cin >> test3; // re-enter input
  }

  int average = (test1 + test2 + test3) / 3; // initialize and calculate average

  cout << "Your average was: " << average << endl;

  if (average == 100) { cout << "You got a perfect score! \n";
  } else if (average < 50) { cout << "You got a terrible score! \n"; 
  }
  
  // in order to use switch we want to use floor division, this gives us the tens value of the average which determines the grade 
  int letter = (average - (average % 10)) / 10;

  switch (letter) {
    case (10): // if they got a perfect score they would get a 10 and we don't want that to go in the default case
      cout << "You got an A. \n";
      break;
    case (9):
      cout << "You got an A. \n";
      break;
    case (8):
      cout << "You got an B. \n";
      break;
    case (7):
      cout << "You got an C. \n";
      break;
    case (6):
      cout << "You got an D. \n";
      break;
    default: // this is anything 0-5 or potentially > 10 *nope this is resolved, check note*
      cout << "You got an F. \n";
      break;
  }
}

/*
Note: If we wanted to make sure that the user is only inputing something 1-100 for the tests we can add the following after promting each input of of test scores

  while (true) { // this will make sure that the input is with in range
    if (test1 > 0 && test < 101) break; // breaks if they entered a valid input
    cerr << "Invalid Input, must be a value between 0-100 \n"; // display error of invalid input
    cout << "Please try again: ";
    cin >> bev; // re-enter input
  }

  THIS HAS BEEN ADDED, HOWEVER IF ONLY THIS IS COMMENTED OUT IT WILL STILL WORK, BUT IT WILL NOT CHECK IF THE SCORES ARE <0 and >100
*/