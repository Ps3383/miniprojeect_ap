#pragma once
#ifndef TEACHER_H
#define TEACHER_H
#include<iostream>
using namespace std;
class Teacher {
private:
	string Name;
	string Username;
	string Password;
	int Teacher_ID;
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

};

#endif