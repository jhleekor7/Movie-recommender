#pragma once
#include <vector>
#include "user.h"
#include "BaseManager.h"
class UserManager : public BaseManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& u);
    void printAll() const;
    
    void loadFromFile(const std::string& filename) override;

    void saveToFile(const std::string& filename) const override;

    int size() const override;
};