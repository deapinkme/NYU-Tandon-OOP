#include <iostream>

using namespace std;

class A {
    double data;
};

class C {
    int data;
};

int f​() {
    C* ptr = new C();
    A a;
    return 0;
}

class Node {
public:
  Node(int data=0, Node* Next = nullptr) : data(data), Next(Next) {}
	int data;
	Node* Next;

};

struct BaseClass {
  const int wheels = 2;
};

struct DerivedClass : BaseClass {
  const int wheels = 4;
};

void printWheels(BaseClass& base) {
  cout << base.wheels << endl;
}

int main() {
/*
  const int n =7;
  n++;
  cout << n;

Node* C = new Node(30);
Node* B = new Node(30);
Node* A = new Node(30);
delete(B);
cout << B << endl;

int x = f();
cout << x;

const Thing& something;
//
*p = 17;

int* int_array = new int[20];
int i = int_array[24];
cout << i;
*/

DerivedClass der;
printWheels(der);
}

struct isPresent {
    isPresent(int n) : n(n) {}
    bool operator()(int val) { return val % n == 0; }
    int n;
};

void func(vector<double> &myVect, int value) {
  vector<double>::iterator p = find(myVect.begin(), myVect.end(), value);
  if (p != v.end()) {
    cout << "Found" << endl;
  } else {
    cout << "NOT FOUND" << endl;
  }
}

/*
  The STL. Standard Template Library
  Sec B
*/

#include <vector>
#include <iostream> 
#include <list>
#include <algorithm>
using namespace std;

char* myfind(char* start, char* stop, char target) {
    for (char* curr = start; curr != stop; ++curr) {
	if (*curr == target) return curr;
    }
    return stop;
}

template <typename Iter, typename Victim>
Iter myfind(Iter start, Iter stop, Victim target) {
    for (Iter curr = start; curr != stop; ++curr) {
	if (*curr == target) return curr;
    }
    return stop;
}

bool isEven(int val) {
    return val % 2 == 0;
}

template <typename Iter, typename Predicate>
Iter myfind_if(Iter start, Iter stop, Predicate pred) {
    for (Iter curr = start; curr != stop; ++curr) {
	if ( pred(*curr) ) return curr;
    }
    return stop;
}

// No, does not work. auto cannot be a parameter type
//void foo(auto n) {}

//int bar() { return 17; }
auto bar() { return 17; } // c++17


struct IsEvenStruct {
    bool operator()(int val) { return val % 2 == 0; }
};

struct IsMultipleStruct {
    IsMultipleStruct(int n) : n(n) {}
    bool operator()(int val) { return val % n == 0; }
    int n;
};


int main() {

    char arr[] = "Bjarne Stroustrup";
    int len = 17;

    vector<char> vc(arr, arr+len);
    list<char> lc(&vc[0], &vc[len]);
    list<char> lc2(vc.begin(), vc.end());

    //char* where = find(arr, arr+len, 's');
    char* where = myfind(arr, arr+len, 's');


    // list<char>::iterator where2 = find(lc.begin(), lc.end(), 's');
    // list<char>::iterator where3 = find(lc.begin(), lc.end(), 'Q');
    list<char>::iterator where2 = myfind(lc.begin(), lc.end(), 's');
    list<char>::iterator where3 = myfind(lc.begin(), lc.end(), 'Q');
    if (where3 == lc.end()) {
	cout << "Q is not in Stroustrup's name\n";
    }

    vector<int> vi {3, 5, 6, 7, 11};
    
    vector<int>::iterator where4 = find_if(vi.begin(), vi.end(), isEven);
    where4 = find_if(vi.begin(), vi.end(), 
		     //[] (int val) -> bool { return val % 2 == 0; });
                     [] (int val) { return val % 2 == 0; });

    auto where27 = myfind(lc.begin(), lc.end(), 'Q');

    IsEvenStruct isEvenInstance;
    if (isEvenInstance(18)) cout << "is even\n";

    where4 = find_if(vi.begin(), vi.end(), isEvenInstance);
    where4 = find_if(vi.begin(), vi.end(), IsEvenStruct() );
    where4 = find_if(vi.begin(), vi.end(), IsMultipleStruct(2) );


    sort(arr, arr+len);  // using a half-open range   [arr, arr+len)

    auto x = 17.0;
}

