## Makefile

INC_DIR =

ALL_LIBS =

rootFile = main.cc

solverFiles = Thing.cc World.cc

utilityFiles = utilities.cc Stopwatch.cc

inputFile = $(rootFile) $(solverFiles) $(utilityFiles)

objectFile = $(inputFile:.cc=.o)
dependFile = $(inputFile:.cc=.d)

COMPILE_OPTION =
LINK_OPTION =

default: all

all: $(objectFile)
	g++ $(LINK_OPTION) $(INC_DIR) $(objectFile) $(ALL_LIBS) -o gdevice
	rm -f *~

%.o: %.cc
	g++ $(COMPILE_OPTION) $(INC_DIR) -c $< -o $@

%.d: %.cc
	g++ -M $(COMPILE_OPTION) $(INC_DIR) -c $< > $@

clean:
	rm -f *~
	rm -f *.o
	rm -f *.d
	rm -f gdevice
