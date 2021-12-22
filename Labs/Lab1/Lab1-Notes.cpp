// 1 June 2021

#include 
#include <string>

using namespace std;

/*
class Car {
  // access specifiers // private, public protected
private:
  // data members aka propetioes aka variables
  string make;
  string model;
  // member mothods
public:
  void start() {
    cout << make << "\t" <<  model <<" car started \n";
  }
}; // ends with semicolon

int main() {
  Car car1;
  car1.setMake("BMW");
  car1.setModel("x6");
  cout << "Make << "\t" <<  model <<" car started \n";

  Car car2;
  car2.make = "Ferrari";
  car2.model = "spider";
}
*/

#include <iostream>
using namespace std;

void inputInfo(struct Student* arr);
void updateInfo(struct Student* arr);
void displayInfo(struct Student* arr);

struct Student
{
    int ID;
    string name;
    string email;
    string phone;
    double GPA = 0.0;
    int age = 0;
};

void inputInfo(struct Student* arr)
{
    int count = 0;
    int id;
    // counting empty spots
    for (Student* p = arr; p<arr+5; ++p)
    {
        if (p->ID == 0)
        {
            count++;
        }
    }
    for (Student* p = arr; p<arr+5; ++p)
    {
        // check availability
        if(count >= 1)
        {
            cout<<"Enter ID: ";
            cin>>id;
        }
        else
        {
            cout<<"Array is full.";
            break;
        }
        // check uniqueness
        while(p->ID == id)
        {
            cout<<"Enter an unique ID.";
            cin>>id;
        }
        // input info
        p->ID = id;
        cout<<"Enter name: "; cin>>p->name;
        cout<<"Enter email: "; cin>>p->email;
        cout<<"Enter phone: "; cin>>p->phone;
        cout<<"Enter GPA: "; cin>>p->GPA;
        cout<<"Enter Age: "; cin>>p->age;
    }
    cout<<"New student added successfully"<<endl;
}

int main()
{
    Student arr[5];
    inputInfo(arr);
    displayInfo(arr);
    return 0;
}