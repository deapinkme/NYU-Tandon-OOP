#include "Student.h"
#include "Course.h"
using namespace std;


namespace BrooklynPoly {
	ostream& operator<<(ostream& os, const Student& aStud) {
		os << "Student: " << aStud.name << "\n\tCourses: ";
		if (aStud.courses.size() == 0) {
			os << "None\n";
		}
		for (size_t i = 0; i < aStud.courses.size(); ++i) {
			if (i > 0) {
				os << ", ";
			}
			os << aStud.courses[i]->getName();
		}
		return os;
	}
	Student::Student(const string& name) : name(name) {}
	string Student::getName() const { return name; }
	void Student::addCourse(Course* courseP) {
		courseP->addStudent(this);
		courses.push_back(courseP);
	}

	void Student::removeCourse(Course* courseP) {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i] == courseP) {
				courses[i] = nullptr;
				for (size_t rest = i + 1; rest < courses.size(); ++rest) {
					if (!courses[rest - 1]) {
						courses[rest - 1] = courses[rest];
						courses[rest] = nullptr;
					}
				}
				courses.pop_back();
				break;
			}
		}
	}
	bool Student::inCourse(const string& courseName) const {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i]->getName() == courseName) {
				return true;
			}
		}
		return false;
	}

}