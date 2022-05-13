CC=g++
OBJS=Player.o Card.o Mtmchkin.o main.o utilities.o
EXEC=mtmchkin_test
DEBUG_FLAG= -g
CPPFLAGS=--std=c++11 -Wall -pedantic-errors -Werror -DNDEBUG -g

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(CPPFLAGS) $(OBJS) -o $@


utilities.o: utilities.cpp utilities.h
Player.o: Player.cpp Player.h utilities.h
Card.o: Card.cpp Card.h Player.h utilities.h
Mtmchkin.o: Mtmchkin.cpp Mtmchkin.h Card.h Player.h 
main.o: main.cpp Mtmchkin.h Card.h
test.o : test.cpp Player.h Mtmchkin.h Card.h

tester : Player.o Card.o Mtmchkin.o utilities.o test.o
	$(CC) $(DEBUG_FLAG) $(CPPFLAGS) Player.o Card.o Mtmchkin.o utilities.o test.o -o $@

clean:
	rm -f $(OBJS) $(EXEC)
