#include "Course.h"
#include "Student.h"
using namespace std;

namespace BrooklynPoly {
	ostream& operator<<(ostream& os, const Course& aCourse) {
		os << "Course: " << aCourse.name << "\n\tStudents: ";
		if (aCourse.students.size() == 0) {
			os << "None\n";
		}
		for (size_t i = 0; i < aCourse.students.size(); ++i) {
			if (i > 1) {
				os << ", ";
			}
			os << aCourse.students[i]->getName();
		}
		return os;
	}

	Course::Course(const string& courseName) : name(courseName) {}
	string Course::getName() const { return name; }

	void Course::addStudent(Student* studP) {
		students.push_back(studP);
	}

	void Course::purge() {
		for (size_t i = 0; i < students.size(); ++i) {
			students[i]->removeCourse(this);
		}
		students.clear();
	}
	bool Course::hasStudent(const string& studName) const {
		for (size_t i = 0; i < students.size(); ++i) {
			if (students[i]->getName() == studName) {
				return true;
			}
		}
		return false;
	}
}