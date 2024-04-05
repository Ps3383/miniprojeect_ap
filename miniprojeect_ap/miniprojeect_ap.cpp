
#include <iostream>
#include <fstream>
#include <string>
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
    admin.readStudentsFromFile(st, c_student);

      string input;
      while (true) {
         // system("cls");
          cout << "press 1 to login to admin account\n";
          cout << "press 2 to login to teacher account\n";
          cout << "press 3 to login to student account\n";
          cout << "press 4 to exit\n";
          cin >> input;

          if (!isInteger(input)) {
              string m;
              cout << "invalid input ! try again\n";
              cout << "press any key to back to menu\n";
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
                      cout << "press 1 to add teacher\n";
                      cout << "press 2 to delete teacher\n";
                      cout << "press 3 to add student\n";
                      cout << "press 4 to delete student\n";
                      cout << "press 5 to exit \n";
                      cin >> command;
                      if (!isInteger(command)) {
                          string m;
                          cout << "invalid input ! try again\n";
                          cout << "press any key to back to menu\n";
                          cin >> m;
                          continue;
                      }
                      if (command == "5") {
                          break;
                      }
                      else if (command == "1") {
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
                          admin.saveTeachersToFile(te, c_teacher);
                      }
                      else if (command == "2") {
                          string user_remove;
                          cout << "Enter teacher_username that you want to delete : ";
                          cin >> user_remove;
                          admin.removeTeacher(te, c_teacher, user_remove);
                          admin.saveTeachersToFile(te, c_teacher);
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
                          admin.removeStudent(st, c_student, user_remove);
                          admin.saveStudentsToFile(st, c_student);
                      }
                      else {
                          string m;
                          cout << "invalid input ! try again\n";
                          cout << "press any key to back to menu\n";
                          cin >> m;
                          continue;
                      }
                  }
              }
              else {
                  puts("\n");
                  string k;
                  cout << "wrong username or password !\n" << endl;
                  cout << "press any key to back to menu \n";
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
              if (admin.login_teacher(te, user_, pass_, c_teacher)) {

              }
          }
          else if (input == "3") {
              string user_;
              string pass_;
              cout << "Enter your username : ";
              cin >> user_;
              cout << "Enter your password : ";
              cin >> pass_;
              if (admin.login_student(st, user_, pass_, c_student)) {

              }
          }
          else if (input == "4") {
              break;
          }
          else {
              string m;
              cout << "invalid input ! try again\n";
              cout << "press any key to back to menu\n";
              cin >> m;
              continue;
          }

      }// End while

  return 0;
}

 
