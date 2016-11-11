

#include <iostream>
#include <iostream>
#include "Tablero.h"

using namespace std;

Tablero::Tablero(){
	matriz = new char*[11];

	for (int i = 0; i < 11;i++){
		matriz[i] = new char[11];
	}

	matriz[0][0] = '+';
	matriz[10][0] = '#';
	matriz[10][10] = '+';
	matriz[0][10] = '#';


	jugador = 0;
	movimiento(matriz, jugador);
	
	
}

void Tablero::impresionMatriz(){
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			cout << "[" <<  matriz[i][j]  << "]";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Tablero:: setGano(int pJugador){
	jugador = pJugador;
}

int Tablero:: getGano(){
	return jugador;
}

int Tablero::siGanoAlguien(){
	int contadorjug1 = 0;
	int contadorjug2 = 0;
	int espacioslibres = 0;

	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if(matriz[i][j] == '+'){
				contadorjug1++;
			}
			else if(matriz[i][j] == '#'){
				contadorjug2++;
			} else{
				espacioslibres++;
			}
		}
	}

	/*
	2 -> jugador 1 gano
	1 -> jugador 2 gano
	0 -> nadie ha ganado
	3 -> empate
	*/

	if(contadorjug1 == 0){
		return 2;
	} 
	else if (contadorjug2 == 0){
		return 1;
	} else if(espacioslibres == 0){
		if(contadorjug2 > contadorjug1){
			return 1;
		} else if(contadorjug1 > contadorjug2){
			return 2;
		} else{
			return 3;
		}
	}else {
		return 0;
	}
}


char** Tablero:: movimiento(char** x, int turno){

	int personaquegano = siGanoAlguien();

	if(personaquegano == 0){
		impresionMatriz();

		if(turno ==  0){
			cout << "Jugador 1" << endl;
		}
		if(turno ==  1){
			cout << "Jugador 2" << endl;
		}
		cout << endl;
		cout << "Ingrese posicion [i] para moverse: ";
		int i = 0; int j = 0;
		cin >> i;
		cout << endl;
		cout << "Ingrese posicion [j] para moverse: ";
		cin >> j;

		if(i > 10 || j > 10 || i < 0 || j < 0){
			cout << "El valor que ingreso se pasa de los limites de la matriz" << endl;
		} else{
			if(turno == 0){
				if(i + 2 <= 10){
					if(matriz[i+2][j] == '+'){
						matriz[i][j] = '+';
					}
				} 
				if (i + 1 <= 10){
					if(matriz[i + 1][j] == '+'){
						matriz[i][j] = '+';
					}
				} 
				if(i - 1 >= 0){
					if(matriz[i - 1][j] == '+'){
						matriz[i][j] = '+';
					}
				} 
				if(i - 2 >= 0 ){
					if(matriz[i - 1][j] == '+'){
						matriz[i][j] = '+';
					}
				}
				if(j + 2 <= 10){
					if(matriz[i][j + 2] == '+'){
						matriz[i][j] = '+';
					}
				} 
				if (j + 1 <= 10){
					if(matriz[i][j + 1] == '+'){
						matriz[i][j] = '+';
					}
				} 
				if(j - 1 >= 0){
					if(matriz[i][j - 1] == '+'){
						matriz[i][j] = '+';
					}
				} 
				if(j - 2 >= 0 ){
					if(matriz[i][j - 2] == '+'){
						matriz[i][j] = '+';
					}
				}
				cout << endl << endl;
				impresionMatriz();
				turno = 1;
				return movimiento(matriz, turno);

			} else if(turno == 1){
				if(i + 2 <= 10){
					if(matriz[i+2][j] == '#'){
						matriz[i][j] = '#';
					}
				} 
				if (i + 1 <= 10){
					if(matriz[i + 1][j] == '#'){
						matriz[i][j] = '#';
					}
				} 
				if(i - 1 >= 0){
					if(matriz[i - 1][j] == '#'){
						matriz[i][j] = '#';
					}
				} 
				if(i - 2 >= 0 ){
					if(matriz[i - 1][j] == '#'){
						matriz[i][j] = '#';
					}
				}
				if(j + 2 <= 10){
					if(matriz[i][j + 2] == '#'){
						matriz[i][j] = '#';
					}
				} 
				if (j + 1 <= 10){
					if(matriz[i][j + 1] == '#'){
						matriz[i][j] = '#';
					}
				} 
				if(j - 1 >= 0){
					if(matriz[i][j - 1] == '#'){
						matriz[i][j] = '#';
					}
				} 
				if(j - 2 >= 0 ){
					if(matriz[i][j - 2] == '#'){
						matriz[i][j] = '#';
					}
				}
				cout << endl << endl;
				impresionMatriz();
				turno = 0;
				return movimiento(matriz, turno);

			}
		}
	}else if(personaquegano == 1){
		cout << endl << "Ha ganado el jugador 2!";
	} else if(personaquegano == 2){
		cout << endl << "Ha ganado el jugador 1!";
	} else if(personaquegano == 3){
		cout << endl << "Ha quedado en empate!";
	}
}
				



