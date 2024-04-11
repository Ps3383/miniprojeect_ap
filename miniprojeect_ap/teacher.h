#pragma once
#ifndef TEACHER_H
#define TEACHER_H
#include<iostream>
#include<vector>
#include<map>
#include"Assignment.h"
#include"Person.h"
using namespace std;
class Teacher : public Person {
private:

	int Teacher_ID;
	map<string, vector<string>> courses; // Map to store students for each course
	map<string, map<string, int>> grades; // Map to store grades for each student in each course
	map<string, vector<Assignment>> courseAssignments;
	static int count_teacher_obj;
	static int number_t;

public:
	Teacher(string _name = "", string _username = "", string _password = "");
	~Teacher();

	int get_teacher_id();

	int get_count_teacher_obj();

	void print_teacher(Teacher te);

	void create_course(string course_name);
	void addStudentToCourse(string course_name, string student_username);
	void removeStudentFromCourse(string course_name, string student_username);
	void recordGrade(string course_name, string student_username, int grade);


	void addAssignmentToCourse(string course_name, string title, string text, string student_username);

	void printAssignmentsOfCourse(string course_name);

	void gradeAssignmentOfCourse(string course_name, string assignmentTitle, string student_username, int grade);
	
	void viewAssignmentsOfCourse(string course_name);

	void print_map_grades();
};

#endif