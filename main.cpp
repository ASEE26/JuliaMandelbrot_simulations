#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Complejo.hpp"
#include "Mandelbrot.hpp"
//#include "Julia.hpp"

int main(){
	Complejo *c1 = new Complejo(-1.3,0.00525);
/*	Complejo *c2 = new Complejo(0.399,0.159);
	Complejo *c3 = new Complejo(-0.8,-0.25);
	Complejo *c4 = new Complejo(-0.1,0.87);
	Complejo *c5 = new Complejo(0.285,-0.01);
	
    Julia *FractalJulia = new Julia(300);
    FractalJulia->setImprimirConjunto(*c1);
    
    Julia *Fractal = new Julia(100);
	Fractal->setImprimirConjunto(*c2);
    
    Julia *fractal = new Julia(200);
    fractal->setImprimirConjunto(*c3);
    
    Julia *Fractal2 = new Julia(100);
	Fractal2->setImprimirConjunto(*c4);
	
	Julia *Fractal3 = new Julia(100);
	Fractal3->setImprimirConjunto(*c5);
    
    delete FractalJulia;
    FractalJulia = 0;
    
    delete Fractal;
    Fractal =0;
    
    delete fractal;
    fractal =0;
    
	delete Fractal2;
    Fractal2 =0;
    
    delete Fractal3;
    Fractal3 =0; */
    
    
    Mandelbrot *Fractal = new Mandelbrot(500);   
    Fractal->setImprimirConjunto(*c1);
    
    delete Fractal;
    Fractal = 0; 
    	
	system("pause");	
	return 0;
}
