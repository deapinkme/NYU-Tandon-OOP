//Andrea M. Stojanovski
// Lab 1

#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;


void calculatorIF() {
	char op;
	float num1;
	float num2;
  float res;

	cout << "Enter operator (+,-,*,/): \n";
	cin >> op;

	cout << "Enter first number: \n";
	cin >> num1;

	cout << "Enter second number: \n";
	cin >> num2;

	if (op == '+') { res = (num1 + num2);
  } else if (op == '-') { res = (num2 - num1);
  } else if(op == '*') { res = (num1 * num2);
  } else if(op == '/') { res = (num2 / num1);
  }

  cout << "Solution: " << res << endl;
}

void calculatorSWITCH() {
  char op;
	float num1;
	float num2;
  float res;

	cout << "Enter operator (+,-,*,/): \n";
	cin >> op;

	cout << "Enter first number: \n";
	cin >> num1;

	cout << "Enter second number: \n";
	cin >> num2;

  switch (op) {
  case '+':
    res = (num1 + num2);
    break;

  case '-':
    res = (num2 - num1);
    break;

  case '*':
    res = (num1 * num2);
    break;

  case '/':
    res = (num2 / num1);
    break;
  // no default because the input should fall in the above
}
  cout << "Solution: " << res << endl;
}

int main() {
	calculatorIF();
  calculatorSWITCH();
}
/*
Note: In this program we are not checking if the inputs are valid. However if we would like to do so...

  ex: checking the operator

  while (true) {
    if (op == '+'||op == '-'||op == '*'||op == '/') break; // breaks if they entered a valid input
    cerr << "Invalid Input, must enter valid operation \n"; // display error of invalid input
    cout << "Please try again: ";
    cin >> op; // re-enter input
  } 

  ex: checking that num1 is a number

  while (true) {
    if (float(num1) == num1) break; // breaks if they entered a valid input
    cerr << "Invalid Input, must enter number \n"; // display error of invalid input
    cout << "Please try again: ";
    cin >> num1; // re-enter input
  }

  ex: checking that num2 is a number

  while (true) {
    if (float(num2) == num2) break; // breaks if they entered a valid input
    cerr << "Invalid Input, must enter number \n"; // display error of invalid input
    cout << "Please try again: ";
    cin >> num2; // re-enter input
  } 

*/