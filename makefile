
# makefile for minesweeper
mine: main.cpp minesweeper.cpp
	g++ main.cpp minesweeper.cpp -o mine
	cp mine /usr/local/bin
