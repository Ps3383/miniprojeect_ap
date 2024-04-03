
#include <iostream>
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


int main()
{
//    Student* st;
  //  st = new Student[100];
  //  Teacher* te;
  //  te = new Teacher[100];
    Student st[2000];
    Teacher te[100];
    int c_teacher = 0;
    int c_student = 0;

  string input;
  while (true) {
      system("cls");
      cout << "press 1 to login to admin account\n";
      cout << "press 2 to login to teacher account\n";
      cout << "press 3 to login to student account\n";
	  cin >> input;

    if (!isInteger(input)) {
          cout << "invalid input ! try again\n"<<endl;
          continue;
    }
      if (input == "1") {
          string u_name;
          string pass;
          cout << "Enter username : ";
          cin >> u_name;
          cout << "Enter password : ";
          cin >> pass;
             if (u_name == "admin" && pass == "admin") {
                 string command;
                 while (true) {
                     system("cls");
                     cout << "press 1 to add teacher\n";
                     cout << "press 2 to delete teacher\n";
                     cout << "press 3 to add student\n";
                     cout << "press 4 to delete student\n";
                     cout << "press 5 to exit \n";
                     cin >> command;
                     if (!isInteger(command)) {
                         cout << "invalid input ! try again" << endl;
                         continue;
                     }
                     if (command == "5") {
                         break;
                     }
                     else if (command == "1") {

                     }
                     else if (command == "2") {

                     }
                     else if (command == "3") {

                     }
                     else if (command == "4") {

                     }
                     else {
                         cout << "invalid input ! try again\n";
                         continue;
                     }
                 }
             }
             else {
                 puts("\n");
                 cout << "wrong username or password !\n" << endl;
                 continue;
              }
      }
      else if (input == "2") {

      }
      else if (input == "3") {

      }
      else {
          cout << "invalid input ! try again\n";
          continue;
      }

      







  }
  return 0;
}

 
