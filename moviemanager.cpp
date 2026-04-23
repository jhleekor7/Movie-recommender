#include "moviemanager.h"
#include <iostream>
#include <algorithm>

void MovieManager::addMovie(const Movie& m) {
    movies.push_back(m);
}

void MovieManager::printAll() const {
    if (movies.empty()) {
        std::cout << "등록된 영화가 없습니다.\n";
        return;
    }
    for (const Movie& m : movies) {
        std::cout << m << "\n";
    }
}

void MovieManager::searchByTitle(const std::string& title) const {
    bool found = false;
    for (const Movie& m : movies) {
        if (m.getTitle() == title) {
            std::cout << m << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "검색 결과가 없습니다.\n";
}

void MovieManager::sortByRating() {
    std::sort(movies.begin(), movies.end(), [](const Movie& a, const Movie& b) {
        return a.getAverageRating() > b.getAverageRating(); // 높은 평점순
    });
    printAll();
}