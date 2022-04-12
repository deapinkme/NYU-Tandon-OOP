#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly {
	class Student;
	class Course {
		friend std::ostream& operator<<(std::ostream& os, const Course& aCourse);
	public:
		Course(const std::string& courseName);
		std::string getName() const;
		void addStudent(Student* studP);
		void purge();

		bool hasStudent(const std::string& studName) const;

	private:
		std::string name;
		std::vector<Student*> students;
	};
}
#endif
