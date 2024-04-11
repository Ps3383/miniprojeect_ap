#pragma once
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Assignment {
private:
    string title;
    string text;
    string studentUsername;
    int grade;

public:
    Assignment(string _title = "", string _text = "", string _studentUsername = "", int _grade = -1)
        : title(_title), text(_text), studentUsername(_studentUsername), grade(_grade) {}

    string getTitle() const;
    void setTitle(string _title);

    string getText() const;
    void setText(string _text);

    string getStudentUsername() const;
    void setStudentUsername(string _studentName);

    int getGrade() const;
    void setGrade(int _grade);
};

#endif