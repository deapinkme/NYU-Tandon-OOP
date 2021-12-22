// Andrea M. Stojanovski
// 24

#include <iostream>
#include <fstream>
#include<vector>
using namespace std;

int main() {
// task 1
string tempLine;
getline(infile, tempLine);
size_t i = tempLine.find("sad");

if (i != string::npos)
    tempLine.replace(i, replace.length(), "happy");

// task 2
  // open file in append mode and add Happy Final Exam!
  ofstream fileOUT("text.txt", ios::app);
  fileOUT << "Happy Final Exam!" << endl;
  fileOUT.close();


// task 3
  // copy contents of lower into upper
  ifstream infile("lower.txt");
  ofstream outfile("upper.txt");
  outfile << infile;

  

  // close files
  outfile.close();
  infile.close();
}