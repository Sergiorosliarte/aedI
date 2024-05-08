//Clase Lugar

#ifndef CARRETERA_H
#define CARRETERA_H
#include <iostream>
using namespace std;

class Lugar;
class Carretera{
	private:
		Lugar * destino;
		int coste;
		string informacion;
		
	public:
		Carretera();
		~Carretera();
		void set(Lugar *l, int coste, string info);
		void set(int coste, string info);
		Lugar* getDestino ();
		int getCoste();
		string getInfo();
};

#endif
