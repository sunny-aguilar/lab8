# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	March 1, 2019
# Description:	Makefile for Lab 8

# Variables to control Makefile operation

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += menu.o
OBJECTS += searchSort.o

HPPs = menu.hpp
HPPs = searchSort.hpp

CPPs = main.cpp
CPPs = menu.cpp
CPPs += searchSort.cpp


# Targets needed to bring the executable up to date
Search: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o Search $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

menu.o: menu.hpp

searchSort.o: searchSort.hpp


# Clean-up operations
clean:
	rm Search *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./Search

zip:
	zip -D Lab8_Aguilar_Sandro.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf
