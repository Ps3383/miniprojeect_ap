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
	static int student_id;
	static int count_student_obj;
public:
	Student(string _name="", string _username="", string _password="" , int _ids=-5);
	~Student();

	string get_name() const;
	void set_name(string __name);

	string get_username() const;
	void set_username(string __username);

	string get_password() const;
	void set_password(string __password);

	int get_count_student_obj();
	void print_student(Student st);
};

#endif
