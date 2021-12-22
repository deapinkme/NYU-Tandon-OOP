// Andrea M. Stojanovski
// Lec 3

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

int main() {
  // make vectors with all menu items
  vector<string> Beverages = {"Coke", "Diet", "Water", "Sprite", "Fanta"};
  vector<string> Appetizer = {"Soup", "Salad", "Calamari"};
  vector<string> Entree = {"Pizza", "Pasta", "Chicken", "Fish"};
  vector<string> Dessert = {"Pie", "Cake", "Ice-cream"};

  // initialize menu selections
  int bev;
  int app;
  int ent;
  int des;

  // Beverages
  cout << "Please select a Beverage (1-5): \n";
  for (int i; i < Beverages.size(); ++i) {
    cout << i+1 << ". " << Beverages[i] << " | ";
  }
  cout << endl;
  cin >> bev;
  while (true) { // this will make sure that the input is with in range of the menu
    if (bev > 0 && bev < 6) break; // breaks if they entered a valid input
    cerr << "Invalid Input, must be a value between 1-5 \n"; // display error of invalid input
    cout << "Please try again: ";
    cin >> bev; // re-enter input
  }

  // Appetizers
  cout << "Please select a Appetizer (1-3): \n";
  for (int i; i < Appetizer.size(); ++i) {
    cout << i+1 << ". " << Appetizer[i] << " | ";
  }
  cout << endl;
  cin >> app;
  while (true) {
    if (app > 0 && app < 4) break;
    cerr << "Invalid Input, must be a value between 1-3 \n";
    cout << "Please try again: ";
    cin >> app;
  }

  // Entrees
  cout << "Please select a Entree (1-4): \n";
  for (int i; i < Entree.size(); ++i) {
    cout << i+1 << ". " << Entree[i] << " | ";
  }
  cout << endl;
  cin >> ent;
  while (true) {
    if (ent > 0 && ent < 5) break;
    cerr << "Invalid Input, must be a value between 1-4 \n";
    cout << "Please try again: ";
    cin >> ent;
  }

  // Desserts
  cout << "Please select a Dessert (1-3): \n";
  for (int i; i < Dessert.size(); ++i) {
    cout << i+1 << ". " << Dessert[i] << " | ";
  }
  cout << endl;
  cin >> des;
  while (true) {
    if (des > 0 && des < 4) break;
    cerr << "Invalid Input, must be a value between 1-3 \n";
    cout << "Please try again: ";
    cin >> des;
  }

  // Display selections
  cout << "You selected: \n";
  cout << Beverages[bev - 1] << endl;
  cout << Appetizer[app - 1] << endl;
  cout << Entree[ent - 1] << endl;
  cout << Dessert[des - 1] << endl;

  // initialize cost
  float cost = 0;

  // Beverage
  if (bev == 1) {
    cost += 3.00;
  } else if (bev == 2) {
    cost += 3.50;
  } else if (bev == 3) {
    cost += 1.00;
  } else if (bev == 4) {
    cost += 2.95;
  } else if (bev == 5) {
    cost += 3.15;
  } // We do not need to worry about getting something that is not 1-5 that was covered above

  // Appetizers

  if (app == 1) {
    cost += 14.50;
  } else if (app == 2) {
    cost += 12.35;
  } else if (app == 3) {
    cost += 22.00;
  }

  // Entrees
  switch (ent) {
    case 1:
      cost += 4.75;
      break;

    case 2:
      cost += 17.40;
      break;

    case 3:
      cost += 24.75;
      break;

    case 4:
      cost += 30.00;
      break;
    // no default because we know that the input is within range from above
  }  

  // Desserts
  switch (des) {
    case 1:
      cost += 8.00;
      break;

    case 2:
      cost += 5.95;
      break;

    case 3:
      cost += 2.50;
      break;
  }  

  // Display the total cost calculated
  cout << endl;
  cout << "Your total is: $" << cost << endl;
}

/* 
Note: If we wanted to create a struct for menu items, this would be nice so that a user could add items to the menu (maybe someone who worked at the restaurant)

struct Menu {
  string name;
  int price;
  Menu(const string& name, const int& price) : name(name), price(price) {}
};

*/