#pragma once
#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
	string Name;
	string Username;
	string Password;
public:
	string get_name() const;
	void set_name(string __name);

	string get_username() const;
	void set_username(string __username);

	string get_password() const;
	void set_password(string __password);

};
