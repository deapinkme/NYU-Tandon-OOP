// Andrea M. Stojanovski

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Section { 
	friend ostream& operator<<(ostream& os, const Section& section) {
		os << "Section: " << section.name << ", Time Slot: " << section.slot << ", Students:";
		if (section.studentRecord.size() == 0) {
			os << "None" << endl;
		}
		else {
			os << endl;
			for (size_t i = 0; i < section.studentRecord.size(); ++i) {
				os << *(section.studentRecord[i]) << endl;
			}
		}
		return os;
	}
public:
	Section(const string& name, const string& day, int time) : name(name), slot(day, time) {};

	~Section() {
		cout << "Section " << name << " is being deleted\n";
		for (size_t i = 0; i < studentRecord.size(); ++i) {
			cout << "Deleting " << studentRecord[i] -> getName() << endl;
			delete studentRecord[i];
			studentRecord[i] = nullptr;
		}
	}
	Section(const Section& otherSec) : name(otherSec.name), slot(otherSec.slot) {
		for (size_t i = 0; i < otherSec.studentRecord.size(); ++i) {
			Student* studentP = new Student(*(otherSec.studentRecord[i]));
			studentRecord.push_back(studentP);
		}
	}
	void addStudent(const string& name) {
		Student* studentP = new Student(name);
		studentRecord.push_back(studentP);
	}
	void addGrade(const string& studentName, int grade, int week) {
		for (size_t i = 0; i < studentRecord.size(); ++i) {
			if (studentRecord[i] -> getName() == studentName) {
				studentRecord[i] -> setGrade(grade, week);
				break;
			}
		}
	}
	void reset() {
		for (size_t i = 0; i < studentRecord.size(); ++i) {
			delete studentRecord[i];
			studentRecord[i] = nullptr;
		}
		studentRecord.clear();

	}
private:
	string name;
	class Student {
		friend ostream& operator<<(ostream& os, const Student& student) {
			os << "Name: " << student.name << ", Grades: ";
			for (size_t i = 0; i < student.labRecord.size(); ++i) {
				os << student.labRecord[i] << ' ';
			}
			return os;
		}
	public:
		Student(const string& name) : name(name), labRecord(14, -1) {}
		Student(const Student& otherStud) {
			name = otherStud.name;
			labRecord = otherStud.labRecord;
		}
		void setGrade(int grade, int week) {
			labRecord[week - 1] = grade;
		}
		const string& getName() const {
			return name;
		}
	private:
		string name;
		vector<int> labRecord;
	};
	class TimeSlot {
		friend ostream& operator<<(ostream& os, const TimeSlot& slot) {
			os << "[Day: " << slot.day << ", Start Time: "
				<< (slot.startTime - 12) << slot.meridiem << ']';
			return os;
		}
	public:
		TimeSlot(const string& day, int time) : day(day), startTime(time) {
			if (startTime > 12) {
				meridiem = "pm";
			}
			else {
				meridiem = "am";
			}
		}
		TimeSlot(const TimeSlot& otherSlot) {
			day = otherSlot.day;
			startTime = otherSlot.startTime;
			meridiem = otherSlot.meridiem;
		}
	private:
		string day;
		int startTime;
		string meridiem;
	};
	vector<Student*> studentRecord;
	TimeSlot slot;
};

class LabWorker {
	friend ostream& operator<<(ostream& os, const LabWorker& worker) {
		if (!(worker.hisSection)) {
			os << worker.name << " does not have a section\n";
			return os;
		}
		os << worker.name << " has " << *worker.hisSection;
		return os;
	}
public:
	LabWorker(const string& name) : name(name) {}
	~LabWorker() { 
	hisSection = nullptr;
	}
	void addGrade(const string& studentName, int grade, int week) {
		if (!hisSection) {
			cerr << name << " does not have a section\n";
			return;
		}
		hisSection -> addGrade(studentName, grade, week);
	}
	void addSection(Section& sec) {
		hisSection = &sec;
	}
	void reset() {
		hisSection = nullptr;
	}
private:
	string name;
	Section* hisSection = nullptr;
};


// Test code
void doNothing(Section sec) {
	cout << sec << endl;;
}

int main() {

	cout << "Test 1: Defining a section\n";
	Section secA2("A2", "Tuesday", 16);
	cout << secA2 << endl;

	cout << "\nTest 2: Adding students to a section\n";
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");
	cout << secA2 << endl;

	cout << "\nTest 3: Defining a lab worker.\n";
	LabWorker moe("Moe");
	cout << moe << endl;

	cout << "\nTest 4: Adding a section to a lab worker.\n";
	moe.addSection(secA2);
	cout << moe << endl;

	cout << "\nTest 5: Adding a second section and lab worker.\n";
	LabWorker jane("Jane");
	Section secB3("B3", "Thursday", 11);
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");
	jane.addSection(secB3);
	cout << jane << endl;

	cout << "\nTest 6: Adding some grades for week one\n";
	moe.addGrade("John", 17, 1);
	moe.addGrade("Paul", 19, 1);
	moe.addGrade("George", 16, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << moe << endl;

	cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
	moe.addGrade("John", 15, 3);
	moe.addGrade("Paul", 20, 3);
	moe.addGrade("Ringo", 0, 3);
	moe.addGrade("George", 16, 3);
	cout << moe << endl;

	cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
		<< "those students (or rather their records?)\n";

	cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
		<< "then make sure the following call works properly, i.e. no memory leaks\n";
	doNothing(secA2);
	cout << "Back from doNothing\n\n";

} // main
