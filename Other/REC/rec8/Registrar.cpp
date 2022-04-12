#include "Course.h"
#include "Student.h"
#include "Registrar.h"
using namespace std;

namespace BrooklynPoly {
	ostream& operator<<(ostream& os, const Registrar& aReg) {
		if (aReg.courses.size() == 0) {
			os << "Courses: None\n";
		}
		for (size_t i = 0; i < aReg.courses.size(); ++i) {
			os << *aReg.courses[i] << endl;
		}
		if (aReg.students.size() == 0) {
			os << "Students: None\n";
		}
		for (size_t i = 0; i < aReg.students.size(); ++i) {
			os << *aReg.students[i] << endl;
		}
		return os;
	}
	Registrar::Registrar() {}
	bool Registrar::addCourse(const string& courseName) {
		if (findCourse(courseName) != -1) {
			cerr << "A course called " << courseName << " already exists\n";
			return false;
		}
		Course* aCourse = new Course(courseName);
		courses.push_back(aCourse);
		return true;
	}
	bool Registrar::addStudent(const string& studName) {
		if (findStudent(studName) != -1) {
			cerr << "A student named " << studName << " already exists\n";
			return false;
		}
		Student* aStud = new Student(studName);
		students.push_back(aStud);
		return true;
	}
	bool Registrar::enrollStudentInCourse(const string& studName,
		const string& courseName) {
		size_t studInd = findStudent(studName);
		if (studInd == -1) {
			cerr << "A student named " << studName << " does not exist\n";
			return false;
		}
		size_t courseInd = findCourse(courseName);
		if (courseInd == -1) {
			cerr << "A course called " << courseName << " does not exist\n";
			return false;
		}
		Student* studP = students[studInd];
		Course* courseP = courses[courseInd];

		if (studP->inCourse(courseName)) {
			cerr << studP->getName() << " is already enrolled in " << courseName << endl;
			return false;
		}
		studP->addCourse(courseP);
		return true;
	}
	bool Registrar::cancelCourse(const string& courseName) {
		size_t courseInd = findCourse(courseName);
		if (courseInd == -1) {
			cerr << "A course called " << courseName << " does not exist\n";
			return false;
		}
		for (size_t i = courseInd; i < courses.size(); ++i) {
			if (i == courseInd) {
				courses[i]->purge();
				delete courses[i];
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
		return true;
	}
	void Registrar::purge() {
		for (size_t i = 0; i < students.size(); ++i) {
			delete students[i];
			students[i] = nullptr;
		}
		for (size_t i = 0; i < courses.size(); ++i) {
			delete courses[i];
			courses[i] = nullptr;
		}
		students.clear();
		courses.clear();
	}

	size_t Registrar::findStudent(const string& studName) {
		for (size_t i = 0; i < students.size(); ++i) {
			if (students[i]->getName() == studName) {
				return i;
			}
		}
		return -1;
	}
	size_t Registrar::findCourse(const string& courseName) {
		for (size_t i = 0; i < courses.size(); ++i) {
			if (courses[i]->getName() == courseName) {
				return i;
			}
		}
		return -1;
	}
}