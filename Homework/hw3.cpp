// Andrea M. Stojanovski
// HW3

#include <iostream>

using namespace std;

void greeting(int num) {
  for (int i=0; i<num; i++) { // loops "num" times and prints Hello
    cout << "HELLO \n";
  }
}

int prod(int num1, int num2) {
  int product = num1 * num2; // initialize product and solve
  return product;
}

int Add(int num1, int num2) {
  int sum = num1 + num2; // initialize sum and solve
  return sum;
}

int Div(int num1, int num2) {
  int quotient = num2 / num1; // initialize quotient and solve
  return quotient;
}

int Avg(int num1, int num2, int num3) {
  int average = (num1 + num2 + num3) / 3; // initialize average and solve
  return average;
}

void Halfs(int num) {
  cout << num << endl; // prints original "num"
  while (num > 1) {
    num = num / 2; // modifies "num"
    cout << num << endl; // prints updated "num" 
  }
}

int main() {
  // I added in arbitrary values and made them print so we can observe results
  greeting(4);
  cout << "Product: " << prod(2,3) << endl;
  cout << "Addition: " << Add(2,3) << endl;
  cout << "Division: " << Div(2,6) << endl;
  cout << "Average: " << Avg(2,4,8) << endl;
  Halfs(10);
}

/*
Notes: the task asks to use if statments, switch statements, do-while loops
  this seems unnecesary for the simplicity of the task unless we can to check that inputs are valid, but we have not set a criteria.

  ex: we want the average of exams (other assignment) check that num is 1-100

  if (num > 100 | num < 0) cout << "This is not a valid input";

  ex: we want div to be larger than 0 (meaning num1 must be smaller than num2)

  int diff = num2 - num1;
  do {
    div(num1, num2);
  } while (diff > 0);

  ex: if the person does greeting with 1-3 it will print it a respective number of times
    if the enter anything larger than 3  it will just print "HELLLLLOOOOO!!!" once

  switch (num) {
    case 1:
      greeting(1); // let's say this is in main and we can make a call to greeting
      break;
    case 2:
      greeting(2);
      break;
    case 2:
      greeting(2);
      break;
    default: // this will only occur if the num is not 1-3 (technically if they write 0 this will occur too, but if we want to account for that we can add more cases)
      cout << "" << endl;
      break;
  }

ASSUME THAT THESE CAN BE ADDED IN MAIN GIVEN THEY MAKE CALLS TO THE FUNCTIONS WE DEFINED
*/