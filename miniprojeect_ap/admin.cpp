#include"admin.h"
#include <fstream>
#include<iostream>
#include <string>
using namespace std;

Admin::Admin() {

}

Admin::~Admin() {
	// nothing now
}

void Admin::saveTeachersToFile(const Teacher te[], int count, map<string, vector<string>> courses, map<string, map<string, int>> grades) {
    ofstream outFile("teachers.txt");
    if (!outFile) {
        cerr << "Error: Unable to open file teachers.txt" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        outFile << te[i].get_name() << ',' << te[i].get_username() << ',' << te[i].get_password() << '\n';
    }
    ////////////
    for (const auto& courseEntry : courses) {
        string courseName = courseEntry.first;
        const vector<string>& students = courseEntry.second;
        for (const auto& student : students) {
            int grade = grades[courseName][student];
            outFile << courseName << "," << student << "," << grade << "\n";
        }
    }
    //////////////

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
    ////////////
        // Read courses, students, and grades
    while (getline(inFile, line)) {
        if (line.empty()) // Check for empty line, indicating end of teacher's data
            break;

        size_t pos = line.find(',');
        string courseName = line.substr(0, pos);
        string studentUsername = line.substr(pos + 1);
        te[count].addStudentToCourse(courseName, studentUsername); // Assume you have a function to add student to course
        // Read grade and add it to the teacher's data
        // Assuming the grade is the next entry in the file
        getline(inFile, line);
        int grade = stoi(line);
        te[count].recordGrade(courseName, studentUsername, grade); // Assume you have a function to record grades
    }
    ////////////

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

int Admin::find_index_teacher_name(Teacher te[], string name, int count) {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (te[i].get_name() == name) {
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

void Admin::softDeleteTeacher(const string& username) {
    // Open teachers.txt file to read from
    ifstream inFile("teachers.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file teachers.txt" << endl;
        return;
    }

    // Open restore_teachers.txt file to append to
    ofstream outFile("restore_teachers.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file restore_teachers.txt" << endl;
        return;
    }

    string line;
    bool found = false;

    // Read each line from teachers.txt
    while (getline(inFile, line)) {
        // Check if the line contains the username
        if (line.find(username) != string::npos) {
            // Write the line to restore_teachers.txt
            outFile << line << '\n';
            found = true;
        }
    }

    // Close the files
    inFile.close();
    outFile.close();

    if (found) {
        cout << "Teacher data moved to restore_teachers.txt successfully." << endl;
    }
    else {
        cout << "Error: Teacher not found." << endl;
    }
}


void Admin::restoreTeacher(const string& username) {
    // Open restore_teachers.txt file to read from
    ifstream inFile("restore_teachers.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file restore_teachers.txt" << endl;
        return;
    }

    // Open teachers.txt file to append to
    ofstream outFile("teachers.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file teachers.txt" << endl;
        return;
    }

    string line;
    bool found = false;

    // Read each line from restore_teachers.txt
    while (getline(inFile, line)) {
        // Check if the line contains the username
        if (line.find(username) != string::npos) {
            // Write the line to teachers.txt
            outFile << line << '\n';
            found = true;
        }
    }

    // Close the files
    inFile.close();
    outFile.close();

    if (found) {
        cout << "Teacher with username " << username << " restored successfully." << endl;
    }
    else {
        cout << "Error: Teacher with username " << username << " not found in restore file." << endl;
    }
}

void Admin::removeRestoredTeacher(const string& username) {
    ifstream inFile("restore_teachers.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file restore_teachers.txt" << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error: Unable to open temporary file temp.txt" << endl;
        inFile.close();
        return;
    }

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.find(username) == string::npos) {
            tempFile << line << '\n';
        }
        else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("restore_teachers.txt");
    rename("temp.txt", "restore_teachers.txt");

    if (found) {
        cout << "Information of the restored teacher with username " << username << " removed successfully from restore file." << endl;
    }
    else {
        cout << "Error: Teacher with username " << username << " not found in restore file." << endl;
    }
}

void Admin::softDeleteStudent(const string& username) {
    // Open teachers.txt file to read from
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file students.txt" << endl;
        return;
    }

    // Open restore_teachers.txt file to append to
    ofstream outFile("restore_students.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file restore_students.txt" << endl;
        return;
    }

    string line;
    bool found = false;

    // Read each line from teachers.txt
    while (getline(inFile, line)) {
        // Check if the line contains the username
        if (line.find(username) != string::npos) {
            // Write the line to restore_teachers.txt
            outFile << line << '\n';
            found = true;
        }
    }

    // Close the files
    inFile.close();
    outFile.close();

    if (found) {
        cout << "student data moved to restore_students.txt successfully." << endl;
    }
    else {
        cout << "Error: student not found." << endl;
    }
}

void Admin::restoreStudent(const string& username) {
    // Open restore_teachers.txt file to read from
    ifstream inFile("restore_students.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file restore_students.txt" << endl;
        return;
    }

    // Open teachers.txt file to append to
    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file students.txt" << endl;
        return;
    }

    string line;
    bool found = false;

    // Read each line from restore_teachers.txt
    while (getline(inFile, line)) {
        // Check if the line contains the username
        if (line.find(username) != string::npos) {
            // Write the line to teachers.txt
            outFile << line << '\n';
            found = true;
        }
    }

    // Close the files
    inFile.close();
    outFile.close();

    if (found) {
        cout << "student with username " << username << " restored successfully." << endl;
    }
    else {
        cout << "Error: student with username " << username << " not found in restore file." << endl;
    }

}

void Admin::removeRestoredStudent(const string& username) {
    ifstream inFile("restore_students.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file restore_students.txt" << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error: Unable to open temporary file temp.txt" << endl;
        inFile.close();
        return;
    }

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.find(username) == string::npos) {
            tempFile << line << '\n';
        }
        else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    remove("restore_students.txt");
    rename("temp.txt", "restore_students.txt");

    if (found) {
        cout << "Information of the restored student with username " << username << " removed successfully from restore file." << endl;
    }
    else {
        cout << "Error: student with username " << username << " not found in restore file." << endl;
    }
}



