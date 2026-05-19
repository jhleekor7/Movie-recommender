#pragma once
#include <string>
using namespace std;

class Rating {
private:
    int studentId;
    string movieTitle;
    double score;

public:
    Rating(int studentId, const string& movieTitle, double score);

    int getStudentId() const;
    string getMovieTitle() const;
    double getScore() const;

    void display() const;
};