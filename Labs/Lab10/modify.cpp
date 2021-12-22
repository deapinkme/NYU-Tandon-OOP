//      File name: modify.cpp
// Andrea M. Stojanovski

#include <iostream>
#include <fstream>    // using file input-output
#include <string>      // using islower, toupper
using namespace std;
int main()
{
    // a character variable to read character-by-character
    char c;

    // declare input and output streams
    ifstream inFile;
    ofstream outFile;

    // Problem 2: open input and output files:
    // input file: data.txt, output file: result2.txt
    // inFile.open("data.txt",ios::in);
    inFile.open("bad_data.txt",ios::in);
    outFile.open("result2.txt", ios::out);


    // checking if the files have opened correctly:
    if (!inFile) {
        //print error message to standard error stream:
        cerr << "Can not open input file" << endl;
        exit(1);
    }

    if (!outFile) {
        //print error message to standard error stream:
        cerr << "Can not open output file" << endl;
        exit(1);
    }

    // input-outpur loop goes until the end of file 
    // There is no wrong data for unformatted character-by-character input

    // Problem 2: input a character c using method get(c) in the condition
    // of the while loop: 
    inFile.get(c);
    while (!fin.eof( )) { // c!='\n'
        // if c is a lower-case letter, convert it to upper case
        if (islower(c))
            c = toupper(c);
        // Problem 2: output c to the output file using put(c) method:
        cout.put(c);

    }

    // Problem 2: close input and output files:
    inFile.close();
    outFile.close();

    return 0;
}