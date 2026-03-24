#include "rating.h"
#include <iostream>
using namespace std;

Rating::Rating(int studentId, const string& movieTitle, double score)
    : studentId(studentId), movieTitle(movieTitle) {

    if (score < 0.0 || score > 5.0) {
        cout << "잘못된 별점 → 0으로 설정" << endl;
        this->score = 0.0;
    } else {
        this->score = score;
    }
}

int Rating::getStudentId() const { return studentId; }
string Rating::getMovieTitle() const { return movieTitle; }
double Rating::getScore() const { return score; }

void Rating::display() const {
    cout << "학번: " << studentId
         << " | 영화: " << movieTitle
         << " | 별점: " << score << endl;
}