#pragma once
#include "CMovil.h"

class Rectangulo : public CMovil {

public:
	Rectangulo() : CMovil() {}
	Rectangulo(int n) : CMovil(n) {}
	~Rectangulo() {}
	void dibujar(Graphics^ g) {
		g->DrawRectangle(gcnew Pen(Color::FromArgb(re, gr, bl)), Rectangle(x, y, ancho, alto));
	}


};