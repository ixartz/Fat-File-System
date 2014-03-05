CC = g++
CXXFLAGS = -W -Wall -Wextra -Werror -pedantic -std=c++11 -O0 -g -ggdb
INCLUDE =
LIBS =

EXEC = fat-fs
SRC = partition.cc disk.cc main.cc
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
