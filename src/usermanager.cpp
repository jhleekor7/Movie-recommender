#include "usermanager.h"
#include <iostream>

void UserManager::addUser(const User& u) {
    users.push_back(u);
}

void UserManager::printAll() const {
    if (users.empty()) {
        std::cout << "등록된 사용자가 없습니다.\n";
        return;
    }
    for (const User& u : users) {
        u.display();
    }
}
void UserManager::loadFromFile(const std::string& filename) {
}

void UserManager::saveToFile(const std::string& filename) const {
}

int UserManager::size() const {
    return users.size();
}
