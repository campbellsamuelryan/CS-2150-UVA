# Samuel Campbell, CS2150
CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -o2
DEBUG=-g

OBJECTS = wordPuzzle.o timer.o hashTable.o

hash: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

timer.o: timer.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp timer.h hashTable.h
