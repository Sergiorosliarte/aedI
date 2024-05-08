a.out: 302.o Lugar.o MapaLugares.o TablaHash.o Carretera.o NodoAvl.o ArbolCarreteras.o
	g++ 302.o Lugar.o MapaLugares.o TablaHash.o Carretera.o NodoAvl.o ArbolCarreteras.o
	
Carretera.o: Carretera.h Lugar.h
	g++ -c Carretera.cpp

NodoAvl.o: NodoAvl.cpp NodoAvl.h Carretera.h Lugar.h
	g++ -c NodoAvl.cpp

ArbolCarreteras.o: ArbolCarreteras.cpp ArbolCarreteras.h Carretera.h NodoAvl.h Lugar.h
	g++ -c ArbolCarreteras.cpp
		
Lugar.o: Lugar.cpp Lugar.h ArbolCarreteras.h Carretera.h
	g++ -c Lugar.cpp
	
TablaHash.o: TablaHash.cpp TablaHash.h
	g++ -c TablaHash.cpp

MapaLugares.o: MapaLugares.cpp MapaLugares.h Lugar.h TablaHash.h Carretera.h
	g++ -c MapaLugares.cpp

302.o: 302.cpp MapaLugares.h Lugar.h Carretera.h
	g++ -c 302.cpp
