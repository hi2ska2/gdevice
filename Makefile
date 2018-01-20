## Makefile

INC_DIR =

ALL_LIBS =

inputFile = Stopwatch.cc main.cc

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
