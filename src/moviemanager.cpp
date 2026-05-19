#include "moviemanager.h"

#include <fstream>
#include <sstream>
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

    if (!found) {
        std::cout << "검색 결과가 없습니다.\n";
    }
}

void MovieManager::sortByRating() {
    std::sort(movies.begin(), movies.end(),
        [](const Movie& a, const Movie& b) {
            return a.getAverageRating() > b.getAverageRating();
        });

    printAll();
}

void MovieManager::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cout << "파일 저장 실패\n";
        return;
    }

    for (const Movie& m : movies) {
        outFile
            << m.getId() << ","
            << m.getTitle() << ","
            << m.getGenre() << ","
            << m.getYear()
            << "\n";
    }

    outFile.close();
}

void MovieManager::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cout << "파일 없음\n";
        return;
    }

    movies.clear();

    std::string line;

    while (getline(inFile, line)) {
        std::stringstream ss(line);

        std::string idStr;
        std::string title;
        std::string genre;
        std::string yearStr;

        getline(ss, idStr, ',');
        getline(ss, title, ',');
        getline(ss, genre, ',');
        getline(ss, yearStr, ',');

        int id = stoi(idStr);
        int year = stoi(yearStr);

        Movie movie(id, title, genre, year);

        movies.push_back(movie);
    }

    inFile.close();
}
int MovieManager::size() const {
    return movies.size();
}