all: Game Mapa.o Player.o Pantallas.o

Mapa.o: Mapa.cpp
	g++ -Wall -D_GLIBCXX_DEBUG -c Mapa.cpp

Player.o: Player.cpp
	g++ -Wall -D_GLIBCXX_DEBUG -c Player.cpp

Pantallas.o: Pantallas.cpp
	g++ -Wall -D_GLIBCXX_DEBUG -c Pantallas.cpp

Game: Juego.cpp Mapa.o Player.o Pantallas.o
	g++ -Wall -D_GLIBCXX_DEBUG -o Game Juego.cpp Player.o Mapa.o Pantallas.o

clean: 
	rm *.o Game