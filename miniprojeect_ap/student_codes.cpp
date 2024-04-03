#include "student.h"
#include<iostream>
using namespace std;

int Student::number_s = 1;
int Student::count_student_obj = 0;

Student::Student(string _name, string _username, string _password ) {
	this->Name = _name;
	this->Username = _username;
	this->Password = _password;
	this->Student_ID = this->number_s;
	this->number_s+=2;
	++count_student_obj;
}

Student::~Student() {
//nothing now
}

string Student::get_name() const { return Name; }
void Student::set_name(string _name) { Name = _name; }

string Student::get_username() const{ return Username; }
void Student::set_username(string _username) { Username = _username; }

string Student::get_password() const{ return Password; }
void Student::set_password(string _password) { Password = _password; }

int Student::get_student_id() { return Student_ID; }

int Student::get_count_student_obj() { return count_student_obj; }

void Student::print_student(Student st) {
	cout << st.get_name() << endl;
	cout << st.get_username() << endl;
	cout << st.get_password() << endl;
	cout << st.get_student_id();
}
