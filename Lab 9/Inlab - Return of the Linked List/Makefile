CXX=clang $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG = -g

a.out: linkedlist.o 
	$(CXX) $(DEBUG) linkedlist.o -o a.out

linkedlist.o: linkedlist.c

.PHONY: clean
clean:
	-rm -f *.o a.out
