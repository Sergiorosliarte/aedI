#ifndef TABLA_HASH
#define TABLA_HASH

#include "Lugar.h"
#include <list>
#include <iostream>
using namespace std;

class TablaHash
{
	private:
		list<Lugar*> * tabla;
		int nElem;
		int numCubetas;
		uint fhash (string a);
		
	public:
		TablaHash ();
		~TablaHash();
		void inserta (Lugar *L, int &a);
		void reestructura(void);
		Lugar * consulta (string nombre);
		int getCubetas(void);
		void vacia (void);
		int nTotal (void);

};

#endif
