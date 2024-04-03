#pragma once
#ifndef TEACHER_H
#define TEACHER_H
#include<iostream>
using namespace std;
class teacher {
private:
	string name;
	string username;
	string password;
	static int teacher_id;
public:
	teacher(string _name, string _username, string _password);
	~teacher();

	string get_name() const ;
	void set_name(string __name);

	string get_username() const ;
	void set_username(string __username);

	string get_password() const ;
	void set_password(string __password);
};

#endif