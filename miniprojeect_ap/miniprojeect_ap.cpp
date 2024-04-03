
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
void saveTeachersToFile(const Teacher te[], int count) {
    ofstream outFile("teachers.txt");
    if (!outFile) {
        cerr << "Error: Unable to open file teachers.txt" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        outFile << te[i].get_name() << ',' << te[i].get_username() << ',' << te[i].get_password() << '\n';
    }

    outFile.close();
    cout << "Teachers data saved to file successfully." << endl;
}

// Function to read teachers data from file
void readTeachersFromFile(Teacher te[], int& count) {
    ifstream inFile("teachers.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file teachers.txt" << endl;
        return;
    }

    count = 0;
    string line;
    while (getline(inFile, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        string name = line.substr(0, pos1);
        string username = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string password = line.substr(pos2 + 1);
        te[count].set_name(name);
        te[count].set_username(username);
        te[count].set_password(password);
        count++;
    }

    inFile.close();
    cout << "Teachers data read from file successfully." << endl;
}
void saveStudentsToFile(const Student st[], int count) {
    ofstream outFile("students.txt");
    if (!outFile) {
        cerr << "Error: Unable to open file students.txt" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        outFile << st[i].get_name() << ',' << st[i].get_username() << ',' << st[i].get_password() << '\n';
    }

    outFile.close();
    cout << "Students data saved to file successfully." << endl;
}

// Function to read students data from file
void readStudentsFromFile(Student st[], int& count) {
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file students.txt" << endl;
        return;
    }

    count = 0;
    string line;
    while (getline(inFile, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        string name = line.substr(0, pos1);
        string username = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string password = line.substr(pos2 + 1);
        st[count].set_name(name);
        st[count].set_username(username);
        st[count].set_password(password);
        count++;
    }

    inFile.close();
    cout << "Students data read from file successfully." << endl;
}


int main() {

    Student st[2000];
    Teacher te[100];
    int c_teacher = 0;
    int c_student = 0;
    readTeachersFromFile(te, c_teacher);
    readStudentsFromFile(st, c_student);
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
                          saveTeachersToFile(te, c_teacher);
                      }
                      else if (command == "2") {
                          string user;
                          cout << "Enter teacher_username that you want to delete : ";
                          cin >> user;

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
                          saveStudentsToFile(st, c_student);
                      }
                      else if (command == "4") {

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

          }
          else if (input == "3") {

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

      }// end while

  return 0;
}

 
