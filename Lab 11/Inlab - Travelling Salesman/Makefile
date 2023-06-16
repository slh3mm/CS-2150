CXX=clang++
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS=middleearth.o traveling.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(CXXFLAGS) $(OBJECTS)
	doxygen
	@echo "Program Executable Ready to go!"


middleearth.o: middleearth.cpp middleearth.h

traveling.o: traveling.cpp middleearth.h


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
