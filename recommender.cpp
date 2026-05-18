#include "recommender.h"
#include "similaritycalculator.h"

#include <iostream>
#include <set>

Recommender::Recommender(
    MovieManager& mm,
    RatingManager& rm
)
    : movieMgr(mm), ratingMgr(rm) {
}

void Recommender::recommendMovies(int userId) {

    std::vector<Rating> myRatings =
        ratingMgr.getRatingsByUser(userId);

    if (myRatings.empty()) {

        std::cout << "평점 데이터가 없습니다.\n";

        return;
    }

    std::vector<Rating> allRatings =
        ratingMgr.getAllRatings();

    std::set<int> otherUsers;

    for (const Rating& r : allRatings) {

        if (r.getStudentId() != userId) {

            otherUsers.insert(r.getStudentId());
        }
    }

    std::cout << "\n=== 유사도 결과 ===\n";

    int bestUser = -1;
    int bestSimilarity = -1;

    for (int otherId : otherUsers) {

        std::vector<Rating> otherRatings =
            ratingMgr.getRatingsByUser(otherId);

        int similarity =
            SimilarityCalculator::calculate(
                myRatings,
                otherRatings
            );

        std::cout
            << "사용자 "
            << otherId
            << " 와의 유사도: "
            << similarity
            << "\n";

        if (similarity > bestSimilarity) {

            bestSimilarity = similarity;
            bestUser = otherId;
        }
    }

    if (bestUser == -1) {

        std::cout << "추천할 사용자가 없습니다.\n";

        return;
    }

    std::vector<Rating> bestRatings =
        ratingMgr.getRatingsByUser(bestUser);

    std::set<std::string> watchedMovies;

    for (const Rating& r : myRatings) {

        watchedMovies.insert(r.getMovieTitle());
    }

    std::cout << "\n=== 추천 영화 ===\n";

    bool recommended = false;

    for (const Rating& r : bestRatings) {

        if (
            watchedMovies.find(r.getMovieTitle())
            == watchedMovies.end()
        ) {

            std::cout
                << r.getMovieTitle()
                << "\n";

            recommended = true;
        }
    }

    if (!recommended) {

        std::cout << "추천할 영화가 없습니다.\n";
    }
}