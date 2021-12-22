// Andrea M. Stojanovski
// HW 5

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Shape {
public:
  // constructor
  Shape(string n) : name(n) {} // how to we get what type og shape it is?

  // public methods
  void draw() {
    cout << "Drawing a " << getName() << endl;
  }

  string getName() {
    return name;
  }

protected:
  string name;
};

class Square : public Shape { // extends Shape
public:
  // constructor
  Square(double s, string n = "Square") : Side(s), Shape(n) {}

  // public methods
  double getArea () {
    double theArea = Side * Side;
    return theArea;
  }

  double getCircumference() {
    double theCirc = 4 * Side;
    return theCirc;
  }

protected:
  double Side;
};

class Cube : public Square { // extends Square
public:

  // constructor
  Cube(double s, string n = "Cube") : Square(s, n) {}

  // public methods
  double getVolume() {
    double theVol = Side * Side * Side;
    return theVol;
  }

// protected: nothing here

};

class Circle : public Shape { // extends Shape
public:
  // constructor
  Circle(double r, string n = "Circle") : Radius(r), Shape(n) {}

  // public methods
  double getArea () {
    double theArea = Radius * Radius * M_PI; // M_PI is pi
    return theArea;
  }

  double getCircumference() {
    double theCirc = 2 * Radius * M_PI;
    return theCirc;
  }

protected:
  double Radius;
};

class Sphere : public Circle { // extends Circle
public:

  // constructor
  Sphere(double r, string n = "Sphere") : Circle(r, n) {}

  // public methods
  double getVolume() {
    double theVol = 4 / 3 * M_PI * Radius * Radius * Radius;
    return theVol;
  }

// protected: nothing here

};

int main() {

  // create an array of shapes
  Shape *Shapes[4];
  Shapes[0] = new Square(5);
  Shapes[1] = new Circle(2.5);
  Shapes[2] = new Cube(5);
  Shapes[3] = new Sphere(2.5);

  // iterate through the array and handle shapes polymorphically
  for (int i=0; i<4; i++) {
    Shapes[i]->draw();
  }

}

/*
helpful links:

https://icarus.cs.weber.edu/~dab/cs1410/textbook/14.CPP_Relationships/using.html

https://icarus.cs.weber.edu/~dab/cs1410/textbook/10.Multiclass_Programs/using_inheritance.html

https://icarus.cs.weber.edu/~dab/cs1410/textbook/10.Multiclass_Programs/actor1.html

*/