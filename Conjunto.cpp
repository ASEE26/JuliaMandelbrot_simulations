#include "Conjunto.hpp"

//---------Constructor por defecto -----------------
Conjunto::Conjunto(){
	this->Maxiteraciones = 10;
}

//---------Constructor de la clase Padre---------------
Conjunto::Conjunto(const int Iteraciones){
	this->Maxiteraciones = Iteraciones;
}
