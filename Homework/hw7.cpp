// Andrea M. Stojanovski
// HW 7

#include <iostream>
#include <fstream>

using namespace std;

struct Node {

    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}

    int data;

    Node* next;

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
			temp = temp->next;

		}
	}
	
}

void reverseList(Node* LL) {
  Node* LLr = new Node();
  ofstream myfile ("data.txt");
  if (myfile.is_open()) {
    myfile << "Here is our linked list:\n";

    /*
    if (LL == NULL) {
      cout << "The end";
    }
    */

    if (LL->next == NULL) {
      LLr = LL;
      myfile << LL->data << "\t";
    } else {
    reverseList(LL->next);
    }
  } else cout << "Opps, the file did not open";
  LLr = LL;
  myfile << LL->data << "\t";
  LL->next = LL;
  LL->next = NULL;

  printList(LLr);
  cout << endl;

	if (LLr == NULL) {
		myfile << "Linked list is empty";
	}
	else
	{
		Node* temp = LLr;
		while (temp) {
			myfile << temp->data << " ";
			temp = temp->next;

		}
	}

  myfile.close();
}

int main() {
  // create Linked List
  Node* LL = new Node();
  LL->next = NULL;
  Node* second = new Node();
	Node* third = new Node();

	LL->data = 1;
	LL->next = second;

	second->data = 2;
  second->next = third;

	third->data = 3;
	third->next = NULL;

  // display Linked List
  printList(LL); // I know this is not part of the task but we use this for test purposes
  cout << endl;
  // use reverseList
  reverseList(LL);

  // check file (manually - data.txt)
}

/* Note:
When the program is run we can see that it prints the reversed list, however there is an issue with  writing to the file. For some reason LLr (the temporary reversed linked list) is not being writen to the file correctly. However the print to console is done correctly and is recursive.
*/