#pragma once
#include "Figura.h"

class Rombo : public Figura {

private: 
	int anchoR;
	int altoR;

public: 
	Rombo(int x, int y, int anchoR, int altoR) : Figura(x, y) {
		this->anchoR = anchoR;
		this->altoR = altoR;
	}
	~Rombo(){}

	void mover(Graphics^ g) {
		Figura::mover(g);
	}
	void dibujar(Graphics^ g) {
		cli::array<Point>^ pts = {Point(x + (anchoR / 2), y),
			Point(x + anchoR, y + (altoR / 2)),
			Point(x + (anchoR / 2), y + altoR),
			Point(x, y + (altoR / 2))};
		g->DrawPolygon(Pens::Red, pts);
	}
	
	void borrar(Graphics^ g) {
		cli::array<Point>^ pts = { Point(x + (anchoR / 2), y),
			Point(x + anchoR, y + (altoR / 2)),
			Point(x + (anchoR / 2), y + altoR),
			Point(x, y + (altoR / 2)) };
		g->DrawPolygon(Pens::White, pts);
	}
};