CXX=clang++
CXXFLAGS=-Wall -g
AS = nasm
ASFLAGS = -f elf64 -g
OBJECTS = threexinput.o timer.o threexplusone.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~
