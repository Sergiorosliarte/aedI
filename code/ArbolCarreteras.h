#ifndef ARBOL_CARRETERAS
#define ARBOL_CARRETERAS

#include "Carretera.h"
#include "NodoAvl.h"
using namespace std;

class ArbolCarreteras
{
	private:
		NodoAvl * raiz;
		
	protected:
		void RSI(NodoAvl *&nodo);
		void RSD(NodoAvl *&nodo);
		void RDI(NodoAvl *&nodo);
		void RDD(NodoAvl *&nodo);
		int altura (NodoAvl * a);
		void insertarAUX (NodoAvl  *&a, Carretera c);
		Carretera * consultarAUX (NodoAvl *a, string destino);
		string listarAUX (NodoAvl * a);
	public:
		ArbolCarreteras ();
		~ArbolCarreteras ();
		void insertar (Carretera c);
		Carretera * consultar (string destino);
		string listar ();
};
#endif
