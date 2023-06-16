CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG = -g

TreeCalcTest: TreeCalc.o TreeNode.o TreeCalcTest.o
	$(CXX) $(DEBUG) TreeCalc.o TreeNode.o TreeCalcTest.o
	@echo "hello there!"

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeNode.o:TreeNode.cpp TreeNode.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
