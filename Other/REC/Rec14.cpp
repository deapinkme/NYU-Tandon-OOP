fi// Andrea
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

struct Node {
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
	int data;
	Node* next;
};

int countBinaryOnes(int x) {
	if (x < 2) { return x; }
	int res = countBinaryOnes(x / 2);
	return (x % 2) + res;
}

bool evenBin(int x) {
	if (x < 2) {
		return !x;
	}
	bool res = evenBin(x / 2);
	if (res && x % 2) { return false; }
	if (!res && x % 2) { return true; }
	return res;
}

Node* sumLists(Node* lst1, Node* lst2) {
	if (!lst1 && !lst2) { return nullptr; }
	if (!lst1 && lst2){
		Node* res = sumLists(lst1, lst2->next);
		return new Node(lst2->data, res);
	}
	if (lst1 && !lst2) {
		Node* res = sumLists(lst1->next, lst2);
		return new Node(lst1->data, res);
	}
	else {
		Node* res = sumLists(lst1->next, lst2->next);
		return new Node(lst1->data + lst2->data, res);
	}
}

struct TNode { // copied from rec page
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

int max(TNode* root) {
	if (!root) {
		throw invalid_argument("Tree is empty\n");
	}
	if (!root->left && !root->right) {
		return root->data;
	}
	if (root->right && !root->left) {
		int res = max(root->right);
		return root->data > res ? root->data : res;
	}
	if (root->left && !root->right) {
		int res = max(root->left);
		return root->data > res ? root->data : res;
	}
	else {
		int lRes = max(root->left);
		int rRes = max(root->right);
		int res = lRes > rRes ? lRes : rRes;
		return root->data > res ? root->data : res;
	}

}

bool palindrome(const char* curr, int length) {
	if (length < 2) { return true; }
	bool res = palindrome(curr + 1, length - 2);
	return res && (*curr == *(curr + length - 1));
}

int towers(int count, char start, char target, char spare) {
	if (count == 0) { return 0; }
	int res = towers(count - 1, start, spare, target);
	int res2 = towers(count - 1, spare, target, start);
	return res + res2 + 1;
}

void mystery(int n) {
	if (n > 1) {
		cout << 'a';
		mystery(n / 2);
		cout << 'b';
		mystery(n / 2);
	}
	cout << 'c';
}

int main() {
	//Part 1
	cout << evenBin(367) << endl << evenBin(236) << endl;
	cout << evenBin(262032) << endl << evenBin(3) << endl;

	//Part 2
	Node a1(5), b1(4, &a1), c1(3,&b1), d1(2,&c1), e1(1,&d1);
	Node* node1 = &e1;
	Node* node2 = &c1;
	Node* res = sumLists(node1, node2);
	Node* res2 = sumLists(node2, node1);
	Node* res3 = sumLists(node1,node1);
	for (Node* i = res; i != nullptr; i = i->next) {
		cout << i->data << ' ';
	}

	for (Node* i = res2; i != nullptr; i = i->next) {
		cout << i->data << ' ';
	}

	for (Node* i = res3; i != nullptr; i = i->next) {
		cout << i->data << ' ';
	}

	//part 3

	TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
	cout << max(&f) << endl;
	try {
		cout << max(nullptr) << endl;
	}
	catch (invalid_argument inv) {
		cerr << "invalid_argument: " << inv.what() << endl;
	}

	//Part 4
	char s[] = "racecar"; // from rec page
	if (palindrome(s, 7)) { cout << "Yes!\n"; }

	/*
	char s[] = "noon"; // from rec page
	if (palindrome(s, 4)) { cout << "Yes!\n"; }

	char s[] = "mom"; // from rec page
	if (palindrome(s, 3)) { cout << "Yes!\n"; }
	*/

	//part 5
	for(int i = 0; i < 11; ++i){
	cout << towers(i, 'a', 'b', 'c') << endl;
	}

	//part 6
	for (int i = 0; i < 11; ++i) {
		mystery(i);
		cout << endl;
	}


}

  
  
