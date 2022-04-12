// Andrea M. Stojanovski
// OOP HW # 1: Caesar Cypher

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

char charDecryptCaesarCypher(char ch, int steps) { // decrypts by Caesar Cypher
    if (islower(ch)) { // only need to decrypt char if it is lowercase
        ch -= steps;
        if (ch < 'a') {
            ch += 26; // loops back around to lowercase letters
        }
    }
    return ch;
}

void stringDecryptCaesarCypher(string& encryptedStr, int steps) { // will perform the decryption on string by looping through
    for (int i = 0; i < encryptedStr.length(); i++) { // looping through each char of string
        encryptedStr[i] = charDecryptCaesarCypher(encryptedStr[i], steps); // check and decrypts when necessary
    }
}
int main() {
    vector<string> encryptedText; // initialize a vector for encrypted text
    string line;
    ifstream encryptedFile;

    encryptedFile.open("input.txt");
    int steps;

    encryptedFile >> steps;

    while (getline(encryptedFile, line)) { // move in lines of text to vector
        encryptedText.push_back(line);
    }

    for (int i = 0; i < encryptedText.size(); i++) {
        stringDecryptCaesarCypher(encryptedText[i], steps); // decrypting vector of string
    }

    for (int i = encryptedText.size() - 1; i >= 0; i--) {
        cout << encryptedText[i] << endl; // reversing vector by printing from the end to the front
    }
    return 0;
}