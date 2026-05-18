#ifndef RATING_H
#define RATING_H

class Rating {
private:
    int userId;
    int movieId;
    int score;

public:
    Rating(int u, int m, int s);

    int getUserId() const;
    int getMovieId() const;
    int getScore() const;
};

#endif