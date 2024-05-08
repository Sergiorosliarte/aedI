#include "MapaLugares.h"
#include "Lugar.h"
#include "Carretera.h"

MapaLugares::MapaLugares ()
{
	contador = 0;
	numCarreteras = 0;
}
MapaLugares::~MapaLugares ()
{
}

void MapaLugares::vaciar ()
{
	mapa.vacia();
	contador = 0;	
	numCarreteras = 0;
}

void MapaLugares::insertar (Lugar *L, int &a)
{
	mapa.inserta(L, a);
	contador=mapa.nTotal();
}

Lugar * MapaLugares::consultar (string nombre)
{
	return mapa.consulta(nombre);
}	

void MapaLugares::insertarCarretera (string origen, string destino, int coste, string info, int &a)
{
	Lugar * orig = consultar(origen);
	if (orig != NULL)
	{
		Lugar * dest = consultar(destino);
		if (dest != NULL)
		{
			if (orig->getNombre() != dest->getNombre())
			{
				Carretera c;
				c.set(dest, coste, info);
				orig->setCarretera(c,a);
				if (a == 1)
					numCarreteras++;
				a = numCarreteras;
			}
		}
	}
}

Carretera * MapaLugares::consultarCarretera (string origen, string destino)
{
	Lugar * orig = consultar(origen);
	if (orig != NULL)
	{
		Carretera * c = orig->getCarretera(destino);
		return c;
		
	}
	return NULL;
}

void MapaLugares::listarAdyacentes (string origen)
{
	Lugar * orig = consultar(origen);
	if (orig != NULL)
	{
		orig->listarCarreteras();
	}
	else cout<<"No encontrado: "<<origen<<endl;
}

int MapaLugares::nLugares (void) 
{
	return contador;
}


