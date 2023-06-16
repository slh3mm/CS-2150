CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG = -g

a.out: hashTable.o wordPuzzle.o timer.o  
	$(CXX) $(DEBUG) wordPuzzle.o hashTable.o timer.o -o a.out

hashTable.o: hashTable.cpp hashTable.h

wordPuzzle.o: wordPuzzle.cpp timer.h hashTable.h

timer.o: timer.cpp timer.h

.PHONY: clean
clean:
	-rm -f *.o a.out
