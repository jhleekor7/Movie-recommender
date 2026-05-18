#include <iostream>
#include <vector>

#include "Rating.h"
#include "SimilarityCalculator.h"

using namespace std;

int main() {

    vector<Rating> user1 = {
        Rating(1, 101, 5),
        Rating(1, 102, 4),
        Rating(1, 103, 3)
    };

    vector<Rating> user2 = {
        Rating(2, 101, 5),
        Rating(2, 102, 5),
        Rating(2, 104, 4)
    };

    vector<Rating> user3 = {
        Rating(3, 101, 1),
        Rating(3, 102, 2),
        Rating(3, 105, 5)
    };

    int sim12 =
        SimilarityCalculator::calculate(user1, user2);

    int sim13 =
        SimilarityCalculator::calculate(user1, user3);

    cout << "--- 유사도 계산 ---" << endl;

    cout << "User 1 - User 2 : "
         << sim12 << endl;

    cout << "User 1 - User 3 : "
         << sim13 << endl;

    if (sim12 > sim13) {
        cout << "→ User 1과 가장 비슷한 사람: User 2"
             << endl;
    }
    else {
        cout << "→ User 1과 가장 비슷한 사람: User 3"
             << endl;
    }

    return 0;
}