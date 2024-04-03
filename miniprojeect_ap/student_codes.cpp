#include "student.h"
#include<iostream>
using namespace std;

int student::student_id = 1;

student::student(string _name, string _username, string _password) {
	this->name = _name;
	this->username = _username;
	this->password = _password;
	student_id = student_id + 2;
}

student::~student() {
//nothing now
}

string student::get_name() const { return name; }
void student::set_name(string _name) { name = _name; }

string student::get_username() const{ return username; }
void student::set_username(string _username) { username = _username; }

string student::get_password() const{ return password; }
void student::set_password(string _password) { password = _password; }


