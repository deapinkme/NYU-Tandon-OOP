#ifndef REGISTRAR_H
#define REGISTRAR_H
#include <string>
#include <vector>
#include <iostream>

namespace BrooklynPoly {
	class Student;
	class Course;
	class Registrar {
		friend std::ostream& operator<<(std::ostream& os, const Registrar& aReg);
	public:
		Registrar();
		bool addCourse(const std::string& courseName);
		bool addStudent(const std::string& studName);
		bool enrollStudentInCourse(const std::string& studName,
			const std::string& courseName);
		bool cancelCourse(const std::string& courseName);
		void purge();

	private:
		size_t findStudent(const std::string& studName);
		size_t findCourse(const std::string& courseName);

		std::vector<Course*> courses;
		std::vector<Student*> students;
	};
}
#endif