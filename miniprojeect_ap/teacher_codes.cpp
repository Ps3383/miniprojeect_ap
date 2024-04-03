#include"teacher.h"
#include <iostream>
using namespace std;

int teacher::teacher_id = 0;

teacher::teacher(string _name, string _username, string _password) {
	this->name = _name;
	this->username = _username;
	this->password = _password;
	teacher_id = teacher_id + 2;
}

teacher::~teacher() {
	//nothing now
}

string teacher::get_name() const { return name; }
void teacher::set_name(string _name) { name = _name; }

string teacher::get_username() const { return username; }
void teacher::set_username(string _username) { username = _username; }

string teacher::get_password() const { return password; }
void teacher::set_password(string _password) { password = _password; }



