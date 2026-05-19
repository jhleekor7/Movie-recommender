#pragma once

#include <vector>
#include <string>
#include "BaseManager.h"
#include "rating.h"

class RatingManager : public BaseManager {

private:
    std::vector<Rating> ratings;

public:
    void addRating(const Rating& r);

    void printAll() const;

    void printByMovie(const std::string& movieTitle) const;
    

    std::vector<Rating> getRatingsByUser(int studentId) const;

    std::vector<Rating> getAllRatings() const;
    void loadFromFile(const std::string& filename) override;

    void saveToFile(const std::string& filename) const override;

    int size() const override;
};