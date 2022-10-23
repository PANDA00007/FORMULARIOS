#pragma once
#include "Figura.h"

class Elipse : public Figura {
private: 
	int diam1;
	
public: 
	Elipse(int x, int y, int diam1) : Figura(x, y) {
		this->diam1 = diam1;
	}

	~Elipse(){}
	void dibujar(Graphics^ g) {
		g->DrawEllipse(gcnew Pen(Color::DarkSalmon), x, y, 2 * diam1, diam1);
	}
	void mover(Graphics^ g) {
		Figura::mover(g);
	}
	void borrar(Graphics^g) {
		g->DrawEllipse(gcnew Pen(Color::White), x, y, 2 * diam1, diam1);
	}
};