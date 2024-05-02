all: automata_main

automata_main: automata_main.o automata_func.o transiciones.o alfabeto.o automata.o estado.o
	g++ -o automata_main automata_main.o automata_func.o transiciones.o alfabeto.o automata.o estado.o -std=c++2a

automata_func.o: automata_func.cc
	g++ -c -o automata_func.o automata_func.cc -std=c++2a

automata_main.o: automata_main.cc
	g++ -c -o automata_main.o automata_main.cc -std=c++2a

transiciones.o: transiciones.cc
	g++ -c -o transiciones.o transiciones.cc -std=c++2a

alfabeto.o: alfabeto.cc
	g++ -c -o alfabeto.o alfabeto.cc -std=c++2a

automata.o: automata.cc
	g++ -c -o automata.o automata.cc -std=c++2a

estado.o: estado.cc
	g++ -c -o estado.o estado.cc -std=c++2a

clean:
	-rm automata_main.o automata_func.o transiciones.o alfabeto.o automata.o estado.o automata_main