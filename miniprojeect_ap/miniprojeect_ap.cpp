
#include <iostream>
#include <fstream>
#include <string>
#include<map>
#include<vector>
#include"teacher.h"
#include"student.h"
#include"admin.h"
using namespace std;

bool isInteger(const string& s) {
    size_t start = 0;
    if (s[0] == '-' || s[0] == '+')
        start = 1;
    for (size_t i = start; i < s.length(); ++i) {
        if (!isdigit(s[i]))     
            return false;
    }
    return true;
}


int main() {

    Admin admin;
    Student st[2000];
    Teacher te[100];
    int c_teacher = 0;
    int c_student = 0;
    admin.readTeachersFromFile(te, c_teacher);
    admin.readStudentsFromFile(st, c_student);///////nakamelllll
    map<string, vector<string>> courses;
    map<string, map<string, int>> grades;
      string input;
      while (true) {
         // system("cls");
          cout << "Press 1 to login to admin account\n";
          cout << "Press 2 to login to teacher account\n";
          cout << "Press 3 to login to student account\n";
          cout << "Press 4 to exit\n";
          cin >> input;

          if (!isInteger(input)) {
              string m;
              cout << "invalid input ! try again\n";
              cout << "Press any key to back to menu\n";
              cin >> m;
              continue;
          }
          if (input == "1") {
              string u_name;
              string pass;
              cout << "Enter username : ";
              cin >> u_name;
              cout << "Enter password : ";
              cin >> pass;
              if (u_name == "a" && pass == "a") {
                  string command;
                  while (true) {
                      //system("cls");
                      cout << "Press 1 to add Teacher\n";
                      cout << "Press 2 to delete Teacher\n";
                      cout << "Press 3 to add Student\n";
                      cout << "Press 4 to delete Student\n";
                      cout << "Press 5 to restore Student\n";
                      cout << "Press 6 to restore Teacher\n";
                      cout << "Press 7 to exit \n";
                      cin >> command;
                      if (!isInteger(command)) {
                          string m;
                          cout << "invalid input ! try again\n";
                          cout << "Press any key to back to menu\n";
                          cin >> m;
                          continue;
                      }

                      if (command == "1") {
                          string name_;
                          string username_;
                          string password_;
                          cout << "Enter teacher name : ";
                          cin >> name_;
                          cout << "Enter teacher username : ";
                          cin >> username_;
                          cout << "Enter teacher password : ";
                          cin >> password_;
                          te[c_teacher].set_name(name_);
                          te[c_teacher].set_username(username_);
                          te[c_teacher].set_password(password_); 
                          ++c_teacher;
                          admin.saveTeachersToFile(te, c_teacher, courses,grades );
                      }
                      else if (command == "2") {
                          string user_remove;
                          cout << "Enter teacher_username that you want to delete : ";
                          cin >> user_remove;
                          admin.softDeleteTeacher(user_remove);
                          admin.removeTeacher(te, c_teacher, user_remove);
                          admin.saveTeachersToFile(te, c_teacher, courses, grades);
                      }
                      else if (command == "3") {
                          string name_;
                          string username_;
                          string password_;
                          cout << "Enter student name : ";
                          cin >> name_;
                          cout << "Enter student username : ";
                          cin >> username_;
                          cout << "Enter student password : ";
                          cin >> password_;
                          st[c_student].set_name(name_);
                          st[c_student].set_username(username_);
                          st[c_student].set_password(password_);
                          ++c_student;
                          admin.saveStudentsToFile(st, c_student);
                      }
                      else if (command == "4") {
                          string user_remove;
                          cout << "Enter student_username that you want to delete : ";
                          cin >> user_remove;
                          admin.softDeleteStudent(user_remove);
                          admin.removeStudent(st, c_student, user_remove);
                          admin.saveStudentsToFile(st, c_student);
                      }
                      else if (command == "5") {
                          string res_user;
                          cout << "Enter Student_username for restore : ";
                          cin >> res_user;
                          admin.restoreStudent(res_user);
                          admin.removeRestoredStudent(res_user);
                      }
                      else if (command == "6") {
                          string res_user;
                          cout << "Enter Teacher_username for restore : ";
                          cin >> res_user;
                          admin.restoreTeacher(res_user);
                          admin.removeRestoredTeacher(res_user);
                      }
                      else if (command == "7") {
                          break;
                      }
                      else {
                          string m;
                          cout << "invalid input ! try again\n";
                          cout << "Press any key to back to menu\n";
                          cin >> m;
                          continue;
                      }
                  }
              }
              else {
                  puts("\n");
                  string k;
                  cout << "wrong username or password !\n" << endl;
                  cout << "Press any key to back to menu \n";
                  cin >> k;
                  continue;
              }
          }
          else if (input == "2") {
              string user_;
              string pass_;
              cout << "Enter your username : ";
              cin >> user_;
              cout << "Enter your password : ";
              cin >> pass_;
              int index = -1;
              if (admin.login_teacher(te, user_, pass_, c_teacher)) {
                  index = admin.find_index_teacher(te, user_, c_teacher); //have te_index
                  te[index].print_teacher(te[index]); // print te info
                  string in;
                  while (true)
                  {
                      cout << "Press 1 to create course\n";
                      cout << "Press 2 to add student to course\n";
                      cout << "Press 3 to remove student from course\n";
                      cout << "Press 4 to set grade for student\n";
                      cout << "Press 5 to see students in course with grade\n";
                      cout << "Press 6 to set homework for student\n";
                      cout << "Press 7 to change your password\n";
                      cout << "Press 8 to exit \n";
                      cin >> in;
                      if (!isInteger(in)) {
                          string m;
                          cout << "invalid input ! try again\n";
                          cout << "Press any key to back to menu\n";
                          cin >> m;
                          continue;
                      }
                      if (in == "1") {
                          string coursename;
                          cout << "Enter course name that you want to add : ";
                          cin >> coursename;
                          te[index].create_course(coursename);
                          admin.saveTeachersToFile(te, c_teacher, courses, grades);
                      }
                      else if (in == "2") {
                          string coursename;
                          string user_stu;
                          cout << "Enter course name to add student in : ";
                          cin >> coursename;
                          cout << "Enter student_username to add : ";
                          cin >> user_stu;
                          if (admin.find_index_student(st, user_stu, c_student) != -1) {
                              int index_st = admin.find_index_student(st, user_stu, c_student);
                              te[index].addStudentToCourse(coursename, user_stu);
                              st[index_st].set_course_grade(coursename , -1);
                              admin.saveTeachersToFile(te, c_teacher, courses, grades);
                          }
                      }
                      else if (in == "3") {
                          string coursename;
                          string user_stu;
                          cout << "Enter course name to delete student from : ";
                          cin >> coursename;
                          cout << "Enter student_username to delete from course : ";
                          cin >> user_stu;
                          if (admin.find_index_student(st, user_stu, c_student) != -1) {
                              int index_st = admin.find_index_student(st, user_stu, c_student);
                              te[index].removeStudentFromCourse(coursename, user_stu);
                              st[index_st].delete_course(coursename);
                              admin.saveTeachersToFile(te, c_teacher, courses, grades);
                          }
                      }
                      else if (in == "4") {
                          string coursename;
                          string user_stu;
                          int grade = 0;
                          cout << "Enter course name for grade : ";
                          cin >> coursename;
                          cout << "Enter student_username to give grade : ";
                          cin >> user_stu;
                          cout << "Enter grade : ";
                          cin >> grade;
                          if (admin.find_index_student(st, user_stu, c_student) != -1) {
                              int index_st = admin.find_index_student(st, user_stu, c_student);
                              st[index_st].set_course_grade(coursename, grade);
                              te[index].recordGrade(coursename, user_stu, grade);
                              admin.saveTeachersToFile(te, c_teacher, courses, grades);
                          }
                      }
                      else if (in == "5") {
                          te[index].print_map_grades();
                      }
                      else if (in == "6") {
                          cout << "enter";

                      }
                      else if (in == "7") {
                          string __user;
                          string __pass;
                          cout << "Enter your username : ";
                          cin >> __user;
                          cout << "Enter your password : ";
                          cin >> __pass;
                          if (admin.login_student(st, __user, __pass, c_student)) {
                              cout << "Enter your new password :";
                              string newpass;
                              cin >> newpass;
                              admin.change_pass_teacher(te, __user, newpass, c_teacher);
                              admin.saveTeachersToFile(te, c_teacher,courses,grades);
                          }
                      }
                      else if (in == "8") {
                          break;
                      }
                      else {
                          string m;
                          cout << "invalid input ! try again\n";
                          cout << "Press any key to back to menu\n";
                          cin >> m;
                          continue;
                      }

                  } //End while for teacher menu

              }
          }
          else if (input == "3") {
              string user_;
              string pass_;
              cout << "Enter your username : ";
              cin >> user_;
              cout << "Enter your password : ";
              cin >> pass_;
              int index = -1;
              if (admin.login_student(st, user_, pass_, c_student)) {
                  index = admin.find_index_student(st, user_, c_student);
                  st[index].print_student(st[index]);
                  string in;
                  while (true) {
                      cout << "Press 1 to see courses and grades\n";
                      cout << "Press 2 to change your password\n";
                      cin >> in;
                      if (!isInteger(in)) {
                          string m;
                          cout << "invalid input ! try again\n";
                          cout << "Press any key to back to menu\n";
                          cin >> m;
                          continue;
                      }
                      if (in == "1") {
                          st[index].print_map_course_grade();
                      }
                      else if (in == "2") {
                          string __user;
                          string __pass;
                          cout << "Enter your username : ";
                          cin >> __user;
                          cout << "Enter your password : ";
                          cin >> __pass;
                          if (admin.login_student(st, __user, __pass, c_student)) {
                              cout << "Enter your new password :";
                              string newpass;
                              cin >> newpass;
                              admin.change_pass_student(st, __user, newpass, c_student);
                              admin.saveStudentsToFile(st, c_student);
                          }

                      }
                      else if (in == "32") {
                          break;
                      }
                      else {
                          string m;
                          cout << "invalid input ! try again\n";
                          cout << "Press any key to back to menu\n";
                          cin >> m;
                          continue;
                      }

                  }

              }
          }
          else if (input == "4") {
              break;
          }
          else {
              string m;
              cout << "invalid input ! try again\n";
              cout << "Press any key to back to menu\n";
              cin >> m;
              continue;
          }

      }// End main while

  return 0;
}

 
