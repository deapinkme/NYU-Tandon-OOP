// Andrea Morgan Stojanovski
// Object Oriented Programing
// Lab #1
// 31 January 2020

// includes:
#include<iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


int main() { // Hello Program that does not include return statetments
// Hello world:
	cout << "Hello" << endl;
	// this would not return anything

	// modified Hello World
	// this required the <iosteam> to be included
	// iostream is included globally, therefore we od not write it inside main
	std::cout << "Hello" << endl; // the std:: is a qualifier

	cout << "Hello" << endl;
	// this is faster because you don't need to write std::

// Static Typing and Defining Variables

	int x; // if x is not initialized then it will have an undefined and unpredictable behavior
	cout << "x: " << x << endl;

	int x; // setting x = "felix";  causes a compilation error as we assigned x to have a type int
	int y = 17;
	int z = 2000000017; // 2 billion and 7
	double pie = 3.14159;
	// z takes up the most space considering the 32-bit value of approximately 2 billion
	cout << sizeof(x) << endl;
	cout << sizeof(y) << endl;
	cout << sizeof(z) << endl;
	cout << sizeof(pie) << endl;
	// the sizes are being tested and outputed to the consol


// Conditions

	int x;
	if (x >= 10 && x <= 20) { // check if x is larger than 10 and smaller than 20
		// if (x <= 20) check if x is smaller than 20 (second condition) can use nested if or &&
		cout << "x is between 10 and 20 inclusively" << endl;
	}


	// Looping

		// for loop
	int end_val = 20;
	int start_val = 10;
	for (int i = start_val; i < end_val; i++) {// we are starting with 10, incrementing and ending with 20
		cout << i << endl; // here we print each value of i on a separate line
	}


	// while loop
	int i = 10; // staring value of i is 10
	int max = 20; // set max to 20 so there are no seeming random numbers in code
	while (i <= max) { // includes 20
		cout << "i: " << i << endl; // each value of i will be outputed to consol on a separate line
		++i; // increment i
	}


	// do-while loop
	int i = 10;
	int max = 20;
	do {
		cout << "i: " << i << endl; // again outputs values of i on separate lines
		++i;
	} while (i <= max); // includes 20

	// loop to open file
	string file_name; // make a string for the file name
	cin >> file_name; // ask user to input file name

	ifstream ifs;
	while (!ifs) {
		cerr << "Could not open the file." << endl;
		exit(1);
		cin >> file_name; // ask to input another file name
	}

	//reading file word by word
	string word;
	while (ifs >> word) { // while there are more white space delimted tokens (or words)
		ifs >> word; // take the next word
		cout << word << endl; // output the next word to consol
	}
	ifs.close(); // close file

// Vectors

	vector<int> vector_of_ints{};

	int i = 10; // staring value of i is 10
	int max = 100; // set max to 100
	while (i <= max) { // includes 100
		vector_of_ints.push_back(i); // push in values of i into vector
		++i; // increment i
	}

 	for (int i = 0; i < vector_of_ints.size(); ++i) {
		cout << vector_of_ints[i] << endl;
	}

	// loop by range for
	for (int x : vector_of_ints) {
		cout << x << endl;
	}

	// loop in reverse
	for (int i = vector_of_ints.size() - 1; i >= 0; --i) {
		cout << vector_of_ints[i] << endl;
	}

	vector<int> prime_vector;

	int i = 1;
	while (i < 20) {
		int j = 1;
		while (j <= i);
	}

// Functions

	// display vector of ints
	int vector_display (int vec){
		for (int i = 0; i < vector_of_ints.size(); ++i) {
			cout << vector_of_ints[i] << endl;
		}
	}
}