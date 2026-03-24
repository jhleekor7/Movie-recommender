all: movie

movie: main.o movie.o
	g++ -o movie main.o movie.o

main.o: main.cpp
	g++ -c main.cpp

movie.o: movie.cpp
	g++ -c movie.cpp

clean:
	rm -f *.o movieS