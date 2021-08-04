#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#ifndef COMPLEJO
#define COMPLEJO
//------Prototipo Clase Complejo-------
class Complejo{
	
	friend Complejo &operator +(const Complejo &, const Complejo &);
	friend Complejo &operator *(const Complejo &, const Complejo &);  
	
	public:
		Complejo();
		Complejo(const double Real, const double Imaginaria);
		
		void MostrarComplejo();
		
		double setReal(const double);
        const double getReal() const; 
        
        double setImag(const double);
        const double getImag() const;
        
        double getMagnitud();
	
	private:
		double real, imaginaria;
};
#endif


