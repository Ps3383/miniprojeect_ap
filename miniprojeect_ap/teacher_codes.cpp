#include"teacher.h"
#include <iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
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


int Teacher::get_teacher_id() { return Teacher_ID; }

int Teacher::get_count_teacher_obj() { return count_teacher_obj; }

void Teacher::print_teacher(Teacher te) {
	cout << "Name" << setw(20) << "Username" << setw(20) << "Password" << setw(20) << "Teacher_ID\n";
	cout << te.get_name();
	cout << setw(18) << te.get_username();
	cout << setw(18) << te.get_password();
	cout << setw(18) <<""<< te.get_teacher_id() << endl;
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
	// Check if the course exists
	if (courses.find(course_name) == courses.end()) {
		cout << "Course <<" << course_name << ">> does not exist for this Teacher!" << endl;
		return;
	}

	// Get the reference to the vector of students in the course
	auto& students = courses[course_name];

	// Use std::remove_if with a lambda function to remove the student by username
	students.erase(std::remove_if(students.begin(), students.end(),
		[student_username](const string& username) {
			return username == student_username;
		}), students.end());

	cout << "Successfully Removed :)" << endl;
}

void Teacher::recordGrade(string course_name, string student_username, int grade) {
	grades[course_name][student_username] = grade;
	cout << "successfully Done (:\n";
}

void Teacher::print_map_grades() {
	cout << setw(20)  << "Student_username" << setw(20) << "Course name" << setw(20) << "Grade" << endl;
	for (const auto& student : grades) {
		for (const auto& course : student.second) {
			cout <<setw(20)  << course.first << setw(20) << student.first << setw(20) << course.second << endl;
		}
	}
}

void Teacher::addAssignmentToCourse(string course_name, string title, string text, string student_username) {
	if (courseAssignments.find(course_name) == courseAssignments.end()) {
		// Course not found, create a new entry
		courseAssignments[course_name] = vector<Assignment>();
	}
	// Add assignment to the corresponding course
	
	courseAssignments[course_name].push_back(Assignment(title, text, student_username));
}

// Implementation of the method to print assignments of a specific course
void Teacher::printAssignmentsOfCourse(string course_name) {
	if (courseAssignments.find(course_name) != courseAssignments.end()) {
		cout << "Assignments for course " << course_name << ":" << endl;
		for (const auto& assignment : courseAssignments[course_name]) {
			cout << "Title: " << assignment.getTitle() << endl;
			cout << "Text: " << assignment.getText() << endl;
			// Print more assignment details if needed
			cout << "--------------------" << endl;
		}
	}
	else {
		cout << "No assignments found for course " << course_name << endl;
	}
}

void Teacher::gradeAssignmentOfCourse(string course_name, string assignmentTitle, string student_username, int grade) {
	if (courseAssignments.find(course_name) != courseAssignments.end()) {
		for (auto& assignment : courseAssignments[course_name]) {
			if (assignment.getTitle() == assignmentTitle && assignment.getStudentUsername() == student_username) {
				assignment.setGrade(grade);
				cout << "Grade for assignment '" << assignment.getTitle() << "' by student '" << student_username << "' in course '" << course_name << "' has been set to " << grade << endl;
				return;
			}
		}
		cout << "Assignment not found or student not enrolled in this course." << endl;
	}
	else {
		cout << "No assignments found for course " << course_name << endl;
	}
}

void Teacher::viewAssignmentsOfCourse(string course_name) {
	cout << "Assignments submitted by students for course " << course_name << ":" << endl;
	// Check if the course has assignments
	if (courseAssignments.find(course_name) != courseAssignments.end()) {
		for (const auto& assignment : courseAssignments[course_name]) {
			cout << "Student: " << assignment.getStudentUsername() << endl;
			cout << "Title: " << assignment.getTitle() << endl;
			cout << "Text: " << assignment.getText() << endl;
			if (assignment.getGrade() != -1) {
				cout << "Grade: " << assignment.getGrade() << endl;
			}
			else {
				cout << "Grade: Not graded yet" << endl;
			}
			cout << "--------------------" << endl;
		}
	}
	else {
		cout << "No assignments found for course " << course_name << endl;
	}
}
