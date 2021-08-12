/*
Esta es la clase hija Conjunto de Mandelbrot
implementa una función miembro que pinta el propio
Conjunto de Mandelbrot y utiliza como miembros de datos 
objetos del tipo Complejo
*/

#include "Complejo.hpp"
#include "Conjunto.hpp"

#ifndef MANDELBROT
#define MANDELBROT
//-----Prototipo de la Clase Hija Conjunto de Mandelbrot-----
class Mandelbrot:public Conjunto{
	public:
		Mandelbrot();           //Constructor por defecto
    	Mandelbrot(const int);  //constructor por parametros
    	~Mandelbrot();          //destructor
	
	void setImprimirConjunto(Complejo &);  //Funcion miembro que cada clase hija implementar a su manera
	
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
	  Complejo Z;	  	   //guardada el cuadro del complejo Z_{0}
};
#endif
