all: compile link run

compile:
	g++ -c main.cpp -I"C:\Users\carlo\Documents\SFML-2.5.1\include"

link:
	g++ main.o -o main -L"C:\Users\carlo\Documents\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system

run:
	./main