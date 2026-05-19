#include "recommender.h"
#include "similaritycalculator.h"

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

Recommender::Recommender(
    MovieManager& mm,
    RatingManager& rm
)
    : movieMgr(mm), ratingMgr(rm) {
}

void Recommender::recommendMovies(int userId) {

    std::vector<Rating> myRatings =
        ratingMgr.getRatingsByUser(userId);

    // 엣지 케이스 1
    // 평점 데이터가 없는 경우

    if (myRatings.empty()) {

        std::cout
            << "평점 데이터가 없습니다.\n";

        return;
    }

    std::vector<Rating> allRatings =
        ratingMgr.getAllRatings();

    std::set<int> otherUsers;

    // 다른 사용자 수집

    for (const Rating& r : allRatings) {

        if (r.getStudentId() != userId) {

            otherUsers.insert(
                r.getStudentId()
            );
        }
    }

    // 엣지 케이스 2
    // 다른 사용자가 없는 경우

    if (otherUsers.empty()) {

        std::cout
            << "다른 사용자가 없습니다.\n";

        return;
    }

    std::cout
        << "\n=== 유사도 결과 ===\n";

    std::vector<
        std::pair<int, int>
    > similarities;

    // 유사도 계산

    for (int otherId : otherUsers) {

        std::vector<Rating> otherRatings =
            ratingMgr.getRatingsByUser(
                otherId
            );

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

        similarities.push_back(
            {otherId, similarity}
        );
    }

    // 유사도 내림차순 정렬

    std::sort(
        similarities.begin(),
        similarities.end(),

        [](const std::pair<int, int>& a,
           const std::pair<int, int>& b) {

            return a.second > b.second;
        }
    );

    // 내가 본 영화 저장

    std::set<std::string> watchedMovies;

    for (const Rating& r : myRatings) {

        watchedMovies.insert(
            r.getMovieTitle()
        );
    }

    // 추천 점수 저장

    std::map<std::string, double>
        movieScores;

    // 상위 K명 사용자 사용

    const size_t K = 3;

    for (
        size_t i = 0;
        i < similarities.size() && i < K;
        i++
    ) {

        int otherUserId =
            similarities[i].first;

        int similarityScore =
            similarities[i].second;

        // 유사도 0 이하 제외

        if (similarityScore <= 0) {

            continue;
        }

        std::vector<Rating> otherRatings =
            ratingMgr.getRatingsByUser(
                otherUserId
            );

        for (const Rating& r : otherRatings) {

            std::string title =
                r.getMovieTitle();

            // 내가 안 본 영화만 추천

            if (
                watchedMovies.find(title)
                == watchedMovies.end()
            ) {

                // 가중 추천 점수 계산

                movieScores[title]
                    += similarityScore
                       * r.getScore();
            }
        }
    }

    // 엣지 케이스 3
    // 추천 영화가 없는 경우

    if (movieScores.empty()) {

        std::cout
            << "\n추천할 영화가 없습니다.\n";

        return;
    }

    // map → vector 변환

    std::vector<
        std::pair<std::string, double>
    > sortedMovies(
        movieScores.begin(),
        movieScores.end()
    );

    // 추천 점수 내림차순 정렬

    std::sort(
        sortedMovies.begin(),
        sortedMovies.end(),

        [](const auto& a,
           const auto& b) {

            return a.second > b.second;
        }
    );

    std::cout
        << "\n=== 추천 영화 ===\n";

    // 상위 N개 추천

    const size_t N = 5;

    for (
        size_t i = 0;
        i < sortedMovies.size() && i < N;
        i++
    ) {

        std::cout
            << sortedMovies[i].first
            << " (추천 점수: "
            << sortedMovies[i].second
            << ")\n";
    }
}