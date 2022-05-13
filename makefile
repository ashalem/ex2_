CC=g++
OBJS=Player.o Card.o Mtmchkin.o main.o
EXEC=mtmchkin_test
DEBUG_FLAG= -g
CPPFLAGS=--std=c++11 -Wall -pedantic-errors -Werror -DNDEBUG

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(CPPFLAGS) $(OBJS) -o $@


Player.o: Player.cpp Player.h utilities.h
Card.o: Card.cpp Card.h Player.h utilities.h
Mtmchkin.o: Mtmchkin.cpp Mtmchkin.h Card.h Player.h 
main.o: main.cpp Mtmchkin.h

clean:
	rm -f $(OBJS) $(EXEC)
