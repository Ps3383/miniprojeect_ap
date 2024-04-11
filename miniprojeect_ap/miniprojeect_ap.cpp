
#include <iostream>
#include <fstream>
#include <string>
#include<map>
#include<vector>
#include"teacher.h"
#include"student.h"
#include"admin.h"
using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
// این پرینت های رنگی در سیستم من به خوبی اجرا میشود.

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
    admin.readStudentsFromFile(st, c_student);
    map<string, vector<string>> courses;
    map<string, map<string, int>> grades;
      string input;
      while (true) {
          system("cls");
          cout << RED << "Press 1 to login to admin account\n" << RESET;
          cout << GREEN << "Press 2 to login to teacher account\n" << RESET;
          cout << BLUE << "Press 3 to login to student account\n" << RESET;
          cout << YELLOW << "Press 4 to exit\n" << RESET;

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
                      system("cls");
                      cout << RED << "Press 1 to add Teacher\n";
                      cout << GREEN << "Press 2 to delete Teacher\n";
                      cout << BLUE << "Press 3 to add Student\n";
                      cout << YELLOW << "Press 4 to delete Student\n";
                      cout << MAGENTA << "Press 5 to restore Student\n";
                      cout << CYAN << "Press 6 to restore Teacher\n";
                      cout << WHITE << "Press 7 to exit \n" << RESET;
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
                          cout << "Successfully Done\n";
                          cout << "Press any key to back to menu : ";
                          string v;
                          cin >> v;
                      }
                      else if (command == "2") {
                          string user_remove;
                          cout << "Enter teacher_username that you want to delete : ";
                          cin >> user_remove;
                          admin.softDeleteTeacher(user_remove);
                          admin.removeTeacher(te, c_teacher, user_remove);
                          admin.saveTeachersToFile(te, c_teacher, courses, grades);
                          cout << "Successfully Done\n";
                          cout << "Press any key to back to menu : ";
                          string v;
                          cin >> v;
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
                          cout << "Successfully Done\n";
                          cout << "Press any key to back to menu : ";
                          string v;
                          cin >> v;
                      }
                      else if (command == "4") {
                          string user_remove;
                          cout << "Enter student_username that you want to delete : ";
                          cin >> user_remove;
                          admin.softDeleteStudent(user_remove);
                          admin.removeStudent(st, c_student, user_remove);
                          admin.saveStudentsToFile(st, c_student);
                          cout << "Successfully Done\n";
                          cout << "Press any key to back to menu : ";
                          string v;
                          cin >> v;
                      }
                      else if (command == "5") {
                          string res_user;
                          cout << "Enter Student_username for restore : ";
                          cin >> res_user;
                          admin.restoreStudent(res_user);
                          admin.removeRestoredStudent(res_user);
                          cout << "Successfully Done\n";
                          cout << "Press any key to back to menu : ";
                          string v;
                          cin >> v;
                      }
                      else if (command == "6") {
                          string res_user;
                          cout << "Enter Teacher_username for restore : ";
                          cin >> res_user;
                          admin.restoreTeacher(res_user);
                          admin.removeRestoredTeacher(res_user);
                          cout << "Successfully Done\n";
                          cout << "Press any key to back to menu : ";
                          string v;
                          cin >> v;
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
                  string in;
                  while (true)
                  {
                      system("cls");
                      te[index].print_teacher(te[index]);
                      puts("\n");
                      cout << RED << "Press 1 to create course\n";
                      cout << GREEN << "Press 2 to add student to course\n";
                      cout << BLUE << "Press 3 to remove student from course\n";
                      cout << YELLOW << "Press 4 to set grade for student\n";
                      cout << MAGENTA << "Press 5 to see students in course with grade\n";
                      cout << CYAN << "Press 6 to set homework for student\n";
                      cout << WHITE << "Press 7 to see assignment of courses that you set\n";
                      cout << RED << "Press 8 to view homework of student\n";
                      cout << GREEN << "Press 9 to change your password\n";
                      cout << BLUE << "Press 10 to sign out \n" << RESET;
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
                          string coursename, title, text,user_stu;
                          cout << "Enter course name for set homework : ";
                          cin >> coursename;
                          cout << "Enter title of homewowrk : ";
                          cin >> title;
                          cout << "Enter description for homework : ";
                          cin.ignore();
                          getline(cin, text);
                          cout << "Enter username for add homework for this student : ";
                          cin >> user_stu;
                          if (admin.find_index_student(st, user_stu, c_student) != -1) {
                              te[index].addAssignmentToCourse(coursename, title, text, user_stu);
                              int st_index = admin.find_index_student(st, user_stu, c_student);
                              st[st_index].addAssignmentToCourse(coursename, title, text);

                          }

                      }
                      else if (in == "7") {
                          cout << "Enter course name : ";
                          string co;
                          cin >> co;
                          te[index].printAssignmentsOfCourse(co);
                      }
                      else if (in == "8") {
                          cout << "Enter course name : ";
                          string co;
                          cin >> co;
                          te[index].viewAssignmentsOfCourse(co);
                          cout << "Press 1 to set grade for assignment\n";
                          cout << "Press 2 to back to menu\n";
                          string j;
                          cin >> j;
                          if (j == "1") {
                              string title, s_user, course;
                              int gra = 0;
                              cout << "Enter course name : ";
                              cin >> course;
                              cout << "Enter title of homework : ";
                              cin >> title;
                              cout << "Enter student_username : ";
                              cin >> s_user;
                              cout << "Enter grade : ";
                              cin >> gra;
                              int i_st = admin.find_index_student(st, s_user, c_student);
                              st[i_st].gradeAssignmentOfCourse(course, title, gra);
                              te[index].gradeAssignmentOfCourse(course, title, s_user, gra);
                          }
                          else if (j == "2") {

                          }
                          else {
                              cout << "Wrong input\n";
                              cout << "Press any key to back to menu\n";
                              string h;
                              cin >> h;
                          }
                      }
                      else if (in == "9") {
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
                      else if (in == "10") {
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
              else {
                  cout<<"Press any key to back to menu : ";
                  string l;
                  cin >> l;
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
                  string in;
                  while (true) {
                      system("cls");
                      st[index].print_student(st[index]);
                      puts("\n");
                      cout << RED << "Press 1 to see courses and grades\n";
                      cout << GREEN << "Press 2 to see your homework\n";
                      cout << BLUE << "Press 3 to change your password\n";
                      cout << CYAN << "Press 4 to sign out\n" << RESET;
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
                          string course;
                          cout << "Enetr name of the course to see homework : ";
                          cin >> course;
                          st[index].printAssignmentsOfCourse(course);
                          puts("\n");
                          cout << "Press 1 to do your homework\n";
                          cout << "Press 2 to back to menu\n";
                          string yes;
                          cin >> yes;
                          if (yes == "1") {
                              string title, text, tename, course;
                              cout << "Enter course name : ";
                              cin >> course;
                              cout << "Enter title of homework : ";
                              cin >> title;
                              cout << "Enter a text for your homework : ";
                              cin.ignore();
                              getline(cin, text);
                              cout << "Enter name of the Teacher : ";
                              cin >> tename;
                              int x = admin.find_index_teacher_name(te, tename, c_teacher);
                              if (x != -1)
                                  st[index].submitAssignmentToTeacher(title, text, te[x], course);
                          }
                          else if (yes == "2") {

                          }
                          else {
                              cout << "Wrong input\n";
                              cout << "Press any key to back to menu\n";
                              string h;
                              cin >> h;
                          }
                      }

                      else if (in == "3") {
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

                      else if (in == "4") {
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
                  cout << "Press any key to back to menu : ";
                  string k;
                  cin >> k;
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

 
