// Andrea M. Stojanovski

#include <cstdlib>
#include <iostream>

using namespace std;

class List;

struct Node {
	Node() : prev(nullptr), next(nullptr) {}
	Node(int data, Node* prev, Node* next)
		:data(data), prev(prev), next(next) {}
	int data;
	Node* prev;
	Node* next;
};

class ListIterator {
	friend List;
	friend bool operator==(const ListIterator& lhs, const ListIterator& rhs) {
		if (!lhs.nodeP || !rhs.nodeP) {
			return false;
		}
		return lhs.nodeP->data == rhs.nodeP->data;
	}
public:
	ListIterator(Node* p) : nodeP(p) {}
	ListIterator& operator++() {
		if (nodeP->next) {
			nodeP = nodeP->next;
		}
		return *this;
	}
	ListIterator& operator--() {
		if (nodeP->prev) {
			nodeP = nodeP->prev;
		}
		return *this;
	}
	int& operator*() {
		return nodeP->data;
	}

private:
	Node* nodeP;
};

class const_ListIterator {
	friend List;
	friend bool operator==(const const_ListIterator& lhs, 
		const const_ListIterator& rhs) {
		if (!lhs.nodeP || !rhs.nodeP) {
			return false;
		}
		return lhs.nodeP->data == rhs.nodeP->data;
	}
public:
	const_ListIterator(Node* p) : nodeP(p) {}
	const_ListIterator& operator++() {
		if (nodeP->next) {
			nodeP = nodeP->next;
		}
		return *this;
	}
	const_ListIterator& operator--() {
		if (nodeP->prev) {
			nodeP = nodeP->prev;
		}
		return *this;
	}
	const int operator*() const {
		return nodeP->data;
	}
private:
	const Node* nodeP;
};

bool operator!=(const ListIterator& lhs, const ListIterator& rhs) {
	return !(lhs == rhs);
}
bool operator!=(const const_ListIterator& lhs, const const_ListIterator& rhs) {
	return !(lhs == rhs);
}

class List {
	friend std::ostream& operator<<(std::ostream& os, const List& rhs){
		for (Node* curr = rhs.headDummy->next; curr != rhs.tailDummy; 
			curr = curr->next) {
			os << curr->data << " ";
		}
		os << endl;
		return os;
	}
public:
	List() : theSize(0), headDummy(new Node()), tailDummy(new Node()) {
		headDummy->next = tailDummy;
		tailDummy->prev = headDummy;
	}
	void push_back(int data) {
		Node* result = new Node(data, tailDummy->prev, tailDummy);
		tailDummy->prev->next = result;
		tailDummy->prev = result;
		++theSize;
	}
	void pop_back() {
		if (!theSize) { exit(1); }
		Node* oldTail = tailDummy->prev;
		tailDummy->prev = oldTail->prev;
		oldTail->prev->next = tailDummy;
		delete oldTail;
		--theSize;
	}

	void push_front(int data) {
		Node* result = new Node(data, headDummy, headDummy->next);
		headDummy->next->prev = result;
		headDummy->next = result;
		++theSize;
	}
	void pop_front() {
		if (!theSize) { exit(1); }
		Node* oldFront = headDummy->next;
		oldFront->next->prev = headDummy;
		headDummy->next = oldFront->next;
		delete oldFront;
		--theSize;
	}

	void clear() {
		for (Node* curr = headDummy->next; curr != tailDummy
			; curr = headDummy->next) {
			headDummy->next = curr->next;
			curr->next->prev = headDummy;
			delete curr;
			--theSize;
		}
	}

	int operator[](int ind) const {
		if ((ind > theSize - 1) || theSize == 0 ) {
			exit(1);
		}
		Node* result = headDummy->next;
		for (int i = 0; i < ind ; ++i) {
			result = result->next;
		}
		return result->data;
	}
	int& operator[](int ind) {
		if ((ind > theSize - 1) || theSize == 0) {
			exit(1);
		}
		Node* result = headDummy->next;
		for (int i = 0; i < ind; ++i) {
			result = result->next;
		}
		return result->data;
	}

	ListIterator insert(const ListIterator& position, int data) {
		Node* result = new Node(data, position.nodeP->prev, position.nodeP);
		position.nodeP->prev->next = result;
		position.nodeP->prev = result;
		++theSize;
		return ListIterator(result);
	}

	ListIterator erase(const ListIterator& position) {
		if (position.nodeP == tailDummy) {
			return position;
		}
		Node* result = position.nodeP->next;
		position.nodeP->prev->next = result;
		result->prev = position.nodeP->prev;
		delete position.nodeP;
		--theSize;
		return ListIterator(result);
	}

	int& front() {
		if (!theSize) {	exit(1);}
		return headDummy->next->data;
	}
	int front() const {
		if (!theSize) { exit(1); }
		return headDummy->next->data;
	}
	int& back() {
		if (!theSize) { exit(1);}
		return tailDummy->prev->data;
	}
	int back() const {
		if (!theSize) { exit(1); }
		return tailDummy->prev->data;
	}
	int size() const { return theSize; }

	ListIterator begin() {
		return ListIterator(headDummy->next);
	}
	
	ListIterator end() {
		return ListIterator(tailDummy);
	}

	const_ListIterator begin() const {
		return const_ListIterator(headDummy->next);
	}

	const_ListIterator end() const {
		return const_ListIterator(tailDummy);
	}

private:
	int theSize;
	Node* headDummy;
	Node* tailDummy;
};

// Task 1
void printListInfo(const List& myList) {
	cout << "size: " << myList.size()
		<< ", front: " << myList.front()
		<< ", back(): " << myList.back()
		<< ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList) {
	theList.front() = 17;
	theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
	for (size_t i = 0; i < myList.size(); ++i) {
		cout << myList[i] << ' ';
	}
	cout << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}    

int main() {

	// Task 1
	cout << "\n------Task One------\n";
	List myList;
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i) {
		cout << "myList.push_back(" << i * i << ");\n";
		myList.push_back(i * i);
		printListInfo(myList);
	}
	cout << "===================\n";

	cout << "Modify the first and last items, and display the results\n";
	changeFrontAndBack(myList);
	printListInfo(myList);
	cout << "===================\n";

	cout << "Remove the items with pop_back\n";
	while (myList.size()) {
		printListInfo(myList);
		myList.pop_back();
	}
	cout << "===================\n";

	// Task 2
	cout << "\n------Task Two------\n";
	cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i) {
		cout << "myList2.push_front(" << i * i << ");\n";
		myList.push_front(i * i);
		printListInfo(myList);
	}
	cout << "===================\n";
	cout << "Remove the items with pop_front\n";
	while (myList.size()) {
		printListInfo(myList);
		myList.pop_front();
	}
	cout << "===================\n";

	// Task 3
	cout << "\n------Task Three------\n";
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i) {
		myList.push_back(i * i);
	}
	printListInfo(myList);
	cout << "Now clear\n";
	myList.clear();
	cout << "Size: " << myList.size() << ", list: " << myList << endl;
	cout << "===================\n";

	// Task 4
	cout << "\n------Task Four------\n";
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	for (int i = 0; i < 10; ++i)  myList.push_back(i * i);
	cout << "Display elements with op[]\n";
	for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
	cout << endl;
	cout << "Add one to each element with op[]\n";
	for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
	cout << "And print it out again with op[]\n";
	for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
	cout << endl;
	cout << "Now calling a function, printListSlow, to do the same thing\n";
	printListSlow(myList);
	cout << "Finally, for this task, using the index operator to modify\n"
		<< "the data in the third item in the list\n"
		<< "and then using printListSlow to display it again\n";
	myList[2] = 42;
	printListSlow(myList);


	// Task 5
	cout << "\n------Task Five------\n";
	cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i)  myList.push_back(i * i);
	printListInfo(myList);
	cout << "Now display the elements in a ranged for\n";
	for (int x : myList) cout << x << ' ';
	cout << endl;
	cout << "And again using the iterator type directly:\n";
	// Note you can choose to nest the iterator class or not, your choice.
	//for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
	for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;
	cout << "WOW!!! (I thought it was cool.)\n";

	// Task 6
	cout << "\n------Task Six------\n";
	cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i * i);
	printListInfo(myList);
	cout << "Filling an empty list with insert at begin(): "
		<< "i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i * i);
	printListInfo(myList);
	// ***Need test for insert other than begin/end***
	cout << "===================\n";

	// Task 7
	cout << "\n------Task Seven------\n";
	cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i * i);
	cout << "Erasing the elements in the list, starting from the beginning\n";
	while (myList.size()) {
		printListInfo(myList);
		myList.erase(myList.begin());
	}
	// ***Need test for erase other than begin/end***
	cout << "===================\n";

	// Task 8
	cout << "\n------Task Eight------\n";
	cout << "Copy control\n";
	cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
	myList.clear();
	for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i * i);
	printListInfo(myList);
	cout << "Calling doNothing(myList)\n";
	doNothing(myList);
	cout << "Back from doNothing(myList)\n";
	printListInfo(myList);

	cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
	List listTwo;
	for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i * i);
	printListInfo(listTwo);
	cout << "listTwo = myList\n";
	listTwo = myList;
	cout << "myList: ";
	printListInfo(myList);
	cout << "listTwo: ";
	printListInfo(listTwo);
	cout << "===================\n";
}
