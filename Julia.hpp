/*
Clase Julia: Es una clase hija que esta obligada a implementar el metodo
para imprimir y pintar el conjunto, en esta clase se trabaja con miembros de datos del tipo complejos.
*/
#include "Complejo.hpp"
#include "Conjunto.hpp"

#ifndef JULIA
#define JULIA
//-----Prototipo Clase hija Conjunto de Julia-----
class Julia:public Conjunto{
	public:
		Julia();           //constructor por defecto
	    Julia(const int);  //constructor por parametros
	    ~Julia();          //destructor
	
	void setImprimirConjunto(Complejo &);
	
	private:
	  static double w;
	  static double h;     //tamaño entre pixeles
      static double xmin;
	  static double ymin;  //para acotar los ejes
      static double xmax;
	  static double ymax;  // para delimitar los ejes
	  static double dx;
	  static double dy;    //diferencia entre cada pixel
	  
	  Complejo Znuevo;     //valor de Z_{k} en cada iteracion
	  Complejo Z0;         // iteracion anterior
 	  Complejo C;          // Complejo C
	  Complejo Z;          //guarda el cuadrado del complejo Z_{0}
	  
};
#endif
