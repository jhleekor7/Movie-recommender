#pragma once
#include <vector>
#include "rating.h"

class RatingManager {
private:
    std::vector<Rating> ratings;

public:
    void addRating(const Rating& r);
    void printByMovie(const std::string& movieTitle) const;
};