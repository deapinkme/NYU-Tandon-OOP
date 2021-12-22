// Andrea M. Stojanvoski
// Lab 4

#include <iostream>
#include<string>

using namespace std;

int main() {
  string first, last, full;

  cout << "Enter first name: ";
  cin >> first;
  cout << endl << "Enter last name: ";
  cin >> last;

  full = first + " " + last;
  cout << "Full name: " << full << endl;

  for (int i=0; i<full.length(); i++) {
    switch (full[i]) {
      case 'a': // lower cases
        full[i] = 'z';
        break;
      case 'e':
        full[i] = 'z';
        break;
      case 'i':
        full[i] = 'z';
        break;
      case 'o':
        full[i] = 'z';
        break;
      case 'u':
        full[i] = 'z';
        break;
      case 'A': // capitals
        full[i] = 'z';
        break;
      case 'E':
        full[i] = 'z';
        break;
      case 'I':
        full[i] = 'z';
        break;
      case 'O':
        full[i] = 'z';
        break;
      case 'U':
        full[i] = 'z';
        break;
      // otherwise do nothing
    }
  }
  cout << "I replaced the vowels: " << full << endl;

  full = first + " " + last; // restore full to orginial (no extra z's)

  cout << "Let's reverse it: ";
  for (int i=full.length(); i>-1; i--) {
    cout << full[i]; // no new line so it looks like its one word
  }
  cout << endl;
}

/*
Note: There is better ways to check if the characters are vowels and replace them, in python we can check if a character is in a list of characters. This could have also been done with if statements instead of switch.

ex:
  if (full[i] == 'a' || full[i] == 'e' || full[i] == 'i' || full[i] == 'o' || full[i] == 'u' || full[i] == 'A' || full[i] == 'E' || full[i] == 'I' || full[i] == 'O' || full[i] == 'U') full[i] = z;

  This is also pretty messy though (visually).
*/