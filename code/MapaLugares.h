#ifndef MAPA_LUGARES
#define MAPA_LUGARES

#include "Lugar.h"
#include "TablaHash.h"
#include <iostream>
#include <list>

class MapaLugares {

	private:
		TablaHash mapa;
		int contador;
		int numCarreteras;

	public:
		MapaLugares ();
		~MapaLugares ();
		void vaciar ();
		void insertar (Lugar *L, int &a);
		Lugar * consultar (string nombre);
		void insertarCarretera (string origen, string destino, int coste, string info, int &a);
		Carretera * consultarCarretera (string origen, string destino);
		void listarAdyacentes(string origen);
		int nLugares (void);

};

#endif
