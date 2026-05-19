#include "movie.h"
#include <iostream>
using namespace std;

Movie::Movie()
    : id(0), year(0), totalRating(0.0), ratingCount(0) {}

Movie::Movie(int id, const string& t, const string& g, int y)
    : id(id), title(t), genre(g), year(y),
      totalRating(0.0), ratingCount(0) {}

void Movie::addRating(double r) {
    if (r < 0.0 || r > 5.0) {
        cout << "잘못된 평점!" << endl;
        return;
    }
    totalRating += r;
    ratingCount++;
}

double Movie::getAverageRating() const {
    if (ratingCount == 0) return 0.0;
    return totalRating / ratingCount;
}


int Movie::getId() const { return id; }
string Movie::getTitle() const { return title; }
string Movie::getGenre() const { return genre; }
int Movie::getYear() const { return year; }

bool Movie::operator<(const Movie& other) const {
    return this->title < other.title;
}

bool Movie::operator==(const Movie& other) const {
    return this->id == other.id;
}


ostream& operator<<(ostream& os, const Movie& m) {
    os << "ID: " << m.id
       << " | 제목: " << m.title
       << " | 장르: " << m.genre
       << " | 연도: " << m.year
       << " | 평점: " << m.getAverageRating();
    return os;
}
void Movie::display() const {
    cout << *this << endl;
}