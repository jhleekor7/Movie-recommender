#include "Rating.h"

Rating::Rating(int u, int m, int s)
    : userId(u), movieId(m), score(s) {}

int Rating::getUserId() const {
    return userId;
}

int Rating::getMovieId() const {
    return movieId;
}

int Rating::getScore() const {
    return score;
}