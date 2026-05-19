#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>

using namespace std;

int main() {

    mkdir("data", 0755);

    cout << "data 디렉토리 생성 완료\n";

    // movies.csv
    {
        ofstream file("data/movies.csv");

        if (!file.is_open()) {
            cerr << "movies.csv 생성 실패\n";
            return 1;
        }

        file << "id,title,genre,year\n";

        file << "1,Inception,SF,2010\n";
        file << "2,Parasite,Thriller,2019\n";
        file << "3,Interstellar,SF,2014\n";
        file << "4,The Matrix,Action,1999\n";
        file << "5,Oldboy,Mystery,2003\n";

        file.close();

        cout << "movies.csv 생성 완료\n";
    }

    // users.csv
    {
        ofstream file("data/users.csv");

        if (!file.is_open()) {
            cerr << "users.csv 생성 실패\n";
            return 1;
        }

        file << "school,name,studentId,email\n";

        file << "SSU,Lee,1001,a@a.com\n";
        file << "SSU,Kim,1002,b@b.com\n";
        file << "CAU,Park,1003,c@c.com\n";

        file.close();

        cout << "users.csv 생성 완료\n";
    }

    // ratings.csv
    {
        ofstream file("data/ratings.csv");

        if (!file.is_open()) {
            cerr << "ratings.csv 생성 실패\n";
            return 1;
        }

        file << "studentId,movieTitle,score\n";

        file << "1001,Inception,5\n";
        file << "1001,Parasite,4\n";
        file << "1001,Interstellar,5\n";

        file << "1002,Inception,4\n";
        file << "1002,Interstellar,5\n";
        file << "1002,The Matrix,3\n";

        file << "1003,Parasite,5\n";
        file << "1003,Oldboy,4\n";
        file << "1003,The Matrix,5\n";

        file.close();

        cout << "ratings.csv 생성 완료\n";
    }

    cout << "\nCSV 파일 준비 완료\n";

    return 0;
}