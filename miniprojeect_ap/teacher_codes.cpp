#include"teacher.h"
#include <iostream>
using namespace std;

int Teacher::teacher_id = 0;
int Teacher::count_teacher_obj = 0;

Teacher::Teacher(string _name, string _username, string _password, int _idt) {
	this->Name = _name;
	this->Username = _username;
	this->Password = _password;
	this->teacher_id = _idt;
	teacher_id = teacher_id + 2;
	++count_teacher_obj;
}

Teacher::~Teacher() {
	//nothing now
}

string Teacher::get_name() const { return Name; }
void Teacher::set_name(string _name) { Name = _name; }

string Teacher::get_username() const { return Username; }
void Teacher::set_username(string _username) { Username = _username; }

string Teacher::get_password() const { return Password; }
void Teacher::set_password(string _password) { Password = _password; }

int Teacher::get_count_teacher_obj() { return count_teacher_obj; }

void Teacher::print_teacher(Teacher te) {
	cout << te.get_name() << endl;
	cout << te.get_username() << endl;
	cout << te.get_password();
}

