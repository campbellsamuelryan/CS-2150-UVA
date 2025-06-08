# Samuel Campbell, CS2150
CXX=clang++ $(CXXFLAGS)
CXXFLAGS= -Wall -o2
DEBUG=-g

OBJECTS = BinaryNode.o BinarySearchTree.o BSTPathTest.o

tree: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
	
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
