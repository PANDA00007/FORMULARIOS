#pragma once
#include <iostream>

using namespace std;
using namespace System::Drawing;

#define anchoForm 800
#define altoForm 800

class CMovil {
protected: 
	int x, y;
	int alto, ancho;
	int dx, dy;
	int re, gr, bl;

public: 
	CMovil() {
		System::Random r;
		ancho = rand() % 100 + 50;
		alto = rand() % 100 + 50;
		x = rand() % (anchoForm - ancho);
		y = rand() % (altoForm - alto);
		do {
			dx = (rand() % 3 - 1) * 10;
			dy = (rand() % 3 - 1) * 10;
		} while (dx == 0 && dy == 0);
		re = rand() % 256;
		gr = r.Next(0, 256);
		bl = r.Next(0, 256);
	}

	~CMovil(){}

	int validarMov() {
		if (x + dx < 0 || x + dx + ancho > anchoForm) return 1;
		if (y + dy < 0 || y + dy + alto > altoForm) return 2;
		return 0;
	}

	void movInvalido(int eje) {
		System::Random r;
		if (eje == 1) dx = -dx;
		if (eje == 2) dy = -dy;
		if (eje == 3){ dy = 0; dx = 0; }
		if (eje == 4) {
			do {
				dx = (rand() % 3 - 1) * 10;
				dy = (rand() % 3 - 1) * 10;
			} while (dx == 0 && dy == 0);
		}
	}

	void mover() {
		x += dx;
		y += dy;
	}

	virtual void dibujar(Graphics^ g) {}

	CMovil(int n) {
		System::Random r;
		ancho = 50;
		alto = 50;
		x = rand() % (anchoForm - ancho);
		y = rand() % (altoForm - alto);
		do {
			dx = (rand() % 3 - 1) * 10;
			dy = (rand() % 3 - 1) * 10;
		} while (dx == 0 && dy == 0);
		re = rand() % 256;
		gr = r.Next(0, 256);
		bl = r.Next(0, 256);
	}

	// NO SE USA --- tons pa que lo puso xd
	/*bool colision(Rectangle rec) {
		return rec.IntersectsWith(getRec());
	}*/

	Rectangle getRec() {
		return Rectangle(x, y, ancho, alto);
	}

	Rectangle getFutRec() {
		// TOLERANCIA: en el caso de que calce exacto la figura, el programa no lo dejara pasar
		//            con ello, esto se usa para que pueda pasar por lugares "estrechos"
		int tolerancia = 3; 
		return Rectangle(x + dx + tolerancia, y + dy + tolerancia,
			          ancho - tolerancia * 2, alto - tolerancia * 2);
	}
	
	// En caso el objeto aparezca dentro de una pared, escoge un nuevo lugar
	void reposicion() {
		System::Random r;
		x = rand() % (anchoForm - ancho);
		y = rand() % (altoForm - alto);
	}
};