#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include<vector>
struct Node {
	Node(int data = 0, Node* next = nullptr);
	Node(const std::vector<int>& dataVec, size_t currInd);
	Node(const Node* nodeP);
	int data;
	Node* next;
};

class Polynomial {
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);
	friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
public:
	explicit Polynomial(const std::vector<int>& coeffs = { 0 });
	Polynomial(const Polynomial& rhs);
	~Polynomial();
	Polynomial& operator+=(const Polynomial& rhs);
	Polynomial& operator=(const Polynomial& rhs);
	int evaluate(int x);
private:
	size_t degree;
	Node* coeffsP;
	void reverseDisplayPolynomial(const Node* currNode, int currDegree) const;
};

bool operator!=(const Polynomial& lhs, const Polynomial& rhs);
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

#endif