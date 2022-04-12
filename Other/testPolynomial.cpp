// Andrea M Stojanovski
#include "polynomial.h"
#include <iostream>
#include <vector>
using namespace std;

Node::Node(int data, Node* next)
	: data(data), next(next) {}

Node::Node(const vector<int>& dataVec, size_t currInd) {
	data = dataVec[currInd];
	if (currInd == dataVec.size() - 1) {
		next = nullptr;
	}
	else {
		next = new Node(dataVec, currInd + 1);

	}
}

Node::Node(const Node* nodeP) {
	data = nodeP->data;
	if (!nodeP->next) {
		next = nullptr;
	}
	else {
		next = new Node(nodeP->next);
	}
}

ostream& operator<<(ostream& os, const Polynomial& rhs) {
	if (!rhs.degree) {
		os << rhs.coeffsP->data;
	}
	else {
		Node* currNode = rhs.coeffsP;
		int currDegree = rhs.degree;
		while (currDegree > -1) {
			if (currDegree != rhs.degree && currNode->data > 0) {
				cout << " + ";
			}
			if (currNode->data > 1 || !currDegree) {
				cout << currNode->data;
			}
			if (currNode->data && currDegree) {
				cout << "x";
				if (currDegree > 1) {
					cout << "^" << currDegree;
				}
			}

			--currDegree;
			currNode = currNode->next;
		}

	}
	return os;
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs) {
	if (lhs.degree != rhs.degree) { return false; }
	Node* curr = lhs.coeffsP;
	Node* rhsCurr = rhs.coeffsP;
	while (curr) {
		if (curr->data != rhsCurr->data) { return false; }
		curr = curr->next;
		rhsCurr = rhsCurr->next;
	}
	return true;
}

Polynomial::Polynomial(const vector<int>& coeffs)
	: degree(coeffs.size() - 1), coeffsP(new Node(coeffs, 0)) {}

Polynomial::Polynomial(const Polynomial& rhs)
	: degree(rhs.degree), coeffsP(new Node(rhs.coeffsP)) {}

Polynomial::~Polynomial() {
	Node* next = coeffsP;
	while (coeffsP) {
		next = coeffsP->next;
		delete coeffsP;
		coeffsP = next;
	}
}
Polynomial& Polynomial::operator+=(const Polynomial& rhs) {
	while (rhs.degree > degree) {
		coeffsP = new Node(0, coeffsP);
		++degree;
	}
	Node* rhsCurr = rhs.coeffsP;
	Node* curr = coeffsP;
	int currDegree = degree;
	while (rhsCurr) {
		if (!(currDegree > rhs.degree)) {
			curr->data += rhsCurr->data;
			rhsCurr = rhsCurr->next;
		}
		curr = curr->next;
		--currDegree;
	}
	while (!coeffsP->data) {
		Node* newFront = coeffsP->next;
		delete coeffsP;
		coeffsP = newFront;
		--degree;
	}
	return *this;
}
Polynomial& Polynomial::operator=(const Polynomial& rhs) {
	Node* next = coeffsP;
	while (coeffsP) {
		next = coeffsP->next;
		delete coeffsP;
		coeffsP = next;

	}
	coeffsP = new Node(rhs.coeffsP);
	degree = rhs.degree;
	return *this;
}
int Polynomial::evaluate(int x) {
	int currDegree = degree;
	int result = 0;
	for (Node* i = coeffsP; i; i = i->next) {
		result += (i->data) * pow(x, currDegree);
		--currDegree;
	}
	return result;
}

bool operator!=(const Polynomial& lhs, const Polynomial& rhs) {
	return !(lhs == rhs);
}
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
	Polynomial result(lhs);
	result += rhs;
	return result;
}

int main() {
	
    //test constructor
    Polynomial p1({17});                 // 17
    Polynomial p2({1, 2});               // x + 2
    Polynomial p3({-1, 5});              // -1x + 5
    Polynomial p4({5, 4, 3, 2, 1});      // 5x^4 + 4x^3 + 3x^2 + 2x + 1
    Polynomial has_a_zero({4, 0, 1, 7}); // 4x^3 + x + 7
	
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;
    cout << "has_a_zero: " << has_a_zero << endl;
    cout << "p2 + p3: " << (p2+p3) << endl; 
    cout << "p2 + p4: " << (p2+p4) << endl; 
    cout << "p4 + p2: " << (p4+p2) << endl;


    //test copy constructor - the statement below uses the copy constructor
    //to initialize poly3 with the same values as poly4
    Polynomial p5(p4);
    p5 += p3;
    cout << "Polynomial p5(p4);\n"
         << "p5 += p3;\n";

    cout << "p4: " << p4 << endl;  
    cout << "p5: " << p5 << endl;  

    cout << "Calling doNothing(p5)\n";
    doNothing(p5);
    cout << "p5: " << p5 << endl;

    //tests the assignment operator
    Polynomial p6;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;  // Causes bools true and false to be printed that way.
    cout << "(p4 == p6) is " << (p4 == p6) << endl;
    p6 = p4;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;
    cout << "(p4 == p6) is " << (p4 == p6) << endl;

    //test the evaluaton
    int x = 5;
    cout << "Evaluating p1 at " << x << " yields: " << p1.evaluate(5) << endl;
    cout << "Evaluating p2 at " << x << " yields: " << p2.evaluate(5) << endl;
	
    Polynomial p7({3, 2, 1});           // 3x^2 + 2x + 1
    cout << "p7: " << p7 << endl;
    cout << "Evaluating p7 at " << x << " yields: " << p7.evaluate(5) << endl;

    cout << boolalpha;
    cout << "(p1 == p2) is " << (p1 == p2) << endl;
    cout << "(p1 != p2) is " << (p1 != p2) << endl;

	/*=================================================================
	NEW TEST CODE - test if cleaning the leading 0s
	===================================================================*/

	Polynomial p8({ 1, 1 });
	Polynomial p9({ -1, 1 });
	Polynomial p10({ 0, 0, 2 });
	//p8 + p9 tests if += does the cleanup()
	//p10 tests if constructor does the cleanup()
	cout << "((p8 + p9) == p10) is " << ((p8 + p9) == p10) << endl;

    
}


