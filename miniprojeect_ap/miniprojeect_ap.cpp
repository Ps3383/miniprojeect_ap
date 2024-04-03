
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
    Student* st;
    st = new Student[100];
    Teacher* te;
    te = new Teacher[100];

  string input;
  cout << "press 1 to login to admin account\n";
  cout << "press 2 to login to teacher account\n";
  cout << "press 3 to login to student account\n";
  while (true) {
	  cin >> input;

      if (!isInteger(input)) {
          cout << "invalid input ! try again\n";
          continue;
      }
      if (input == "1") {

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

 
