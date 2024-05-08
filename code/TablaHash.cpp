#include "TablaHash.h"
#include <string>

TablaHash::TablaHash ()
{
	nElem = 0;
	numCubetas=1000;
	tabla = new list<Lugar*>[numCubetas];
}
TablaHash::~TablaHash ()
{
	vacia();
	delete [] tabla;
}

uint TablaHash::fhash(string a)
{
	uint x=0;
	uint pot=1;
	for (int i = 0; i<a.length(); i++)
	{
		uint y = uint(a[i])*pot;
		x+=y;
		pot=pot*7;
	}
	return x%numCubetas;
}

void TablaHash::inserta (Lugar *L, int &a)
{
	if (nElem >= 1.5 * numCubetas)
		reestructura();
		
	uint cubeta = fhash(L->getNombre());
	string nom = L->getNombre();
    list<Lugar*>::iterator it = tabla[cubeta].begin();                             
    while (it != tabla[cubeta].end() && (*it)->getNombre() < nom) 
    {
        it++;
    }
    
    if (it == tabla[cubeta].end() || (*it)->getNombre() != nom)
    {
        tabla[cubeta].insert(it, L);
        nElem++;
        a=1;
        
    }
    else if((*it)->getNombre() == nom)
    {
		(*it)->set(nom, L->getInfo());
        a=2;
    }
}

void TablaHash::reestructura (void)
{
	list<Lugar*> *aux = tabla;
	numCubetas=2*numCubetas;
	tabla = new list<Lugar*>[numCubetas];
	int x=0;
	nElem=0;
	for (int i=0; i<(numCubetas/2); i++)
	{
		list<Lugar*>::iterator it = aux[i].begin();
		while (it != aux[i].end())
		{
			inserta((*it),x);
			it++;
		}
	}
	delete [] aux;
}
    
Lugar * TablaHash::consulta (string nombre)
{
	uint cubeta = fhash(nombre);
	list<Lugar*>::iterator it = tabla[cubeta].begin();
    while (it != tabla[cubeta].end())
    {
        if((*it)->getNombre() == nombre)
        {
            return (*it);
        }
        it++;
    }
    return NULL;
}	

int TablaHash::getCubetas (void)
{
	return numCubetas;
}

void TablaHash::vacia ()
{
	for (int i=0; i<numCubetas; i++)
	{
		list<Lugar*>::iterator it = tabla[i].begin();
		while (it != tabla[i].end())
		{
			Lugar * aux = (*it);
			delete aux;
			it++;
		}
		tabla[i].clear();
		nElem=0;	
	}
}

int TablaHash::nTotal (void) 
{
	return nElem;
}

