#pragma once
#include "CMovil.h"

class Rombo : public CMovil {

public:
	Rombo() : CMovil(){}
	Rombo(int n) : CMovil(n) {}
	~Rombo() {}
	void dibujar(Graphics^ g) {
		cli::array<Point>^ pts = { Point(x + (ancho / 2), y),
			Point(x + ancho, y + (alto / 2)),
			Point(x + (ancho / 2), y + alto),
			Point(x, y + (alto / 2)) };
		g->DrawPolygon(gcnew Pen(Color::FromArgb(re, gr, bl)), pts);
	}


};