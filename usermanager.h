#pragma once
#include <vector>
#include "user.h"

class UserManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& u);
    void printAll() const;
};