// Andrea M. Stojanovski
// lab 8

#include <iostream>
#include <string>

using namespace std;

// Task 1.1 part 2
class base_conversion {
public:
  // constructor
  base_conversion(double iVal) : m_initialValue(iVal) {}

  // setter
  void set_initial(double iVal) {
    m_initialValue = iVal;
  }  
  void set_converted(double cVal) {
    m_convertedValue = cVal;
  }

  // getter 
  double get_initial() {
    return m_initialValue;
  } 
  double get_converted() {
    return m_convertedValue;
  }

/*
  // virtual printing function
  virtual void convert_it() {
    cout << "Base conversion by super class" << endl;
    m_convertedValue = 2 * m_initialValue;
  }
*/

  // pure virtual function
  virtual void convert_it() = 0;

private:
  double m_initialValue;
  double m_convertedValue;
};

// Task 1.1 part 3
class kilos_miles : public base_conversion {
public:
  // constructor
  kilos_miles(double iVal) : base_conversion(iVal) {}

  // overode printing function
  void convert_it() override {
    cout << "Conversion by kilos_miles class" << endl;
    m_convertedValue = 0.6 * get_initial();
  }

private:
  double m_convertedValue;
};

// Task 1.1 part 4
class miles_kilos : public base_conversion {
public:
  // constructor
  miles_kilos(double iVal) : base_conversion(iVal) {}

  // overode printing function
  void convert_it() override {
    cout << "Conversion by kilos_miles class" << endl;
    m_convertedValue = get_initial() / 0.6;
  }

private:
  double m_convertedValue;
};

class yard_meter : public base_conversion {
public:
  // constructor
  yard_meter(double iVal) : base_conversion(iVal) {}

  // overode printing function
  void newConvert() {
    cout << "Not able to convert yet" << endl;
  }

  // Task 1.3 part 6
  void convert_it() override {
    cout << "Conversion by yard_meter class" << endl;
    m_convertedValue = get_initial() / 0.6;
  }
private:
  double m_convertedValue;
};

int main() {
  /*
  // Task 1.2
  base_conversion* baseOBJ = new base_conversion(100.0);
  baseOBJ->convert_it();
  cout << "Initial value is: " << baseOBJ.get_initial()<<endl;
  cout << "Converted value is: " << baseOBJ.get_converted()<<endl; 

  kilos_miles* kmOBJ = new kilos_miles(100.0);
  kmOBJ->convert_it();
  cout << "Distance in kilometers is: " << kmOBJ.get_initial()<<endl;
  cout << "Distance in miles is: " << kmOBJ.get_converted()<<endl; 

  miles_kilos* mkOBJ = new miles_kilos(60);
  mkOBJ->convert_it();
  cout << "Distance in miles is: " << mkOBJ.get_initial()<<endl;
  cout << "Distance in kilometers is: " << mkOBJ.get_converted()<<endl; 

  yard_meter* ymOBJ = new yard_meter(50);
  ymOBJ->convert_it();
  cout << "Distance in miles is: " << ymOBJ.get_initial()<<endl;
  cout << "Distance in kilometers is: " << ymOBJ.get_converted()<<endl; 
  */

  // Task 1.3 part 3
//  base_conversion* baseOBJ = new base_conversion(100.0);

  // Task 1.3 part 5
  yard_meter* ymOBJ = new yard_meter(50);

}