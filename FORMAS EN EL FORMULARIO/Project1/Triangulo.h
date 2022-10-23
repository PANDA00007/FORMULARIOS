#pragma once
#include "Figura.h"

class Triangulo : public Figura {
private: 
	int altoT;
	int base;

public:

	Triangulo(int x, int y, int altoT, int base) : Figura(x, y) {
		this->altoT = altoT;
		this->base = base;
	}

	~Triangulo(){}
	void dibujar(Graphics^ g) {
		cli::array <Point>^ pts = { Point(x,y),
		Point(x, y + altoT),
		Point(x + base, y + altoT) };
		g->DrawPolygon(Pens::ForestGreen, pts);
	}
	void mover(Graphics^ g) {
		Figura::mover(g);
	}
	void borrar(Graphics^ g) {
		cli::array <Point>^ pts = { Point(x,y),
			Point(x, y + altoT),
			Point(x + base, y + altoT) };
		g->DrawPolygon(Pens::White, pts);
	}
};
