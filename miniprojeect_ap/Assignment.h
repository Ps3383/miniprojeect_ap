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
    string studentName;
    int grade;

public:
    Assignment(string _title = "", string _text = "", string _studentName = "", int _grade = -1)
        : title(_title), text(_text), studentName(_studentName), grade(_grade) {}

    string getTitle() const;
    void setTitle(string _title);

    string getText() const;
    void setText(string _text);

    string getStudentName() const;
    void setStudentName(string _studentName);

    int getGrade() const;
    void setGrade(int _grade);
};

#endif