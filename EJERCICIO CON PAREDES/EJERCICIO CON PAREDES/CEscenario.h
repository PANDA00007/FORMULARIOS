#pragma once
#include <iostream>

using namespace std;
using namespace System::Drawing;

class Escenario {
private: 
	int ancho, alto;
	int** mat;

public: 

	Escenario() { // coordenadas / tamaño = indice
		ancho = 800 / 50;
		alto = 16;
		mat = new int* [alto];
		for (int i = 0; i < alto; i++) {
			mat[i] = new int[ancho];
			for (int j = 0; j < ancho; j++) {
				if (i == 0 || j == 0 || i == alto - 1 || j == ancho - 1 || rand() % 100 < 5) {
					mat[i][j] = 1; // Pared
				} 
				else {
					mat[i][j] = 0; // Piso
				}
			}
		}
	}

	~Escenario() {
		for (int i = 0; i < alto; i++) {
			delete[] mat[i];
		}
		delete[]mat;
	}

	void dibujar(Graphics^ g) {
		// Coordenada / tamaño = indice
		// Coordenada = indice * tamaño
		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				if (mat[i][j] == 1) {
					g->FillRectangle(Brushes::IndianRed, Rectangle(j * 50, i * 50, 50, 50));
				}
			}
		}
	}

	bool colision(int x, int y) {
		return mat[y / 50][x / 50];
	}

	bool colision(Rectangle rec) {
		return colision(rec.X, rec.Y) ||
			colision(rec.X + rec.Width, rec.Y) ||
			colision(rec.X + rec.Width, rec.Y + rec.Height) ||
			colision(rec.X, rec.Y + rec.Height);
	}
};
