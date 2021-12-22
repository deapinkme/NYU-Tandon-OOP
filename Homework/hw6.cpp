// Andrea M. Stojanovski
// HW6

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node{
  // added a default constructor incase a "blank" node is created
  Node(int data=0, Node* Next=nullptr) : data(data), Next(Next) {}
  int data;
  Node *Next;
};

void insertBefore(Node* aNode, int data) {
  Node* prev = aNode;
  Node* newNode = new Node(data, aNode->Next);

  aNode->Next->Next = prev;
}

void insertAfter(Node* aNode, int data) {
  aNode->Next = new Node(data, aNode->Next);
}

Node* reverseList(Node* aNode) {
  if (aNode == NULL || aNode->Next == NULL)
      return aNode; // when there is only one node (nothing to reverse)

  Node* otherNodes = reverseList(aNode->Next);
  aNode->Next->Next = aNode;

  aNode->Next = NULL;
  
  return otherNodes;
}

// found this online to try and figure it out... but this isn't what we want
void printReverse(Node* head)
{
    // Base case
    if (head == NULL)
    return;
 
    // print the list after head node
    printReverse(head->Next);
 
    // After everything else is printed, print head
    cout << head->data << " ";
}

void printNodes(Node* firstNode) {
  Node* p = firstNode;
  while (p != nullptr) { // make sure it is not the end of the linked list
    cout << p->data << ' '; // print the current data
    p = p->Next; // shift to next node
  }
  cout << endl;
}

int main() {
  Node* linkedList = nullptr;
  linkedList = new Node(17);
  linkedList->Next = new Node(28);
  printNodes(linkedList);

  insertBefore(linkedList->Next, 100);
  printNodes(linkedList);

  insertBefore(linkedList, 17);
  printNodes(linkedList);

//  reverseList(linkedList);
  printNodes(linkedList);

}