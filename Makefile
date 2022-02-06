play: play.cpp card.cpp deck.cpp parser.cpp solver.cpp
	clang++ -Wall -g -O0 -o play play.cpp card.cpp deck.cpp parser.cpp solver.cpp
clean:
	rm -rf play *.o *~ *dSYM
