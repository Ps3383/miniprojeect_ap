#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
using namespace std;
class student {
private:
	string name;
	string username;
	string password;
	static int student_id;
public:
	student(string _name, string _username, string _password);
	~student();

	string get_name() const;
	void set_name(string __name);

	string get_username() const;
	void set_username(string __username);

	string get_password() const;
	void set_password(string __password);

};

#endif
