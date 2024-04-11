#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<vector>
#include<map>
#include"Assignment.h"
#include"teacher.h"
#include"Person.h"
using namespace std;
class Student : public Person {
private:
	//string Name;
	//string Username;
	//string Password;
	int    Student_ID;

	map <string, int > Course_Grade;
	map<string, vector<Assignment>> courseAssignments;  // لیست تکالیف

	static int count_student_obj;
	static int number_s;
public:
	Student(string _name="", string _username="", string _password="");
	~Student();

	//string get_name() const;
	//void set_name(string __name);

	//string get_username() const;
	//void set_username(string __username);

	//string get_password() const;
	//void set_password(string __password);

	int get_student_id();

	int get_count_student_obj();

	void print_student(Student st);

	void set_course_grade(string course_name, int grade);
	void delete_course(string course_name);

	// اضافه کردن تکلیف به لیست تکالیف دانشجو
	void addAssignmentToCourse(string course_name, string title, string text);
	// Print assignments for a specific course
	void printAssignmentsOfCourse(string course_name);
	// Grade an assignment for a specific course
	void gradeAssignmentOfCourse(string course_name, string assignmentTitle, int grade);

	void submitAssignmentToTeacher(string assignmentTitle, string assignmentText, Teacher& teacher, string course_name);

	void print_map_course_grade();

};

#endif
