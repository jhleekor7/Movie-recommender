#include "user.h"
#include <iostream>
using namespace std;

User::User(const string& school,
           const string& name,
           int studentId,
           const string& email)
    : school(school),
      name(name),
      studentId(studentId),
      email(email) {}

string User::getSchool() const { return school; }
string User::getName() const { return name; }
int User::getStudentId() const { return studentId; }
string User::getEmail() const { return email; }

void User::display() const {
    cout << "학교: " << school << endl;
    cout << "이름: " << name << endl;
    cout << "학번: " << studentId << endl;
    cout << "이메일: " << email << endl;
}