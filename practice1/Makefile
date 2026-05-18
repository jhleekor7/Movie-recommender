TARGET = recommend

OBJS = main.o Rating.o SimilarityCalculator.o

$(TARGET): $(OBJS)
	g++ $(OBJS) -o $(TARGET)

main.o: main.cpp
	g++ -c main.cpp

Rating.o: Rating.cpp
	g++ -c Rating.cpp

SimilarityCalculator.o: SimilarityCalculator.cpp
	g++ -c SimilarityCalculator.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)