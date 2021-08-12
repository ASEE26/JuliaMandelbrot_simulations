#include "Conjunto.hpp"
#include "Mandelbrot.hpp"
#include "miniwin.h"

using namespace miniwin;

//---------Inicializacion de las variables de tipo static-------
double Mandelbrot::w = 2.5;
double Mandelbrot::h = 2.5;
	
double Mandelbrot::xmin = -2;
double Mandelbrot::ymin = -1.25;

double Mandelbrot::xmax = xmin + w;
double Mandelbrot::ymax = ymin + h;

double Mandelbrot::dx = (xmax - xmin) / (DIM-1);
double Mandelbrot::dy = (ymax - ymin) / (DIM-1);

//-----------Constructor por defecto ------------
Mandelbrot::Mandelbrot():Conjunto(){
	this->Maxiteraciones = 400;
}

//------------Constructor por parametros Mandelbrot--------------	
Mandelbrot::Mandelbrot(const int Iteraciones):Conjunto(Iteraciones){
	this->Maxiteraciones = Iteraciones;
}

//------------Funcion set que Pinta el conjunto------------
void Mandelbrot::setImprimirConjunto(Complejo &c1){
	/*ciclos para recorrer la pantalla entre cada pixel
	 y calcular el complejo correspondiente*/ 
	vredimensiona(DIM,DIM);
		
	for(int j=0; j < DIM ; j++){
		this->C.setImag(this->ymin+j*this->dy); //cambio del espacio virtual al espacio matematico
		for(int i=0; i < DIM ; i++){
			this->C.setReal(this->xmin+i*this->dx);
			this->Z0.setReal(C.getReal());
			this->Z0.setImag(C.getImag());
			
			int iteracion = 0;
			for(iteracion = 0; iteracion < this->Maxiteraciones; iteracion++){		
		    this->Z = Z0*Z0;
		    this->Znuevo = Z + C;
		    
			/* si se cumple entonces el complejo no pertenece 
			al conjunto y pasamos a estudiar el siguiente pixel*/
			if(Znuevo.getMagnitud() > 4){ 
				break;
			}			
		    	this->Z0.setReal(this->Znuevo.getReal());
		    	this->Z0.setImag(this->Znuevo.getImag());
		   
		    }
		    
		    if(iteracion == this->Maxiteraciones){ //pertenece al conjunto
		    	color_rgb(0,0,0);
		    	punto(i,j);
			}
			else if(iteracion >=0 && iteracion <= 17){
			    color_rgb(100,10*iteracion,iteracion*16%255);
		    	punto(i,j);
			}
			else if(iteracion > 17 && iteracion <=255){
				color_rgb(iteracion*16%255,iteracion,iteracion*16%255);
		    	punto(i,j);
			}
			else if(iteracion > 255 && iteracion <=2*255){
				color_rgb(2*iteracion*16%255,0,0);
		    	punto(i,j);
			}
			else if(iteracion >2*255 && iteracion <=3*255){ 
				color_rgb(255, iteracion-2*255,3*iteracion*16%255);
		    	punto(i,j);
			}
			else if(iteracion >3*255 && iteracion <=4*255){
				color_rgb(4*iteracion*16%255,iteracion-3*255,50);
				punto(i,j);
			}
			else if(iteracion >4*255 && iteracion <=5*255){
				color_rgb(255,5*iteracion*16%255,0);
				punto(i,j);
			}
		}
	}

	color(NEGRO);	
	texto(20,20,"Conjunto de Mandelbrot");
	system("pause");
	refresca();
}

//--------------Destructor-------------
Mandelbrot::~Mandelbrot(){
}


