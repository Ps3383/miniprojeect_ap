#include "student.h"
#include"teacher.h"
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

int Student::number_s = 1;
int Student::count_student_obj = 0;

Student::Student(string _name, string _username, string _password ) {
	this->Name = _name;
	this->Username = _username;
	this->Password = _password;
	this->Student_ID = this->number_s;
	this->number_s+=2;
	++count_student_obj;
}

Student::~Student() {
//nothing now
}

string Student::get_name() const { return Name; }
void Student::set_name(string _name) { Name = _name; }

string Student::get_username() const{ return Username; }
void Student::set_username(string _username) { Username = _username; }

string Student::get_password() const{ return Password; }
void Student::set_password(string _password) { Password = _password; }

int Student::get_student_id() { return Student_ID; }

int Student::get_count_student_obj() { return count_student_obj; }

void Student::print_student(Student st) {
	cout << st.get_name() << endl;
	cout << st.get_username() << endl;
	cout << st.get_password() << endl;
	cout << st.get_student_id() << endl;
	//cout << st.get_courses() << endl;
}

void Student::set_course_grade(string course_name, int grade) {
	Course_Grade[course_name] = grade;
}

void Student::delete_course(string course_name) {
	if (Course_Grade.count(course_name) == 0) {
		cout << "this Course does not exist for this student\n";
		return;
	}
	Course_Grade.erase(course_name);
}

void Student::print_map_course_grade() {
	int ccc = 1;
	cout << setw(15) << left << "Course" << "Grade" << endl;
	for (const auto& pair : Course_Grade) {
		cout << ccc << "." << setw(15) << left << pair.first << pair.second << endl;
		++ccc;
	}
}

void Student::addAssignmentToCourse(string course_name, string title, string text) {
    if (courseAssignments.find(course_name) == courseAssignments.end()) {
        // Course not found, create a new entry
        courseAssignments[course_name] = vector<Assignment>();
    }
    // Add assignment to the corresponding course
    courseAssignments[course_name].push_back(Assignment(title, text, Name));
}

// Implementation of the method to print assignments of a specific course for Student
void Student::printAssignmentsOfCourse(string course_name) {
    if (courseAssignments.find(course_name) != courseAssignments.end()) {
        cout << "Your Assignments for course " << course_name << ":" << endl;
        for (const auto& assignment : courseAssignments[course_name]) {
            cout << "Title: " << assignment.getTitle() << endl;
            cout << "Text: " << assignment.getText() << endl;
            // Print more assignment details if needed
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

// Implementation of the method to grade an assignment for a specific course for Student
void Student::gradeAssignmentOfCourse(string course_name, string assignmentTitle, int grade) {
    if (courseAssignments.find(course_name) != courseAssignments.end()) {
        for (auto& assignment : courseAssignments[course_name]) {
            if (assignment.getTitle() == assignmentTitle && assignment.getStudentName() == Name) {
                assignment.setGrade(grade);
                cout << "Grade for assignment '" << assignment.getTitle() << "' in course '" << course_name << "' has been set to " << grade << endl;
                return;
            }
        }
        cout << "Assignment not found or you are not enrolled in this course." << endl;
    }
    else {
        cout << "No assignments found for course " << course_name << endl;
    }
}

void Student::submitAssignmentToTeacher(string assignmentTitle, string assignmentText, Teacher& teacher, string course_name) {
    // Create an assignment object
    Assignment assignment(assignmentTitle, assignmentText, Name);

    // Add the assignment to the teacher's course
    teacher.addAssignmentToCourse(course_name, assignmentTitle, assignmentText, Name);

    cout << "Assignment '" << assignmentTitle << "' has been submitted to the teacher for course '" << course_name << "'" << endl;
}


