#include <iostream>
#include <limits>

#include "movie.h"
#include "user.h"
#include "rating.h"
#include "moviemanager.h"
#include "usermanager.h"
#include "ratingmanager.h"
#include "recommender.h"

using namespace std;

int main() {

    MovieManager movieMgr;
    movieMgr.loadFromFile("movies.csv");

    UserManager userMgr;
    RatingManager ratingMgr;

    Recommender recommender(movieMgr, ratingMgr);

    int choice;

    while (true) {

        cout << "\n=== Movie Recommender ===\n";

        cout << "[ 영화 ]\n";
        cout << "1. 영화 추가\n";
        cout << "2. 제목으로 검색\n";
        cout << "3. 전체 목록 출력\n";
        cout << "4. 평점순 정렬 출력\n";

        cout << "[ 사용자 ]\n";
        cout << "5. 사용자 추가\n";
        cout << "6. 사용자 목록 출력\n";

        cout << "[ 평점 ]\n";
        cout << "7. 평점 입력\n";
        cout << "8. 영화별 평점 보기\n";

        cout << "[ 추천 ]\n";
        cout << "9. 영화 추천\n";

        cout << "0. 종료\n";
        cout << "선택 > ";

        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice == 1) {

            int id, year;
            string title, genre;

            cout << "ID: ";
            cin >> id;

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "제목: ";
            getline(cin, title);

            cout << "장르: ";
            getline(cin, genre);

            cout << "연도: ";
            cin >> year;

            movieMgr.addMovie(
                Movie(id, title, genre, year)
            );

            cout << "영화가 추가되었습니다.\n";
        }

        else if (choice == 2) {

            string title;

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "검색할 제목: ";
            getline(cin, title);

            movieMgr.searchByTitle(title);
        }

        else if (choice == 3) {

            movieMgr.printAll();
        }

        else if (choice == 4) {

            movieMgr.sortByRating();
        }

        else if (choice == 5) {

            string school, name, email;
            int studentId;

            cout << "학교: ";
            cin >> school;

            cout << "이름: ";
            cin >> name;

            cout << "학번: ";
            cin >> studentId;

            cout << "이메일: ";
            cin >> email;

            userMgr.addUser(
                User(school, name, studentId, email)
            );

            cout << "사용자가 추가되었습니다.\n";
        }

        else if (choice == 6) {

            userMgr.printAll();
        }

        else if (choice == 7) {

            int studentId;
            string movieTitle;
            double score;

            cout << "학번: ";
            cin >> studentId;

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "영화 제목: ";
            getline(cin, movieTitle);

            cout << "점수 (1~5): ";
            cin >> score;

            ratingMgr.addRating(
                Rating(studentId, movieTitle, score)
            );

            cout << "평점이 입력되었습니다.\n";
        }

        else if (choice == 8) {

            string movieTitle;

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "영화 제목: ";
            getline(cin, movieTitle);

            ratingMgr.printByMovie(movieTitle);
        }

        else if (choice == 9) {

            int userId;

            cout << "사용자 학번: ";
            cin >> userId;

            recommender.recommendMovies(userId);
        }

        else {

            cout << "잘못된 입력입니다.\n";
        }
    }

    movieMgr.saveToFile("movies.csv");

    cout << "프로그램을 종료합니다.\n";

    return 0;
}