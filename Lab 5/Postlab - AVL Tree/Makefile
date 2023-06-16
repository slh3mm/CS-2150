CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g

AVLPathTest: AVLPathTest.o AVLTree.o AVLNode.o
	$(CXX) $(DEBUG) AVLPathTest.o AVLTree.o AVLNode.o
	@echo "Program Executable Ready to go"

AVLNode.o: AVLNode.cpp AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
