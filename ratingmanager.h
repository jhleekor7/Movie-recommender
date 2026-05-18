#pragma once

#include <vector>
#include <string>

#include "rating.h"

class RatingManager {

private:
    std::vector<Rating> ratings;

public:
    void addRating(const Rating& r);

    void printAll() const;

    void printByMovie(const std::string& movieTitle) const;

    std::vector<Rating> getRatingsByUser(int studentId) const;

    std::vector<Rating> getAllRatings() const;
};