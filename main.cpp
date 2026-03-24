#include <iostream>
#include <vector>
#include "movie.h"
#include "user.h"
#include "rating.h"

using namespace std;

int main() {

    vector<Movie> movies;

    movies.emplace_back(1, "Inception", "SF", 2010);
    movies.emplace_back(2, "Parasite", "Thriller", 2019);

    movies[0].addRating(4.5);
    movies[0].addRating(5.0);
    movies[1].addRating(4.8);

    cout << "=== 영화 목록 ===" << endl;
    for (const Movie& m : movies) {
        m.display();
    }

    cout << endl;

    User u1("Soongsil", "Jihun", 20261234, "jihun@email.com");
    User u2("Soongsil", "Minji", 20264567, "minji@email.com");

    cout << "=== 사용자 목록 ===" << endl;
    u1.display();
    u2.display();

    cout << endl;

    Rating r1(20261234, "Inception", 4.5);
    Rating r2(20264567, "Parasite", 5.0);
    Rating r3(20261234, "Parasite", 6.0); // 유효성 테스트

    cout << "=== 평점 기록 ===" << endl;
    r1.display();
    r2.display();
    r3.display();

    cout << endl;

    return 0;
}