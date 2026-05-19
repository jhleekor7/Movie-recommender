#include "ratingmanager.h"

#include <iostream>

void RatingManager::addRating(const Rating& r) {
    ratings.push_back(r);
}

void RatingManager::printAll() const {

    if (ratings.empty()) {
        std::cout << "등록된 평점이 없습니다.\n";
        return;
    }

    for (const Rating& r : ratings) {

        std::cout
            << "학번: "
            << r.getStudentId()
            << ", 영화: "
            << r.getMovieTitle()
            << ", 점수: "
            << r.getScore()
            << "\n";
    }
}

void RatingManager::printByMovie(const std::string& movieTitle) const {

    bool found = false;

    for (const Rating& r : ratings) {

        if (r.getMovieTitle() == movieTitle) {

            std::cout
                << "학번: "
                << r.getStudentId()
                << ", 영화: "
                << r.getMovieTitle()
                << ", 점수: "
                << r.getScore()
                << "\n";

            found = true;
        }
    }

    if (!found) {
        std::cout << "해당 영화의 평점이 없습니다.\n";
    }
}

std::vector<Rating> RatingManager::getRatingsByUser(int studentId) const {

    std::vector<Rating> result;

    for (const Rating& r : ratings) {

        if (r.getStudentId() == studentId) {

            result.push_back(r);
        }
    }

    return result;
}
std::vector<Rating> RatingManager::getAllRatings() const {
    return ratings;
}
void RatingManager::loadFromFile(const std::string& filename) {
}

void RatingManager::saveToFile(const std::string& filename) const {
}

int RatingManager::size() const {
    return ratings.size();
}