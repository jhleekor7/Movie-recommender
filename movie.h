#pragma once
#include <string>
using namespace std;

class Movie {
private:
    int id;
    string title;
    string genre;
    int year;

    double totalRating; 
    int ratingCount;    

public:
    Movie();

    
    Movie(int id, const string& t, const string& g, int y);

    
    void addRating(double r);
    double getAverageRating() const;

    void display() const;

    
    int getId() const;
    string getTitle() const;
    string getGenre() const;
    int getYear() const;
};