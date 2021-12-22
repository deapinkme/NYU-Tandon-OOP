// Andrea M. Stojanovski
// Lab 6

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// PART 1

void print_one(const int * arr, int size_arr) {
  cout << "The elements of the array are: " << endl;
  for (int i=0; i<size_arr; i++) {
    cout << "Element ";
    cout << arr[i];
    cout << " is located at ";
    cout << &arr[i] << endl;
  }
}

void print_two(const int *arr, int size_arr) {
  cout << "The elements of the array are: " << endl;
  for (int i=0; i<size_arr; i++) {
    cout << "Element ";
    cout << *(arr + i);
    cout << " is located at ";
    cout << arr + i << endl;
  }
}

int * product(const int *arr1, int size_arr1, const int *arr2, int size_arr2) {
  int *arr {new int[size_arr1 * size_arr2] {}};
  int pos{0};
  for (int i{0}; i < size_arr2; i++) {
    for (int j{0}; j < size_arr1; j++) {
      arr[pos] = arr1[j] *arr2[i];
      pos++;
    }
  }
  return arr;
}

// PART 3

string get_secret_message(string secret_message = "") { // if they don't pass something, it is nothing
  while (secret_message.empty()){
    cout << "Please reenter a secret message: ";
    cin >> secret_message;
    cout << endl;
  }
  return secret_message; // makes sure it isn't empty
}

void encode_message(string alphabet, string secret_message, string key="XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr") {
  // we can make the alphabet default too, however maybe they want to use a different alphabet, in which case the key length might not match but I was told not to make alphabet defualt
  for (int i=0; i<secret_message.length(); i++) {
    if (secret_message[i] == alphabet[alphabet.find(secret_message[i])]) secret_message[i] = key[alphabet.find(secret_message[i])];
  }
}

void decode_message(string alphabet, string secret_message, string key="XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr") {
  for (int i=0; i<secret_message.length(); i++) {
    if (secret_message[i] == key[key.find(secret_message[i])]) secret_message[i] = alphabet[key.find(secret_message[i])];
  }
}

void change_key(string& key) {
  key = key.substr(0, key.length()/2) + key.substr((key.length()/2)+1, key.length());
}

int main() {

  // PART 1
  cout << "PART 1" << endl;

  int *arr1 = {new int[5] {1, 2, 3, 4, 5}};
  int *arr2 = {new int[3] {10, 20, 30}};

  const int size_one = 5;
  const int size_two = 3;

  print_one(arr1, size_one);
  cout << endl;
  print_two(arr2, size_two);
  cout << endl;

  print_one(product(arr1, size_one, arr2, size_two), size_one * size_two);
  
  cout << endl;
  // PART 2
  cout << "PART 2" << endl;

  vector<int> vec1;
  vector<int> vec2;

  vec1.push_back(10);
  vec1.push_back(20);

  cout << "Vector 1: ";

  for (int i{0}; i < vec1.size(); i++) {
    cout << vec1.at(i) << " ";
  }

  cout << endl << "The size of vector 1 is: " << vec1.size() << endl;

  vec2.push_back(100);
  vec2.push_back(200);
  
  cout << "Vector 2: ";

  for (int i{0}; i < vec2.size(); i++) {
    cout << vec2.at(i) << " ";
  }
  cout << endl;

  vec2.assign({333,777,888});

  cout << "Vector 2: ";

  for (int i{0}; i < vec2.size(); i++) {
    cout << vec2.at(i) << " ";
  }
    cout << endl << "The size of vector 2 is: " << vec2.size() << endl;

  vector<vector<int>> vec_2d;
  vec_2d.push_back(vec1);
  vec_2d.push_back(vec2);

  cout << "vec_2d: " << endl;

  for (int i = 0; i < vec_2d.size(); i++) {
    for (int j = 0; j < vec_2d[i].size(); j++) {
      cout << vec_2d.at(i).at(j) << " ";
    }
    cout << endl;
  }

  vec1.at(0) = 1000;

  cout << "vec_2d: " << endl;

  for (int i = 0; i < vec_2d.size(); i++) {
    for (int j = 0; j < vec_2d[i].size(); j++) {
      cout << vec_2d.at(i).at(j) << " ";
    }
    cout << endl;
  }

  cout << "Vector 1: ";

  for (int i{0}; i < vec1.size(); i++) {
    cout << vec1.at(i) << " ";
  }

  cout << endl << "The size of vector 1 is: " << vec1.size() << endl;

  auto second_elem = vec2.begin() + 1;
  vec2.insert(second_elem, 555);

  cout << "Vector 2: ";

  for (int i{0}; i < vec2.size(); i++) {
    cout << vec2.at(i) << " ";
  }

  cout << endl << "The size of vector 1 is: " << vec1.size() << endl;
  cout << endl << "The size of vector 2 is: " << vec2.size() << endl;

  cout << endl << "The capacity of vector 1 is: " << vec1.capacity() << endl;
  cout << endl << "The capacity of vector 2 is: " << vec2.capacity() << endl;

  vec1.clear();
  vec2.clear();

  vec1.resize(0);
  vec2.resize(0);

  cout << endl << "The size of vector 1 is: " << vec1.size() << endl;
  cout << endl << "The size of vector 2 is: " << vec2.size() << endl;

  cout << endl << "The capacity of vector 1 is: " << vec1.capacity() << endl;
  cout << endl << "The capacity of vector 2 is: " << vec2.capacity() << endl;

  cout << endl;
  // PART 3
    cout << "PART 3" << endl;

  // GIVEN:
  string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string key = "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr";
  string secret_message = "My name is Andrea";

  encode_message(alphabet, secret_message, key);
  cout << secret_message << endl;
  decode_message(alphabet, secret_message, key);
  cout << secret_message << endl;



  // PART 4
  cout << "PART 4" << endl;
  cout << "I will submit this seperately! \n";
}