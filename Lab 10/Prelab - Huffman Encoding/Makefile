CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-g
OBJECTS= heap.o Node.o huffmanenc.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(CXXFLAGS) $(OBJECTS)
	@echo "Program Executable Ready to go"!

heap.o: heap.cpp heap.h Node.h

Node.o: Node.cpp  Node.h

huffmanenc.o: huffmanenc.cpp heap.h Node.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
