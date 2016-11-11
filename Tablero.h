#ifndef Tablero_h
#define Tablero_h


#include <iostream>


class Tablero {

	public:
		char** matriz;
		int jugador;
		void impresionMatriz();
		char** movimiento(char**, int);

		Tablero();

		int siGanoAlguien();

		void setGano(int);
		int getGano();



};

#endif