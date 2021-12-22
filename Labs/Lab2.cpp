// Andrea M. Stojanovski
// Lec 2

#include <iostream>
using namespace std;


int main() {
  while (true) { // remove while loop and it will only do this once
    int x;
    cout << "Enter number" << endl;
    cin >> x;
    if (0 == x % 2) cout << "Even" << endl;
    else cout << "Odd" << endl;
  }
}

/*
Note: I noticed if the number entered is very large (I tried with 15-20 digits) or an unexpected symbol it will cause an infinite loop of odd/even and enter number being printed. Otherwise this works.

ex:
#include <string>

str = to_string(x); // converts x to string
for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false) // checks that all placevalues are valid digits
         cout << "NOT VALID! \n"; // found invalid character 
    // otherwise continue with code to check parity of x (line 13)

*/