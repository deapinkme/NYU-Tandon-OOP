// Andrea M. stojanovski

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

// task 9
void printListIter(const list<int>& lst) {
	for (list<int>::const_iterator curr = lst.begin()
		; curr != lst.end(); ++curr) {
		cout << *curr << ' ';
	}
	cout << endl;
}

//task 10
void printListRanged(const list<int>& lst) {
	for (int i : lst) {
		cout << i << ' ';
	}
	cout << endl;
}

//task 11
void printListAuto(const list<int>& lst) {
	for (auto curr = lst.begin(); curr != lst.end(); ++curr) {
		cout << *curr << ' ';
	}
	cout << endl;
}
// task 12
list<int>::const_iterator findReturnConst(int item, const list<int>& lst) {
	for (list<int>::const_iterator i = lst.begin(); i != lst.end(); ++i) {
		if (*i == item) { return i; }
	}
	return lst.end();
}
//task 13
auto findReturnAuto(int item, const list<int>& lst) {
	for (auto i = lst.begin(); i != lst.end(); ++i) {
		if (*i == item) { return i; }
	}
	return lst.end();
}
//task 15
bool isEven(int n) { return !(n % 2); }
// task 16
class IsEvenClass {
public:
	bool operator()(int n) const { return !(n % 2); }
};

//task 19
list<int>::iterator ourFind(list<int>::iterator begin
	, list<int>::iterator end, int target) {
	cout << "in ourFind\n";
	for (auto iter = begin; iter != end; ++iter) {
		if (*iter == target) { return iter; }
	}
	return end;
}

//task 20
template <class T>
T ourFind(T begin, T end, int target) {
	cout << "in templated ourFind\n";
	for (T iter = begin; iter != end; ++iter) {
		if (*iter == target) { return iter; }
	}
	return end;
}

int main() {
	// 1. Create a vector with some values and display using ranged for
	cout << "Task 1: Create vector\n";
	vector<int> vInt = { 1,3,5,7,2,9,4,6,8 };
	cout << "vector: ";
	for (const int i : vInt) {
		cout << i << ' ';
	}
	cout << "\n=======\n";

	// 2. Initalize a list as a copy of values from the vector
	cout << "Task 2: Create list from vector\n";
	cout << "list: ";
	list<int> lInt(vInt.begin(), vInt.end());
	for (const int i : lInt) {
		cout << i << ' ';
	}
	cout << "\n=======\n";

	// 3. Sort the original vector.  Display both the vector and the list
	cout << "Task 3: sort vector\n";
	sort(vInt.begin(), vInt.end());
	cout << "vector: ";
	for (const int i : vInt) {
		cout << i << ' ';
	}
	cout << "\n  list: ";
	for (const int i : lInt) {
		cout << i << ' ';
	}
	cout << "\n=======\n";

	// 4. print every other element of the vector.
	cout << "Task 4: vector every other elem (attempt range for)\n";
	cout << "vector: ";
	for (size_t i = 0; i < vInt.size(); ++++i) {
		cout << vInt[i] << ' ';
	}
	cout << "\n=======\n";

	// 5. Attempt to print every other element of the list using the
	//    same technique.
	cout << "Task 5: List every other elem (attempt range for)\n";
	cout << " list: ";
	cout << "\nFailure. Operator [] does not exist for std::list";
	cout << "\n=======\n";

	//
	// Iterators
	//

	// 6. Repeat task 4 using iterators.  Do not use auto;
	cout << "Task 6: Vector every other elem (attempt iterator)\n";
	vector<int>::iterator i = vInt.begin();

	for (vector<int>::iterator i = vInt.begin(); i != vInt.end(); i = i + 2) {
		cout << *i << ' ';
		if (i + 1 == vInt.end()) { break; }
	}
	cout << "\n=======\n";

	// 7. Repeat the previous task using the list.  Again, do not use auto.
	//    Note that you cannot use the same simple mechanism to bump
	//    the iterator as in task 6.
	cout << "Task 7: List every other elem (attempt iterator)\n";
	for (list<int>::iterator i = lInt.begin(); i != lInt.end(); ++i) {
		cout << *i << ' ';
		if (++i == lInt.end()) { break; }
	}
	cout << "\n=======\n";

	// 8. Sorting a list
	cout << "Task 8: Sort list with list method\n";
	lInt.sort();
	for (const int i : lInt) {
		cout << i << ' ';
	}
	cout << "\n=======\n";

	// 9. Calling the function to print the list
	cout << "Task 9: call printListIter\n";
	printListIter(lInt);
	cout << "=======\n";

	// 10. Calling the function that prints the list, using ranged-for
	cout << "Task 10: call printListRanged\n";
	printListRanged(lInt);
	cout << "=======\n";

	//
	// Auto
	//

	// 11. Calling the function that, using auto, prints alterate
	// items in the list
	cout << "Task 11: call printListAuto\n";
	printListAuto(lInt);
	cout << "=======\n";


	// 12.  Write a function find that takes a list and value to search for.
	//      What should we return if not found
	cout << "Task 12: call findReturnConst\n";
	list<int>::const_iterator exist = findReturnConst(8, lInt);
	list<int>::const_iterator notExist = findReturnConst(10, lInt);

	cout << "exist: " << *exist << "\nnotExist == list.end(): "
		<< boolalpha << (notExist == lInt.end());
	cout << "\n=======\n";

	// 13.  Write a function find that takes a list and value to search for.
	//      What should we return if not found
	cout << "Task 13: call findReturnAuto\n";
	auto existAuto = findReturnConst(8, lInt);
	auto notExistAuto = findReturnConst(10, lInt);

	cout << "exist: " << *existAuto << "\nnotExist == list.end(): "
		<< boolalpha << (notExistAuto == lInt.end());
	cout << "\n=======\n";

	//
	// Generic Algorithms
	//


	// 14. Generic algorithms: find
	cout << "Task 14: find algorithm \n";
	exist = find(lInt.begin(), lInt.end(), 8);
	cout << "exist: " << *exist;
	cout << "\n=======\n";

	// 15. Generic algorithms: find_if
	list<int> evenLst = { 2 };

	cout << "Task 15:find_if algorithm\n";
	exist = find_if(lInt.begin(), lInt.end(), isEven);
	cout << "exist: " << *exist;
	cout << "\n=======\n";

	// 16. Functor
	cout << "Task 16: Functor\n";
	exist = find_if(lInt.begin(), lInt.end(), IsEvenClass());

	cout << "exist: " << *exist;
	cout << "\n=======\n";

	// 17. Lambda
	cout << "Task 17: Lambda Expression\n";
	exist = [](const list<int>& lst) {
		for (list<int>::const_iterator i = lst.begin(); i != lst.end(); ++i) {
			if (!(*i % 2)) { return i; }
		}
		return lst.end();
	} (lInt);
	cout << "exist: " << *exist;
	cout << "\n=======\n";

	// 18. Generic algorithms: copy to an array
	cout << "Task 18: copy array\n";
	int arr[9];
	copy(lInt.begin(), lInt.end(), arr);
	for (int i : arr) { cout << i << ' '; }
	cout << "\nfind in Array:\n";
	int* existArray = find(arr, arr + 9, 7);
	int* notExistArray = find(arr, arr + 9, 10);
	cout << "exist: " << *existArray << "\nnotExist == array + 9: "
		<< (notExistArray == arr + 9);
	cout << "\n=======\n";


	//
	// Templated Functions
	//

	// 19. Implement find as a function for lists
	cout << "Task 19: ourFind \n";
	cout << *ourFind(lInt.begin(), lInt.end(), 8);
	cout << "\n=======\n";

	// 20. Implement find as a templated function
	cout << "Task 20:ourFind templated \n";
	cout << "in vector: " << *ourFind(vInt.begin(), vInt.end(), 8)
		<< "\nin array: " << *ourFind(arr, arr + 8, 8);
	cout << "\n=======\n";

	//
	// Associative collections
	//

	// 21. Using a vector of strings, print a line showing the number
	//     of distinct words and the words themselves.
	cout << "Task 21:\n";
	ifstream ifs("pooh-nopunc.txt");
	if (!ifs) { cerr << "error opening file\n"; exit(1); }
	vector<string> wordsVec;
	string word;

	while (ifs >> word) {
		if (wordsVec.end() == find(wordsVec.begin(), wordsVec.end(), word)) {
			wordsVec.push_back(word);
		}
	}
	cout << "vector size: " << wordsVec.size() << " contents: ";
	for (const string& i : wordsVec) { cout << i << ' '; }
	ifs.close();
	cout << "\n\n=======\n";

	// 22. Repeating previous step, but using the set
	cout << "Task 22:\n";
	ifstream ifs2("pooh-nopunc.txt");
	if (!ifs2) { cerr << "error opening file\n"; exit(1); }
	set<string> wordsSet;
	while (ifs2 >> word) {
		wordsSet.insert(word);
	}
	cout << "set size: " << wordsSet.size() << " contents: ";
	for (const string& i : wordsSet) { cout << i << ' '; }
	ifs2.close();
	cout << "\n\n=======\n";

	// 23. Word co-occurence using map
	cout << "Task 23:\n";
	ifstream ifs3("pooh-nopunc.txt");
	int position = 0;
	if (!ifs3) { cerr << "error opening file\n"; exit(1); }
	map<string, vector<int>> wordsMap;
	while (ifs3 >> word) {
		wordsMap[word].push_back(position);
		++position;
	}
	cout << "Map:\n";
	for (auto i : wordsMap) {
		cout << i.first << ": ";
		for (int j : i.second) {
			cout << j << ' ';
		}
		cout << endl;
	}
	ifs3.close();
	cout << "\n=======\n";
}
