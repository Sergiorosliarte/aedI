#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Lugar.h"
#include "Carretera.h"
#include "MapaLugares.h"
using namespace std;

MapaLugares mapa;

int Separar (string linea, string parametros[4])
{
	int p = 0;
	string parametro = {""};
	for (int i = 1; i < (uint)linea.length(); i++)
	{
		if (linea[i] == ',')
		{
			parametros[p] = parametro;
			p += 1;
			parametro = {""};
		}
		else
		{
			parametro += linea[i];
		}
	}
	
	parametros[p] = parametro;
	return p;
}

void INICIALIZAR ()
{
	mapa.vaciar();
	cout<<"Mapa inicializado"<<endl;
}

void ANADIRLUGAR (Lugar *l)
{
	int a=0;
	mapa.insertar(l, a);
	if (a == 1)
		cout<<"Añadido: "<<l->getNombre()<<". Total: "<<mapa.nLugares()<<" lugares"<<endl;
	if (a == 2)
	{
		cout<<"Añadido: "<<l->getNombre()<<". Total: "<<mapa.nLugares()<<" lugares"<<endl;
		delete l;
	}
}

void ANADIRCARRETERA (string origen, string destino, string coste, string info)
{
	int a = 0;
	mapa.insertarCarretera(origen, destino, atoi(coste.c_str()), info, a);
	if (a>=1)
		cout<<"Añadido: "<<origen<<"-"<<destino<<". Total: "<< a <<" carreteras"<<endl;
}

void AL (Lugar *l)
{
	int a=0;
	mapa.insertar(l, a);
	if (a==2)
		delete l;
}

void AC (string origen, string destino, string coste)
{
	int a = 0;
	mapa.insertarCarretera(origen, destino, atoi(coste.c_str()), "", a);
}

void CONSULTARLUGAR (string nombre)
{
	Lugar *l = mapa.consultar(nombre);
			if (l == NULL)
			{
				cout<<"No encontrado: "<<nombre<<endl;
			}
			else
			{
				cout<<"Encontrado: "<<l->getNombre()<<endl;
				cout<<"Información: "<<l->getInfo()<<endl;
			}
}

void CONSULTARCARRETERA (string origen, string destino)
{
	Carretera * c = mapa.consultarCarretera(origen, destino);
	if (c != NULL)
	{
		cout<<"Encontrado: "<<origen<<"-"<<destino<<endl;
		cout<<"Coste: "<<c->getCoste()<<endl;
		cout<<"Información: "<<c->getInfo()<<endl;
	}
	else cout<<"No encontrado: "<<origen<<"-"<<destino<<endl;
}

void LISTARAD (string nombre)
{
	mapa.listarAdyacentes(nombre);
}

void LISTARLUGARES ()
{
	cout<<"Total: 0 lugares"<<endl;
}

void CALCULARRUTA (string orig, string dest)
{
	cout<<"No existe ningún camino entre "<<orig<<" y "<<dest<<endl;
}

void interprete (string comando, string linea)
{
	string parametros[4];
	Separar(linea, parametros);
	
		if (comando=="Inicializar")
		{
			INICIALIZAR();
		}
		
		else if (comando=="AñadirLugar")
		{
			Lugar *l = new Lugar();
			l->set(parametros[0], parametros[1]);
			ANADIRLUGAR(l);
		}
		
		else if (comando=="AñadirCarretera")
			ANADIRCARRETERA(parametros[0], parametros[1], parametros[2], parametros[3]);
		
		else if (comando=="AL")
		{
			Lugar *l = new Lugar();
			l->set(parametros[0], "");
			AL(l);
		}
		
		else if (comando=="AC")
			AC(parametros[0], parametros[1], parametros[2]);
		
		else if (comando=="ConsultarLugar")
		{
			CONSULTARLUGAR(parametros[0]);
		}
		
		else if (comando=="ConsultarCarretera")
			CONSULTARCARRETERA(parametros[0], parametros[1]);
		
		else if (comando=="ListarAdyacentes")
			LISTARAD(parametros[0]);
		
		else if (comando=="ListarLugares")
			LISTARLUGARES();
		
		else if (comando=="CalcularRuta")
			CALCULARRUTA(parametros[0], parametros[1]);
}

int main(void)
{
	string comando, param;
	int cont=1;
	while (cin>>comando)
	{ 
		getline(cin, param);
		interprete(comando, param);
		cont++;
	}
}
