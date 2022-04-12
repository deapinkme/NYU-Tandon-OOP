// Andrea M. Stojanovski

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
	friend ostream& operator<<(ostream& os, const PrintedMaterial& rhs) {
		os << rhs.numOfPages << endl;
		return os;
	}
public:
	PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
	virtual void displayNumPages() const = 0;
private:
	unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
	cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
	void displayNumPages() const override {
		cout << "Magazine:\n";
		PrintedMaterial::displayNumPages();
	}

private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned numPages) : PrintedMaterial(numPages) {}
	void displayNumPages() const override {
		cout << "Book\n";
		PrintedMaterial::displayNumPages();
	}
private:
};

class TextBook : public Book {
public:
	TextBook(unsigned numPages, unsigned numIndex)
		: Book(numPages), numOfIndexPages(numIndex) {}
	void displayNumPages() const override {
		cout << "TextBook:\n" << "Pages: ";
		PrintedMaterial::displayNumPages();
		cout << "Index pages: " << numOfIndexPages << endl;
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned numPages) : Book(numPages) {}
	void displayNumPages() const override {
		cout << "Novel:\n";
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

void displayNumberOfPages(const PrintedMaterial& pm) {
	pm.displayNumPages();
}

int main() {
	vector<PrintedMaterial*> materials;
	TextBook t(5430, 23);
	Novel n(213);
	Magazine m(6);
	materials.push_back(&t);
	materials.push_back(&n);
	materials.push_back(&m);

	for (const PrintedMaterial* pm : materials) {
		pm->displayNumPages();
	}
}