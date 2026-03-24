#pragma once
#include <string>
using namespace std;

class User {
private:
    string school;
    string name;
    int studentId;
    string email;

public:
    User(const string& school,
         const string& name,
         int studentId,
         const string& email);

    string getSchool() const;
    string getName() const;
    int getStudentId() const;
    string getEmail() const;

    void display() const;
};