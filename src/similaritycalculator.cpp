#include "similaritycalculator.h"

#include <cstdlib>

int SimilarityCalculator::calculate(
    const std::vector<Rating>& ratingsA,
    const std::vector<Rating>& ratingsB
) {
    int commonCount = 0;
    int diffSum = 0;

    for (const Rating& a : ratingsA) {
        for (const Rating& b : ratingsB) {

            if (a.getMovieTitle() == b.getMovieTitle()) {

                commonCount++;

                diffSum += abs(a.getScore() - b.getScore());
            }
        }
    }

    if (commonCount == 0) {
        return -1;
    }

    return commonCount * 10 - diffSum;
}