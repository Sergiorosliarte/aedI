//Clase Lugar

#ifndef LUGAR_H
#define LUGAR_H
#include <iostream>
#include "Carretera.h"
#include "ArbolCarreteras.h"
using namespace std;

class Lugar{
	
	private:
		string nombre;
		string informacion;
		ArbolCarreteras * carreteras;
		
	public:
		Lugar();
		~Lugar();
		void setCarretera (Carretera c, int &a);
		void set(string nom, string inf);
		Carretera * getCarretera(string destino);
		void listarCarreteras ();
		string getNombre();
		string getInfo();
};

#endif
