#include "Assignment.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;


string Assignment:: getTitle() const { return title; }
void Assignment::setTitle(string _title) { title = _title; }

string Assignment::getText() const { return text; }
void Assignment::setText(string _text) { text = _text; }

string Assignment::getStudentUsername() const { return studentUsername; }
void Assignment:: setStudentUsername(string _studentUsername) { studentUsername = _studentUsername; }

int Assignment::getGrade() const { return grade; }
void Assignment::setGrade(int _grade) { grade = _grade; }