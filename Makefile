main: knights.o
	g++ -o main knights.o

knights.o: knights.cpp
	g++ -c knights.cpp

clean: 
	rm -f main knights knights.o