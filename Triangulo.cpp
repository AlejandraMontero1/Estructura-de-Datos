#include "Triangulo.h"
//Implementacion de los metodos de la clase
//Declaracion del constructor
Triangulo::Triangulo(void)
{
	base = 4;
	altura = 3;
}
//Declaracion del destructor
Triangulo::~Triangulo(void)
{
}
//Declaración del metodo - funcion
float Triangulo::calculararea(float b, float h)
{
	area = (b * h) / 2;
	return area;
}
