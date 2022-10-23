#pragma once
#include "CMovil.h"

class Elipse : public CMovil {

public:
	Elipse() : CMovil() {}
	Elipse(int n) : CMovil(n) {}
	~Elipse() {}
	void dibujar(Graphics^ g) {
		g->DrawEllipse(gcnew Pen(Color::FromArgb(re, gr, bl)), Rectangle(x, y, ancho, alto));
	}


};