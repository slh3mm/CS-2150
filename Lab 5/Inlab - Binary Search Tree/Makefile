CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g

BSTPathTest: BSTPathTest.o BinarySearchTree.o BinaryNode.o
	$(CXX) $(DEBUG) BSTPathTest.o BinarySearchTree.o BinaryNode.o
	@echo "Program Executable Ready to go"

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
