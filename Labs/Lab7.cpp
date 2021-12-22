// Andrea M. Stojanovski
// Lab 7

#include <iostream>
#include <vector>

using namespace std;

// NOTE: the savings portion is not a part of this submission

class BankAccount {
public:
  // constructor
  BankAccount{int initiaAmount} : m_balance(initiaAmount) {}

  // setter
  void setBalance(int newBalance) {
    m_balance = newBalance;
  }

  // getter
  const int getBalance() {
    return m_balance;
  }

  // toString for display
  const string toString() { // made this a const because the m_balance is const, this seems like it should be too.
    return "Current Bank Account balance is: " + to_string(m_balance);
  }

  void deposit(double aBalance);
  void withdraw(double aBalance);

protected:
  double m_balance;

// private: // should this part be private? That way not even CheckingAccount can use it... I think it needs to just be protected

  // deposit method
  void BankAccount::deposit(double aBalance) {
    m_balance += aBalance;
  }

  // withdraw method
  void BankAccount::withdraw(double aBalance) {
    while (m_balance >= aBalance) {
      m_balance -= aBalance;
      break;
    }
    if (m_balance < aBalance) cout << "Sorry, insufficient funds! \n";
    /*
    while (m_balance < aBalance) {
      cout << "Your current balance is: " << m_balance << endl;
      cout << "Please reenter a valid balance to withdraw: "; // can also display m_balance to let them know how much they can take out
      cin >> aBalance;
      cout << endl;
    }
    */
  }

// end of the BankAccount class
};

class CheckingAccount : public BankAccount {
public:
  // constructor for the superclass
  void CheckingAccount::BankAccount(double aBalance) { // how do you call the constructor from the super class?
    m_balance = aBalance;
    transactioncount = 0; // set transactioncount to 0 for initialization
  }

  // toString for display
  const string toString() { // are we sure that m_balance can be reached... is there no syntax missing?
    return "Current Bank Account balance is: " + to_string(m_balance);
  }

  // check transaction count
  int checkTransCount() {
    return transactioncount;
  }

  virtual void deposit(double aBalance); // override deposit method using virtual
  virtual void withdraw(double aBalance); // override withdraw method using virtual
  void incTransCount();
  void deductFees();

private:
  // setting fees and free transactions
  const double TRANSACTION_FEE = 0.02;
  const int FREE_TRANSACTIONS = 3; // this is not going to be altered rather used to check if there will be a fee
  int transactioncount = 0; // the default is 0 transactions

  // transaction counter incremented
  void incTransCount() { // this can not be public because we don't want it to be manipulated, but should it be private or protected?
    transactioncount += 1;
  }

  // Questions: I am not sure if this is the proper way to override. I added virtal, but is m_balance now passed to the CheckingAccount, if not how do we give it permission? I feel like here there must be an error with not being allowed to access m_balance. To prevent this, should m_balance be placed in protected rather than private? // update I added m_balance to protected

  // override deposit method
  void CheckingAccount::deposit(double aBalance) {
    m_balance += aBalance;
    incTransCount(); // this doesn't need to be a function but it seems cleaner
  }

  // override withdraw method
  void CheckingAccount::withdraw(double aBalance) {
    while (m_balance >= aBalance) {
      m_balance -= aBalance;
    incTransCount();
      break;
    }
    if (m_balance < aBalance) cout << "Sorry, insufficient funds! \n";
    /*
    while (m_balance < aBalance) {
      cout << "Your current balance is: " << m_balance << endl;
      cout << "Please reenter a valid balance to withdraw: "; // can also display m_balance to let them know how much they can take out
      cin >> aBalance;
      cout << endl;
    }
    */
  }

  // decucting the fees
  void deductFees() {
    // calculate how many fees need to be payed
    int currFees = transactioncount - FREE_TRANSACTIONS;

    // remove the fees
    withdraw(double currFees) // withdraws the fees (yes this will increment the transaction counter but we are about to reset it)

    // reset transactioncount
    transactioncount = 0;
  }

// should the functions be in protected? How is private different from protected
  // private can't be accessed outside, protected can be access outside only by inheritance
};

// Done in class
class SavingAccount : public BankAccount { // inherits or extends BankAccount
  // something...
};

int main() {

  BankAccount* bacc0 = new BankAccount(0);
  cout << bacc0->toString();

  BankAccount* bacc1 = new BankAccount(5000);
  cout << bacc1->toString();

  CheckingAccount* chacc1 = new CheckingAccount(500.0);
  cout << chacc1->toString();

 }


/*
Notes from lab:

- banker can envoke deductFees

- override in child by making it the same name and making it virtual in the parent class... call the deposit func from main class and namespace and add transaction

- m_balance protected

- when you use parent constructor
  - to initialize child with the parent constructro BankAccount(initial data)

*/