#include"admin.h"
#include <fstream>
//#include<iostream>
#include <string>
using namespace std;

Admin::Admin() {

}

Admin::~Admin() {
	// nothing now
}

void Admin::saveTeachersToFile(const Teacher te[], int count) {
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
void Admin::readTeachersFromFile(Teacher te[], int& count) {
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
void Admin::saveStudentsToFile(const Student st[], int count) {
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
void Admin::readStudentsFromFile(Student st[], int& count) {
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

void Admin::removeTeacher(Teacher te[], int& count, const string& usernameToRemove) {
    // Find the teacher with the given username
    int indexToRemove = -1;
    for (int i = 0; i < count; ++i) {
        if (te[i].get_username() == usernameToRemove) {
            indexToRemove = i;
            break;
        }
    }

    // If teacher found, remove it
    if (indexToRemove != -1) {
        for (int i = indexToRemove; i < count - 1; ++i) {
            te[i] = te[i + 1];
        }
        count--;
        cout << "Teacher with username " << usernameToRemove << " removed successfully." << endl;
    }
    else {
        cout << "Teacher with username " << usernameToRemove << " not found." << endl;
    }
}

void Admin::removeStudent(Student st[], int& count, const string& usernameToRemove) {
    // Find the student with the given username
    int indexToRemove = -1;
    for (int i = 0; i < count; ++i) {
        if (st[i].get_username() == usernameToRemove) {
            indexToRemove = i;
            break;
        }
    }

    // If student found, remove it
    if (indexToRemove != -1) {
        for (int i = indexToRemove; i < count - 1; ++i) {
            st[i] = st[i + 1];
        }
        count--;
        cout << "Student with username " << usernameToRemove << " removed successfully." << endl;
    }
    else {
        cout << "Student with username " << usernameToRemove << " not found." << endl;
    }
}

bool Admin::login_student(Student st[] , string user, string pass , int count) {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (st[i].get_username() == user && st[i].get_password()==pass) {
            index = i;
            return true;
        }
    }
    if (index == -1) { 
     cout << "Wrong username or password ):\n\n"; 
     return false;
    }
}

bool Admin::login_teacher(Teacher te[] , string user , string pass , int count) {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (te[i].get_username() == user && te[i].get_password()==pass) {
            index = i;
            return true;
        }
    }
    if (index == -1) {
        cout << "Wrong username or password ):\n\n";
        return false;
    }
}

Student Admin::find_student(Student st[], string user, int count) {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (st[i].get_username() == user) {
            index = i;
            return st[index];
        }
    }
    if (index == -1) { cout << "Student cant find ):\n\n";  }
}

Teacher Admin::find_teacher(Teacher te[], string user, int count) {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (te[i].get_username() == user) {
            index = i;
            return te[index];
        }
    }
    if (index == -1) { cout << "Teacher cant find ):\n\n";  }
}

int Admin::find_index_student(Student st[], string user, int count) {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (st[i].get_username() == user) {
            index = i;
            return index;
        }
    }
    if (index == -1) { cout << "Student cant find ):\n\n"; return -1; }
}

int Admin::find_index_teacher(Teacher te[], string user, int count) {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (te[i].get_username() == user) {
            index = i;
            return index;
        }
    }
    if (index == -1) { cout << "Teacher cant find ):\n\n"; return -1; }
}

void Admin::change_pass_student(Student st[], string user, string newpass, int count) {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (st[i].get_username() == user) {
            index = i;
        }
    }
    if (index != -1) {
        st[index].set_password(newpass);
        cout << "Your password changed successfully\n";
    }
}

void Admin::change_pass_teacher(Teacher te[], string user, string newpass, int count) {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (te[i].get_username() == user) {
            index = i;
        }
    }
    if (index != -1) {
        te[index].set_password(newpass);
        cout << "Your password changed successfully\n";
    }
}

void Admin::restore_student() {



}

void Admin::restore_teacher() {



}