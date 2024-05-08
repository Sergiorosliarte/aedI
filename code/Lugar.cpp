#include "Lugar.h"


Lugar::Lugar ()
{
	nombre = {""};
	informacion = {""};
	carreteras = new ArbolCarreteras();
}
Lugar::~Lugar ()
{delete carreteras;}

void Lugar::setCarretera (Carretera c, int &a)
{
	Carretera * aux = getCarretera(c.getDestino()->getNombre());
	if (aux != NULL)
	{
		aux->set(c.getCoste(), c.getInfo());
		a=0;
	}
	else
	{
		carreteras->insertar(c);
		a=1;
	}
}

void Lugar::set (string nom, string inf)
{
	 nombre= nom; 
	 informacion= inf;
}

Carretera * Lugar::getCarretera (string destino)
{
	return carreteras->consultar(destino);
}

void Lugar::listarCarreteras ()
{
	cout<<"Encontrado: "<<nombre<<endl;
	cout<<carreteras->listar()<<endl;
	
}

string Lugar::getNombre ()
{
	return nombre;
}

string Lugar::getInfo ()
{
	return informacion;
}
