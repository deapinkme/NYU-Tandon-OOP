// Andrea M. Stojanovski
// Lab 5

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void inputInfo(struct student* arr);
void updateInfo(struct student* arr);
void displayInfo(struct student* arr);

// Creating heap and stack variables;

int intValidation(double x){
    // reading in a double at first
    // double x; // redefinition of x
    while (1) {
        cin >> x;
        // checking if there are decimal values in x
        // if not, x is an integer
        if (floor(x) == ceil(x)){
            int y = x;
            return x;
        }
        // if yes, x is an double not an integer
        else{
            cout << "Invalid Input! Please input a integer." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

int numValidation(double x){
    // double x; // redefinition of x
    while (1) {
    // Checks if reading in a double creates an error or not
    // if true, it means we read in a valid number
    if (cin >> x) { 
        return x;
    }
    // if false, it means we cannot read in the input, meaning input 
    // is not a valid number
    else{
        cout << "Invalid Input! Please input a numerical value." << endl;
        // clear cin error flag
        cin.clear();
        // ignore 10000 characters until newline
        cin.ignore(10000, '\n');
        }
    }
}

struct student {
    int ID;
    string Name;
    string Email;
    string Phone;
    double GPA;
    int Age;
};

void inputInfo(struct student* arr) {
    cout << "*******Adding new student info" << endl;
    for (student* p = arr; p < arr + 5; ++p) {
        if (p->ID != NULL) { // this gives a warning
            cout << "Array is full!";
            break;
            // as an improvement, perhaps we can resize the array here
        }

        cout << "ID: ";
        int id;
        cin >> id;
        id = intValidation(id);
        while (p->ID == id) {
            cout << "Enter unique new ID: ";cin >> p->ID;
        }
        p->ID = id;
        cout << "Name: ";
        cin >> p->Name;
        cout << "Age: ";
        cin >> p->Age;
        cout << "Email: ";
        cin >> p->Email;
        cout << "Phone: ";
        cin >> p->Phone;
        cout << "GPA: ";
        cin >> p->GPA;
        break;
    }
    cout << " New Student added successfully" << endl;
}

void updateInfo(struct student* arr) {
    cout << "*********Updating student info" << endl;
    int id;
    cout << "Enter student ID for update : ";
    cin >> id;
    id = intValidation(id);

    for (student* p = arr; p < arr + 5; ++p)
    {
        if (p->ID == id)
        {
            cout << "new ID: ";
            cin >> p->ID;
            cout << endl << "new Name: ";
            cin >> p->Name;
            cout << endl << "new Age: ";
            cin >> p->Age;
            cout << endl << "new Email: ";
            cin >> p->Email;
            cout << endl << "new Phone: ";
            cin >> p->Phone;
            cout << endl << "new GPA: ";
            cin >> p->GPA;
            cout << endl << " Student info updated successfully" << endl;
        }
        else {
            cout << "Student record does not exist" << endl;
            break;
        }
    }

}
void displayInfo(struct student* arr)
{
    cout << "*************Getting student info" << endl;
    int id;
    cout << "Enter student ID for info : ";
    cin >> id;
    id = intValidation(id);

    for (student* p = arr; p < arr + 5; ++p)
    {
        if (p->ID == id)
        {
            cout << "ID: " << p->ID << endl;
            cout << "Name: " << p->Name << endl;
            cout << "Age: " << p->Age << endl;
            cout << "Email: " << p->Email << endl;
            cout << "Phone: " << p->Phone << endl;
            cout << "GPA: " << p->GPA << endl;
        }
        else {
            cout << "Student record does not exist" << endl;
            break;
        }
    }

}
int main()
{
    student arr[100];
    int op;
    do {
        cout << "Enter 1 to add a new student" << endl;
        cout << "Enter 2 to view info of a student" << endl;
        cout << "Enter 3 to update info of a student" << endl;
        cout << "Enter 4 to Exit" << endl;

        cin >> op;

        while ((op != 1) && (op != 2) && (op != 3) && (op != 4)) {

            cout << "Invalid input" << endl;
            cout << "Enter 1 to add a new student" << endl;
            cout << "Enter 2 to view info of a student" << endl;
            cout << "Enter 3 to update info of a student" << endl;
            cin >> op;
        }
        if (op == 1) {
            inputInfo(arr);
        }
        else if (op == 2) {
            displayInfo(arr);
        }
        else if (op == 3) {
            updateInfo(arr);
        }
        else if (op == 4) {
            cout << "good bye! \n";
        } else {cout << endl << "Invalid input. Enter 1-4. \n"; } // kind of like validation for menu cases
    } while (op != 4);

    cin.get();
    return 0;
}

/*
Notes:
There seems to be an issue with consistancy in this program. Although line 25 gives a warning, there are no errors. However if you run the program, sometimes it does not let you add over a certain number of students (the array is full, so perhaps it needs to be resized) and when updating the student info sometimes it enters an infinite loop. However other times, with the same input, this will not happen.

Validation for ID can use the intValidation above, and the code already checks that what is entered is unique. If an invalid input is entered it creates an infinite loop.

Validation for GPA can use the numValidation above. If an invalid input is entered it creates an infinite loop.

I am not sure how to check p->ID when that is the input rather than just ID... wouldn't I need to prompt the user for ID and then check intValidation and then pass it to p-> for the pointer.

*/


