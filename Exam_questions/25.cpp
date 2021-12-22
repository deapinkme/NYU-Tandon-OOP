// Andrea M. Stojanovski
// 25

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  Node(int data=0, Node* Next = nullptr) : data(data), Next(Next) {}
	int data;
	Node* Next;

};

void printList(Node* n) {
	//check if list is empty
	if (n == NULL) {
		cout << "List is empty";
	}
	else
	{
		Node* temp = n;

		while (temp) {
			cout << temp->data << " ";
			temp = temp->Next;

		}
	}
	
}

int findNext(Node* head, int target, int largest) {
  vector<int> potentialNext;
	if (head == NULL) { // check if the list is empty
		cout << "List is empty";
	}
	else {
		Node* temp = head;

		while (temp) {
      if (temp->data > target) { // found larger
        // cout << temp->data << " "; // this prints all potentialNext
        potentialNext.push_back(temp->data); // add possible next to vector

      }
			temp = temp->Next;
		}
	}
  // check if list is empty, return largest
  // find min list
  int min = largest; // set the minimum to the largest

	if (potentialNext.size() == 0) { // if there are no possible next return largest
    // we know if there are no possible next that that must mean that the targest is the largest but let's cover the case regardless
    return largest;
  } else { // here we will use STL to find min of the vector
    return *min_element(potentialNext.begin(), potentialNext.end());
  }

}

int main() {
	Node* head = new Node();
	head->Next = NULL;
	Node* second = new Node();
	Node* third = new Node();
	Node* fourth = new Node();
	Node* fifth = new Node();

	head->data = 5;
	head->Next = second;

	second->data = 10;
	second->Next = third;

	third->data = 7;
	third->Next = fourth;

	fourth->data = 15;
	fourth->Next = fifth;

	fifth->data = 3;
	fifth->Next = NULL;

  cout << "Our Linked list: ";
	printList(head);
  cout << endl;
	
  cout << endl;	
  cout << "Let's try: findNext(head, 7, 15)" << endl; 
  int res1 = findNext(head, 7, 15);
  cout << "Next: " << res1 << endl;

  cout << endl;
  cout << "Let's try: findNext(head, 4, 15)" << endl; 
  int res2 = findNext(head, 4, 15);
  cout << "Next: " << res2 << endl;

  cout << endl;
  cout << "Let's try: findNext(head, 16, 15)" << endl; 
  int res3 = findNext(head, 16, 15);
  cout << "Next: " << res3 << endl;
}

/* Just to explain my implementation: 
I understand this as we get a linked list and a target value as well as the maximum value in the linked list.
We then go through the linked list and find elements that are larger than the target.
If there are none then we return the "largest" which we recieved as a parameter. In this case that would imply that the target is the largest, given the target is in the linked list.
If there are elements larger then target they are pushed into a vector.
We then find the minimum in the vector, because that will be next. We return this value.

I also tried to neatly display the results... this is done in main.
*/