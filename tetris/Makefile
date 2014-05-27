tet:	engine.o timestepper.o main.o playzone.o piece.o globals.o titlescreen1.o stringinput.o highscore.o scorelist.o listscores.o
	g++ -g engine.o timestepper.o main.o  playzone.o piece.o globals.o titlescreen1.o stringinput.o highscore.o scorelist.o listscores.o `sdl-config --libs` -lSDL -lSDL_image -lSDL_ttf -o tet

main.o:		main.cpp
	g++ -c main.cpp `sdl-config --cflags`

engine.o:	engine.cpp engine.h
	g++ -c engine.cpp `sdl-config --cflags`

playzone.o:	playzone.cpp playzone.h
	g++ -c playzone.cpp `sdl-config --cflags`

piece.o:	piece.cpp piece.h
	g++ -c piece.cpp `sdl-config --cflags`

stringinput.o:	stringinput.cpp stringinput.h
	g++ -c stringinput.cpp `sdl-config --cflags`

globals.o:	globals.cpp globals.h
	g++ -c globals.cpp `sdl-config --cflags`

timestepper.o:	timestepper.cpp timestepper.h
	g++ -c timestepper.cpp `sdl-config --cflags`

titlescreen1.o:	titlescreen1.cpp titlescreen1.h
	g++ -c titlescreen1.cpp `sdl-config --cflags`

highscore.o:	highscore.cpp highscore.h
	g++ -c highscore.cpp `sdl-config --cflags`

scorelist.o:	scorelist.cpp scorelist.h
	g++ -c scorelist.cpp `sdl-config --cflags`

listscores.o:	listscores.cpp listscores.h
	g++ -c listscores.cpp `sdl-config --cflags`

clean:
	rm -f *.o tet
