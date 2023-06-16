CXX=clang++
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=grid.o puzzleSolver.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(CXXFLAGS) $(OBJECTS)
	doxygen
	@echo "Program Executable Ready to go!"


grid.o: grid.cpp grid.h

puzzleSolver.o: puzzleSolver.cpp grid.h


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
