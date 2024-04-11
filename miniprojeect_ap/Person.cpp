#include<iostream>
#include<string>
#include"Person.h"
using namespace std;

string Person::get_name() const { return Name; }
void Person::set_name(string _name) { Name = _name; }

string Person::get_username() const { return Username; }
void Person::set_username(string _username) { Username = _username; }

string Person::get_password() const { return Password; }
void Person::set_password(string _password) { Password = _password; }

