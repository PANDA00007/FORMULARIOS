#pragma once
#include "CMovil.h"

class Triangulo : public CMovil {
public: 
	Triangulo() : CMovil(){}
	Triangulo(int n) : CMovil(n){}
	~Triangulo(){}
	void dibujar(Graphics^ g) {
		cli::array<Point>^ arr = { Point(x,y), Point(x, y + alto),
		Point(x + ancho, y + alto)};
		g->DrawPolygon(gcnew Pen(Color::FromArgb(re, gr, bl)), arr);
	}
};
