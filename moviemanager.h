#pragma once
#include <vector>
#include <string>
#include "movie.h"

class MovieManager {
private:
    std::vector<Movie> movies;

public:
    void addMovie(const Movie& m);
    void printAll() const;
    void searchByTitle(const std::string& title) const;
    void sortByRating();
};
