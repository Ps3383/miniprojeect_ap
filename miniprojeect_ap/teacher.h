#pragma once
#ifndef TEACHER_H
#define TEACHER_H
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Teacher {
private:
	string Name;
	string Username;
	string Password;
	int Teacher_ID;

	map<string, vector<string>> courses; // Map to store students for each course
	map<string, map<string, int>> grades; // Map to store grades for each student in each course
	
	static int count_teacher_obj;
	static int number_t;
public:
	Teacher(string _name = "", string _username = "", string _password = "");
	~Teacher();

	string get_name() const;
	void set_name(string __name);

	string get_username() const;
	void set_username(string __username);

	string get_password() const;
	void set_password(string __password);

	int get_teacher_id();

	int get_count_teacher_obj();

	void print_teacher(Teacher te);

	void create_course(string course_name);
	void addStudentToCourse(string course_name, string student_username);
	void removeStudentFromCourse(string course_name, string student_username);
	void recordGrade(string course_name, string student_username, int grade);

	void print_map_grades();
};

#endif