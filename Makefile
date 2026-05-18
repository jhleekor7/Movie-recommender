CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = movie_recommender

OBJS = main.o movie.o user.o rating.o \
moviemanager.o usermanager.o ratingmanager.o \
similaritycalculator.o recommender.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp movie.h user.h rating.h moviemanager.h usermanager.h ratingmanager.h recommender.h
	$(CXX) $(CXXFLAGS) -c main.cpp

movie.o: movie.cpp movie.h
	$(CXX) $(CXXFLAGS) -c movie.cpp

user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c user.cpp

rating.o: rating.cpp rating.h
	$(CXX) $(CXXFLAGS) -c rating.cpp

moviemanager.o: moviemanager.cpp moviemanager.h
	$(CXX) $(CXXFLAGS) -c moviemanager.cpp

usermanager.o: usermanager.cpp usermanager.h
	$(CXX) $(CXXFLAGS) -c usermanager.cpp

ratingmanager.o: ratingmanager.cpp ratingmanager.h
	$(CXX) $(CXXFLAGS) -c ratingmanager.cpp

similaritycalculator.o: similaritycalculator.cpp similaritycalculator.h
	$(CXX) $(CXXFLAGS) -c similaritycalculator.cpp

recommender.o: recommender.cpp recommender.h
	$(CXX) $(CXXFLAGS) -c recommender.cpp

clean:
	rm -f *.o $(TARGET)