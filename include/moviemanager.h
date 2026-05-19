#pragma once
#include <vector>
#include <string>
#include "movie.h"
#include "BaseManager.h"

class MovieManager : public BaseManager{
private:
    std::vector<Movie> movies;

public:
    void addMovie(const Movie& m);
    void printAll() const;
    void searchByTitle(const std::string& title) const;
    void sortByRating();
    void saveToFile(const std::string& filename) const override;
    void loadFromFile(const std::string& filename) override;
    int size() const override;
};
