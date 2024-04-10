#include"teacher.h"
#include <iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int Teacher::number_t = 0;
int Teacher::count_teacher_obj = 0;

Teacher::Teacher(string _name, string _username, string _password) {
	this->Name = _name;
	this->Username = _username;
	this->Password = _password;
	this->Teacher_ID = this->number_t;
	this->number_t+=2;
	++count_teacher_obj;
}

Teacher::~Teacher() {
	//nothing now
}

string Teacher::get_name() const { return Name; }
void Teacher::set_name(string _name) { Name = _name; }

string Teacher::get_username() const { return Username; }
void Teacher::set_username(string _username) { Username = _username; }

string Teacher::get_password() const { return Password; }
void Teacher::set_password(string _password) { Password = _password; }

int Teacher::get_teacher_id() { return Teacher_ID; }

int Teacher::get_count_teacher_obj() { return count_teacher_obj; }

void Teacher::print_teacher(Teacher te) {
	cout << te.get_name() << endl;
	cout << te.get_username() << endl;
	cout << te.get_password() << endl;
	cout << te.get_teacher_id() << endl;
}


void Teacher:: create_course(string course_name) {
	courses[course_name] = vector<string>();
	cout << "successfully created (:\n";
	//// Initialize an empty list of students for the new course
}

void Teacher::addStudentToCourse(string course_name, string student_username) {
	if (courses.find(course_name) == courses.end()) {
		cout << "Course <<" << course_name << ">> does not exist!" << endl;
		return;
	}
	courses[course_name].push_back(student_username);
	cout << "successfully Added (:\n";
}

void Teacher::removeStudentFromCourse(string course_name, string student_username) {
	if (courses.find(course_name) == courses.end()) {
		cout << "Course <<" << course_name << ">> does not exist for this Teacher!" << endl;
		return;
	}
	auto& students = courses[course_name];
	students.erase(remove(students.begin(), students.end(), student_username), students.end());
	cout << "successfully Removed (:\n";
}

void Teacher::recordGrade(string course_name, string student_username, int grade) {
	grades[course_name][student_username] = grade;
	cout << "successfully Done (:\n";
}








void Teacher::print_map_grades() {
	int cc = 1;
	cout << setw(20) << left << "Course Name" << setw(20) << left << "Student_username" << "Grade" << endl;
	for (const auto& student : grades) {
		for (const auto& course : student.second) {
			cout << cc << "." << setw(20) << left << course.first << setw(20) << left << student.first << course.second << endl;
			++cc;
		}
	}
}


