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

	bool login_student( Student st[],string user, string pass , int count);
	bool login_teacher( Teacher te[],string user, string pass , int count);

	Student find_student(Student st[], string user, int count);
	Teacher find_teacher(Teacher te[], string user, int count);

	int find_index_student(Student st[], string user, int count);
	int find_index_teacher(Teacher te[], string user, int count);

	void change_pass_teacher(Teacher te[], string user, string newpass, int count);
	void change_pass_student(Student st[], string user, string newpass, int count);

	void restore_student();
	void moveto_restore(const Teacher te[], string user, int count);

};



#endif









