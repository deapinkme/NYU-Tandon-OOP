/*
  Andrea M. Stojanovski
  rec04_start.cpp
  20F

 */

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Task 1
// Define an Account struct

struct AccountS {
    string name;
    int account_num;
};

vector<AccountS> readIn() { // I think this might need to be in the main... I just wanted to put it here and call it
    vector<AccountS> accounts;
    ifstream aFile;
    aFile.open("accounts.txt");
    string aWord;
    char curr_char;
    aWord.clear();
    while (!aFile) {
        curr_char = aFile.get();
        while (curr_char != ' ') {
            aWord = aWord + curr_char;
            curr_char = aFile.get();
        }
        string name;
        int account_num;
        if (isdigit(aWord[0])) {
            account_num = aWord;
        }
        else {
            name = aWord;
        }
        aAccount = AccountS(name, account_num);
        accounts.push_back(aAccount)
    }
    ifs.close();
    for (int i = 0; i < sizeof(acc_vec); i++) {
        cout << "Account holder: " << acc_vec[i].name << ", Account number: " << acc_vec[i].acc_num << endl;
    }
    return accounts;
}

// Task 2
// Define an Account class

class AccountC {
public:
    AccountC(string n, int num, int bal) : name(n), acc_num(num), acc_bal(bal) {}
    string aWord;
    char curr_char;
    aWord.clear();
    while (!aFile) {
        curr_char = aFile.get();
        while (curr_char != ' ') {
            aWord = aWord + curr_char;
            curr_char = aFile.get();
        }
        string name;
        int account_num;
        if (isdigit(aWord[0])) {
            account_num = aWord;
        }
        else {
            name = aWord;
        }
        aAccount = AccountS(name, account_num);
        accountS.push_back(aAccount)
    }
    ifs.close();
    for (int i = 0; i < sizeof(acc_vec); i++) {
        cout << "Account holder: " << acc_vec[i].name << ", Account number: " << acc_vec[i].acc_num << endl;
    }
private:
    string name;
    int acc_num;
    int acc_bal;
};

// friend version

ostream& operator<<(ostream& os, const accountS& somebody) {
    os << "Name: " << somebody.name << ", Account number: " << somebody.acc_num;
    return os;
}

class AccountC {
    friend ostream& operator<<(ostream& os, const Person& somebody);
public:
    Account(const string& aName, int aAcc_num) : name(aName), acc_num(aAcc_num) {
    }

    void display() const {
        cout << "Account holder: " << name << ", Account number: " << acc_num << endl;
    }

private:
    string name;
    int acc_num;
};


// Task 3
// Define an Account and Transaction classes

class Transaction {
public:
    Transaction(string t, int amm, int acc) : type(t), ammount(amm), account_balance(acc) {}
    void trans_output(int account.balance()) {
        if (trans_type == "withdrawal") {
            if (trans_amm < acc_amm) {
                acc_amm = acc_amm - trans_amm;
                cout << "Current account balance:" << acc_balance << endl;
            }
            else if (trans_amm > acc_amm) {
                cout << "Error! The account total is too small." << endl;
            }
        }
        else if (trans_type == "deposit") {
            acc_amm = acc_amm + trans_amm;
            cout << "Current account balance:" << acc_balance << endl;
        }
    };
private:
    string type;
    int ammount;
    int account_balance
};

// Task 4
// Define an Account with a nested public Transaction class

class Transaction {
public:
    Transaction(string t, int amm, int acc) : type(t), ammount(amm), account_balance(acc) {}
    void trans_output() {
        if (trans_type == "withdrawal") {
            if (trans_amm < acc_amm) {
                acc_amm = acc_amm - trans_amm;
                cout << "Current account balance:" << acc_balance << endl;
            }
            else if (trans_amm > acc_amm) {
                cout << "Error! The account total is too small." << endl;
            }
        }
        else if (trans_type == "deposit") {
            acc_amm = acc_amm + trans_amm;
            cout << "Current account balance:" << acc_balance << endl;
        }
    };
    class Account {
    public:
        AccountC(string n, int num, int bal) : name(n), acc_num(num), acc_bal(bal) {}
    private:
        string name;
        int acc_num;
        int acc_bal;
    };
private:
    string type;
    int ammount;
    int account_balance
};

// Task 5
// Define an Account with a nested private Transaction class


 main() {

    // Task 1: account as struct
    //      1a
    cout << "Task1a:\n";

    readIn()

    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";

    accountS.clear();

    //==================================
    // Task 2: account as class

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";


    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";
    

    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";


    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";

    
    cout << "\nTask2e:\n";
    cout << "Filling vector of class objects, using emplace_back:\n";

    
    cout << "==============\n";
    cout << "\nTask 3:\nAccounts and Transaction:\n";


    cout << "==============\n";
    cout << "\nTask 4:\nTransaction nested in public section of Account:\n";

    cout << "==============\n";
    cout << "\nTask 5:\nTransaction nested in private section of Account:\n";

    
}
