all:
	g++ -c -std=gnu++11 Relation.cpp
	g++ -o Relation Relation.o
	./Relation
