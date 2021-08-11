/*
Practicando hacer cambios en proyecto
*/
#include "Complejo.hpp"

//-------------------Constructor por defecto----------------------
Complejo::Complejo(){
	this->real = 0;
    this->imaginaria = 0;
}

//-------------------Constructor con parametro--------------------
Complejo::Complejo(const double Real, const double Imaginaria){
   this->real = Real;
   this->imaginaria = Imaginaria;
}

//---------------------Mostrar Complejo--------------------------
void Complejo::MostrarComplejo(){
	cout<<"El numero complejo es: "<<this->real<<"+"<<this->imaginaria<<"i"<<endl;
}

//---------------------Funcion set ParteReal----------------------
double Complejo::setReal(const double Real){
	this->real = Real;
}

//---------------------Funcion get ParteReal----------------------
const double Complejo::getReal() const{
	return this->real;
}

//--------------------Funcion set ParteImag-----------------------
double Complejo::setImag(const double Imaginaria){
	this->imaginaria = Imaginaria;
}

//---------------------Funcion get ParteImag----------------------
const double Complejo::getImag() const{
    return this->imaginaria;
}

//--------------------Funcion get Magnitud------------------------
double Complejo::getMagnitud(){
	double magnitud;
	magnitud = real*real + imaginaria*imaginaria;
	return magnitud;
}

//--------------------Sobrecarga de operadores---------------------
Complejo &operator +(const Complejo & c1, const Complejo &c2){
	double real = c1.real + c2.real;
	double imag = c1.imaginaria + c2.imaginaria;
	
	return *(new Complejo(real, imag));
}

Complejo &operator *(const Complejo & c1, const Complejo &c2){
	double real = c1.real * c2.real - c1.imaginaria * c2.imaginaria;
	double imag = c1.real * c2.imaginaria + c2.real * c1.imaginaria;
	
	return *(new Complejo(real,imag));
}


