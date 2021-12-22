// Andrea M. Stojanovski
// HW4

#include <iostream>

using namespace std;

void sortDesc(int arr[]) {
  for (int i=0; i<10-1; i++) {
    for (int j=i+1; j<10; j++) {
      if (arr[i] < arr[j]) {
        // swap them
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    cout << arr[i] << ", ";
  }
  cout << arr[9] << endl;
}

int main() {
  int Numbers[10];
  int temp;

  for (int i=0; i< 10; i++) {
    cout << "Please enter integer: \n";
    cin >> temp;
    cout << endl;
    Numbers[i] = temp;
  }
  
  // check for duplicates

  int max = -2147483647; // int minimum so that we can replace it with max
  int min = 2147483647; // int maximum so that we can replace it with min
  for (int i=0; i<10; i++) { // loop through all of the array
    if (Numbers[i] < min) min = Numbers[i]; // set new min
    if (Numbers[i] > max) max = Numbers[i]; // set new max
  }

  cout << "The smallest element in Numbers is: " << min << endl;
  cout << "The largest element in Numbers is: " << max << endl;

  sortDesc(Numbers);
  
  // cout << Numbers[0] << endl; // testing what Numbers looks like after sortDesc
  
  int uNum;

  cout << "What number would you like to search for? ";
  cin >> uNum;
  cout << endl;

  for (int i=0; i<11; i++) { // loop through array to check for number
    if (i == 10) { cout << "Not found. \n"; // in this case we've gone though it all and have not found it.
    } else if (uNum == Numbers[i]) {
        cout << "Found at index: " << i;
        break;
    }
  }
}

/*
Note: I would make sortDesc take two arguements, the array and the size of the array, seeing as we hard coded Numbers to be 10, I did the same for sortDesc, however this is poor practice, I would define a variable for the size ex: size_arr and set that to 10.

I also see that sortDesc does not return anything, however it will modify Numbers to be in descending order.
*/
