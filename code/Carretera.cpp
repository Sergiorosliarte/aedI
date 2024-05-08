#include "Lugar.h"
#include "Carretera.h"

Carretera::Carretera ()
{
	destino = NULL;
}

Carretera::~Carretera ()
{}

void Carretera::set (Lugar *l, int c, string info)
{
	destino = l;
	coste = c;
	informacion = info;
}

void Carretera::set (int c, string info)
{
	coste = c;
	informacion = info;
}

Lugar* Carretera::getDestino ()
{
	return destino;
}

int Carretera::getCoste ()
{
	return coste;
}

string Carretera::getInfo ()
{
	return informacion;
}
