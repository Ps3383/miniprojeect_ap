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

	int Student_ID;
	map <string, int > Course_Grade;
	map<string, vector<Assignment>> courseAssignments;  // لیست تکالیف
	static int count_student_obj;
	static int number_s;

public:
	Student(string _name="", string _username="", string _password="");
	~Student();

	int get_student_id();

	int get_count_student_obj();

	void print_student(Student st);

	void set_course_grade(string course_name, int grade);
	void delete_course(string course_name);

	void addAssignmentToCourse(string course_name, string title, string text);

	void printAssignmentsOfCourse(string course_name);
	
	void gradeAssignmentOfCourse(string course_name, string assignmentTitle, int grade);

	void submitAssignmentToTeacher(string assignmentTitle, string assignmentText, Teacher& teacher, string course_name);

	void print_map_course_grade();

};

#endif
