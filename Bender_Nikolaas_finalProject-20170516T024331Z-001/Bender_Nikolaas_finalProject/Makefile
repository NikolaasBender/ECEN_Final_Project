# Variables
MDR = ../master
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -std=c++0x -pedantic -g
All: fnlPrjct
fnlPrjct: fnlPrjct.o readingTools.o smplrdt.o
	$(CXX) $(CXXFLAGS) -o fnlPrjct fnlPrjct.o readingTools.o smplrdt.o
fnlPrjct.o: fnlPrjct.cpp readingTools.hpp smplrdt.hpp
	$(CXX) $(CXXFLAGS) -c fnlPrjct.cpp 
readingTools.o: readingTools.cpp
	$(CXX) $(CXXFLAGS) -c readingTools.cpp
smplrdt.o : smplrdt.cpp 
	$(CXX) $(CXXFLAGS) -c smplrdt.cpp

.PHONY: clean
clean:
	$(RM) *.o

