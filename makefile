ALL: compile run

compile:
		
		g++  -I ./include/ -o ./lib/Bst.o -c ./src/Bst.cpp
		g++  -I ./include/ -o ./lib/Linkedlist.o -c ./src/Linkedlist.cpp
		g++  -I ./include/ -o ./bin/Program  ./lib/Bst.o ./lib/Linkedlist.o ./src/Program.cpp
run:
		cmd /c cls
		 ./bin/Program
		 