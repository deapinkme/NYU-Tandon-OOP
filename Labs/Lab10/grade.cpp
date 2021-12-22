// grade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Andrea M. Stojanovski

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    //string to store username
    string username;  
    // integer to store the score
    int score;

    //declare input and output streams
    ifstream inFile;
    ofstream outFile;

    // open input and output files:
    // Problem1: open inFile to read from the file "data":
    inFile.open("data.txt",ios::in);

    // problem1: open outFile to write to the file "result":   
    outFile.open("result.txt", ios::out);

    // checking if the files have opened correctly:
    if (!inFile.is_open()) {
        //print error message to standard error stream:
        cerr << "Can not open input file" << endl;
        exit(1);
    }


    if (!outFile.is_open()) {
        //print error message to standard error stream:
        cerr << "Can not open output file" << endl;
        exit(1);
    }

    // input-outpur loop goes until the end of file or until wrong data
    while (inFile >> username >> score) {
        // Exercise 1: write to the output file 
        // the same username and the score increased by 10: 
        outFile << username << " " << score + 10 << endl;
        
    }

    // Problem 1: close both the input and the output files
    inFile.close();
    outFile.close();

    return 0;
}