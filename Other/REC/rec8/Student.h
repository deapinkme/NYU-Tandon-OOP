#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly {
	class Course;
	class Student {
		friend std::ostream& operator<<(std::ostream& os, const Student& aStud);
	public:
		Student(const std::string& name);
		std::string getName() const;
		void addCourse(Course* courseP);
		void removeCourse(Course* courseP);
		bool inCourse(const std::string& courseName) const;

	private:
		std::string name;
		std::vector<Course*> courses;
	};
}
#endif