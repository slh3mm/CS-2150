CXX=clang++
CXXFLAGS=-Wall -g
OBJECTS=topological.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen
	@echo "Program Executable Ready to go!"

topological.o: topological.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
