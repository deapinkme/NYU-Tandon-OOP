// Andrea M. Stojanovski
// 23 Midterm

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// name price stock
// produce: expiration date and weght
// flowers: color

class item {
public:
  // constructor
  item(string n, double uP, int s) : name(n), uPrice(uP), stock(s) {}

  // setter
  void setName(string n) {
    name = n;
  }
  void setUPrice(double uP) {
    uPrice = uP;
  }
  void setStock(int s) {
    stock = s;
  }

  // getter
  string getName() {
    return name;
  }
  double getUPrice() {
    return uPrice;
  }
  int getStock() {
    return stock;
  }  

  // method to compute and return price
  double computePrice() {
    double newPrice = getUPrice() * 1.15; // price + 15% profit margin
    return newPrice;
  }

  // method that returns info string
  virtual string info() {
    return "Item name: " + name + ", unit price: " + to_string(uPrice) + ", quantity: " + to_string(stock) + "\n";
  }

private:
  string name;
  double uPrice;
  int stock;
};

class flowers : public item {
public:
  // constructor
  flowers(string n, double uP, int s, string c) : item(n, uP, s) {
    color = c;
  }

  // setter
  void setColor(string c) {
    color = c;
  }  

  // getter
  string getColor() {
    return color;
  } 

  // method to compute and return price
  virtual double computePrice() {
    return getUPrice(); // here it's just the unit price
  }

  // method that returns info string
  string info() {
    return "Flower name: " + getName() + ", unit price: " + to_string(getUPrice()) + ", quantity: " + to_string(getStock()) + ", color: " + color + "\n";
  }

private:
  string color;
};

class produce : public item {
public:
  // constructor
  produce(string n, double uP, int s, double w, string d) : item(n, uP, s) {
    weight = w;
    expDate = d;
  }

  // setter
  void setWeight(double w) {
    weight = w;
  }  
  void setExpDate(string d) {
    expDate = d;
  }

  // getter 
  double getWeight() {
    return weight;
  } 
  string getExpDate() {
    return expDate;
  }

  // method to compute and return price
  double computePrice() {
    double newPrice = getUPrice() * weight; // price times the weigth
    return newPrice;
  }

  // method that returns info string
  string info() {
    return "Produce name: " + getName() + ", unit price: " + to_string(getUPrice()) + ", quantity: " + to_string(getStock()) +  ", weight: " + to_string(weight) + ", expiration: " + expDate + "\n";
  }
 
private:
  double weight;
  string expDate;
};

// derived classes compute and info are overriden

int main(){
  item* arr [3];
  item* it1 = new item("Bread", 2.5, 15);
  produce* pr1 = new produce("Lettuce", 1.95, 20, 1.5, "06/18/2021");
  flowers* fl1 = new flowers("Rose", 2, 30, "Red");
  arr[0] = it1;
  arr[1] = pr1;
  arr[2] = fl1;
  for (int i = 0; i < 3;i++) {
    cout << arr[i]->info();
    delete(arr[i]);
  }
}