#include "Conjunto.hpp"
#include "Julia.hpp"
#include "miniwin.h"

using namespace miniwin;

//-------------Inicializacion de variables Static----------
double Julia::w = 4;
double Julia::h = 4;
	
double Julia::xmin = -2;
double Julia::ymin = -2;

double Julia::xmax = xmin + w;
double Julia::ymax = ymin + h;

double Julia::dx = (xmax - xmin) / (DIM-1);
double Julia::dy = (ymax - ymin) / (DIM-1);

//-----Constructor por defecto del Conjunto de Julia-----
Julia::Julia():Conjunto(){
	this->Maxiteraciones = 1000;
}

//----------Constructor del Conjunto de Julia------------	
Julia::Julia(const int Iteraciones):Conjunto(Iteraciones){
	this->Maxiteraciones = Iteraciones;
}

//-----Funcion miembro que Pinta el Conjunto de Julia----
void Julia::setImprimirConjunto(Complejo &c1){
	/*ciclos para recorrer la pantalla entre cada pixel
	 y calcular el complejo correspondiente */  
	vredimensiona(DIM,DIM);
	
	for(int j=0; j < DIM ; j++){
		this->C.setImag(this->ymin+j*this->dy); //cambio del espacio virtual a espacio matematico
		for(int i=0; i < DIM ; i++){
			this->C.setReal(this->xmin+i*this->dx);
			this->Z0.setReal(C.getReal());
			this->Z0.setImag(C.getImag());
			
			int iteracion = 0;	//representa el momento en el que el punto se escapa al infinito
	    	while(iteracion < this->Maxiteraciones){
		
			Complejo C(c1.getReal(),c1.getImag()); //se establece fijo el valor del complejo C
		    this->Z = Z0*Z0;
		    this->Znuevo = Z + C;
		    
			/* si se cumple entonces el complejo no pertenece 
			al conjunto,paramos y pasamos a estudiar el siguiente pixel*/
			if(Znuevo.getMagnitud() > 4){ 
				break;
			}
			iteracion++;
			
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
	color(BLANCO);
	texto(40,40, "Conjunto de Julia");
	system("pause");
	refresca();
}

//-------Destructor de la Clase-------
Julia::~Julia(){
}
