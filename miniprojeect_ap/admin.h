#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include"teacher.h"
#include"student.h"
using namespace std;

class Admin {
private:

public:
	Admin();
	~Admin();

	void saveTeachersToFile(const Teacher te[], int count);
	void readTeachersFromFile(Teacher te[], int& count);
	void removeTeacher(Teacher te[], int& count, const string& usernameToRemove);

	void saveStudentsToFile(const Student st[], int count);
	void readStudentsFromFile(Student st[], int& count);
	void removeStudent(Student st[], int& count, const string& usernameToRemove);
};



#endif









