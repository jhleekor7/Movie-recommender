#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include "moviemanager.h"
#include "ratingmanager.h"

class Recommender {
private:
    MovieManager& movieMgr;
    RatingManager& ratingMgr;

public:
    Recommender(
        MovieManager& mm,
        RatingManager& rm
    );

    void recommendMovies(int userId);
};

#endif