#include "miniwin.h"
#include "Complejo.hpp"

using namespace miniwin;

#define DIM 640 //Tamaño de ancho,alto de la ventana
#ifndef CONJUNTO
#define CONJUNTO

//----Prototipo de la Clase Padre Conjunto----
class Conjunto{
	public: 
	   Conjunto();                           //Constructor por defecto
	   Conjunto(const int);                  //Constructor por parametros
	
	virtual void setImprimirConjunto(Complejo &)=0;   //Funcion virtual pura
	
	protected:
	 	 int Maxiteraciones;                //miembros de datos o atributos
};
#endif
