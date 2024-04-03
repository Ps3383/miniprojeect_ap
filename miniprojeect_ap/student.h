#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;
class Student {
private:
	string Name;
	string Username;
	string Password;
	int Student_ID;
	static int count_student_obj;
	static int number_s;
public:
	Student(string _name="", string _username="", string _password="");
	~Student();

	string get_name() const;
	void set_name(string __name);

	string get_username() const;
	void set_username(string __username);

	string get_password() const;
	void set_password(string __password);

	int get_student_id();

	int get_count_student_obj();

	void print_student(Student st);
};

#endif
