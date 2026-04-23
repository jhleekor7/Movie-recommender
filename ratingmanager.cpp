#include "ratingmanager.h"
#include <iostream>

void RatingManager::addRating(const Rating& r) {
    ratings.push_back(r);
}

void RatingManager::printByMovie(const std::string& movieTitle) const {
    bool found = false;
    for (const Rating& r : ratings) {
        if (r.getMovieTitle() == movieTitle) {
            r.display();
            found = true;
        }
    }
    if (!found) std::cout << "해당 영화의 평점이 없습니다.\n";
}