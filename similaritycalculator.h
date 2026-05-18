#ifndef SIMILARITYCALCULATOR_H
#define SIMILARITYCALCULATOR_H

#include <vector>
#include "rating.h"

class SimilarityCalculator {
public:
    static int calculate(
        const std::vector<Rating>& ratingsA,
        const std::vector<Rating>& ratingsB
    );
};

#endif