#include "NodoAvl.h"
#include "Lugar.h"

NodoAvl::NodoAvl (Carretera carretera)
{
	c = carretera;
	clave = c.getDestino()->getNombre();
	altura = 0;
	hijoDer = NULL;
	hijoIzq = NULL;
}

NodoAvl::~NodoAvl ()
{
	delete hijoIzq;
	delete hijoDer;
}

void NodoAvl::setAltura (int a)
{
	altura = a;
}

Carretera * NodoAvl::getCarretera ()
{
	return &c;
}

int NodoAvl::getAltura()
{
	return altura;
}

string NodoAvl::getClave()
{
	return clave;
}
