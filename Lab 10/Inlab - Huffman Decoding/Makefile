CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS= heap.o Node.o huffmandec.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(CXXFLAGS) $(OBJECTS)
	@echo "Program Executable Ready to go"!

heap.o: heap.cpp heap.h Node.h

Node.o: Node.cpp  Node.h

huffmandec.o: huffmandec.cpp heap.h Node.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
