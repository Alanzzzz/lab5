main: main.o
	g++ -o Lab5 main.o
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm Lab5 *.o
