#pragma once
class Triangulo
{
	private:
		float base;
		float altura;
		float area;
		//Metodos - Funciones
	public:
		Triangulo(void); //Constructor - asigna memoria 
		~Triangulo(void); //Deestructor - libera memoria
		//Prototipos
		float calculararea(float b, float h);
	};
