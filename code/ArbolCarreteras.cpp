#include "ArbolCarreteras.h"
#include "Lugar.h"

ArbolCarreteras::ArbolCarreteras ()
{
	raiz = NULL;
}

ArbolCarreteras::~ArbolCarreteras ()
{
	delete raiz;
}

int ArbolCarreteras::altura (NodoAvl * nodo)
{
	if (nodo == NULL)
		return -1;
	else return nodo->altura;
}

void ArbolCarreteras::RSD(NodoAvl *&nodo){


    NodoAvl * aux = nodo->hijoDer;
    nodo->hijoDer = aux->hijoIzq;
    aux->hijoIzq = nodo;
    nodo->setAltura(1 + max(altura(nodo->hijoIzq), altura(nodo->hijoDer)));
    aux->setAltura(1 + max(altura(nodo), altura(aux->hijoDer)));
    nodo = aux;
}

void ArbolCarreteras::RSI(NodoAvl *&nodo){


    NodoAvl * aux = nodo->hijoIzq;
    nodo->hijoIzq = aux->hijoDer;
    aux->hijoDer = nodo;
    nodo->setAltura(1 + max(altura(nodo->hijoIzq), altura(nodo->hijoDer)));
    aux->setAltura(1 + max(altura(nodo), altura(aux->hijoIzq)));
    nodo = aux;
}

void ArbolCarreteras::RDI(NodoAvl *&nodo){
    RSD(nodo->hijoIzq);
    RSI(nodo);
}

void ArbolCarreteras::RDD(NodoAvl *&nodo){
    RSI(nodo->hijoDer);
    RSD(nodo);
}

void ArbolCarreteras::insertarAUX (NodoAvl *&nodo, Carretera c)
{
	if (nodo==NULL)
	{
		nodo = new NodoAvl (c);
	}
	
	else
	{
		string clave = c.getDestino()->getNombre();
		if (clave < nodo->getClave())
		{
			insertarAUX(nodo->hijoIzq, c);
			if (altura(nodo->hijoIzq) - altura(nodo->hijoDer) > 1)
			{
				if (clave < nodo->hijoIzq->getClave())
					RSI(nodo);
					
				else RDI(nodo);
			}
			else nodo->setAltura(1 + max(altura(nodo->hijoIzq), altura(nodo->hijoDer)));
		}
		
		if (clave > nodo->getClave())
		{
			insertarAUX(nodo->hijoDer, c);
			if (altura(nodo->hijoDer) - altura(nodo->hijoIzq) > 1)
			{
				if (clave > nodo->hijoDer->getClave())
					RSD(nodo);
					
				else RDD(nodo);
			}
			else nodo->setAltura(1 + max(altura(nodo->hijoIzq), altura(nodo->hijoDer)));
		}
	}
}

Carretera * ArbolCarreteras::consultarAUX(NodoAvl *nodo, string destino)
{
	if (nodo == NULL)
		return NULL;
	else if (nodo->getClave() == destino)
		return &nodo->c;
	else
	{
		if (destino < nodo->getClave())
		{
			return consultarAUX(nodo->hijoIzq, destino);
		}
		else 
		{
			return consultarAUX(nodo->hijoDer, destino);
		}
	}
}

string ArbolCarreteras::listarAUX (NodoAvl *nodo)
{
	if (nodo == NULL)
		return "";
	else return (listarAUX(nodo->hijoIzq) + nodo->getClave() + ", " + listarAUX(nodo->hijoDer));
		
}

void ArbolCarreteras::insertar (Carretera c)
{
	insertarAUX(raiz, c);
}

Carretera * ArbolCarreteras::consultar (string destino)
{
	return consultarAUX(raiz, destino);
}

string ArbolCarreteras::listar ()
{
	if (raiz == NULL)
		return "Adyacentes: ";
	else
	{
		string a = {"Adyacentes: "};
		a = a + listarAUX(raiz);
		if (a.back() == ' ')
		{
			a.pop_back();
			a.pop_back();
		}
		return a;
	}
}
