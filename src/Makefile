CC = clang++
CXXFLAGS = -W -Wall -Wextra -pedantic -std=c++11 -O0 -g -ggdb
INCLUDE =
LIBS =

EXEC = fat-fs
SRC = entry.cc fsinfo.cc fat.cc partition.cc mbr.cc input.cc main.cc
OFILES = ${SRC:.cc=.o}

all: .depend $(OFILES)
	$(CC) $(CXXFLAGS) $(LIBS) $(OFILES) -o $(EXEC)

%.o: %.cc
	$(CC) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -f .depend
	rm -f $(OFILES)

depend: .depend

.depend: $(SRC)
	rm -f .depend
	$(CC) -MM $(CXXFLAGS) $(INCLUDE) $^ > .depend

-include .depend
