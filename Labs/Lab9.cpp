
#include <iostream>
using namespace std;

class Node {
public:
  Node(int data=0, Node* Next = nullptr) : data(data), Next(Next) {}
	int data;
	Node* Next;

};
//display nodes
void printList(Node* n);
//delete nodes
void removeValue(Node* head, int val);


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

void removeValue(Node* head, int val) {
	Node* p = head; // pointer (for curr position in LL)
	Node* temp1 = head;
	Node* temp2 = head;

	while (p != nullptr) { // this makes sure we are not at the end of the list
    if (p->data == val) {
      // delete node
      // reattach other node
    }
    p=p->Next;
  }
    //delete node
    temp2->Next = temp1->Next;
    delete(temp1);
	
  cout << "Task complete. \n";
}

int main()
{
	Node* head = new Node();
	head->Next = NULL;
	Node* second = new Node();
	Node* third = new Node();

	head->data = 1;
	head->Next = second;

	second->data = 4;
	second->Next = third;

	third->data = 3;
	third->Next = NULL;

	removeValue(head, 4);
	printList(head);
	
	cin.get();
}