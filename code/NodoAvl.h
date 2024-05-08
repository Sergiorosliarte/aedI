#ifndef NODO_AVL
#define NODO_AVL
#include "Carretera.h"

class ArbolCarreteras;
class NodoAvl
{
	friend class ArbolCarreteras;
	private:
		string clave;
		int altura;
		Carretera c;
		NodoAvl * hijoDer;
		NodoAvl * hijoIzq;
		
	public:
		NodoAvl(Carretera carretera);
		~NodoAvl();
		void setAltura (int a);
		Carretera * getCarretera ();
		int getAltura ();
		string getClave ();
};

#endif
