#pragma once
#include "Cuadrado.h"
#include "Circulo.h"
#include "Elipse.h"
#include "Rombo.h"
#include "Triangulo.h"
#include <vector>

using namespace System::Drawing;
using namespace std;
using namespace System;

class ArregloFiguras {
private:
	vector <Figura*>* arrf;
public: 
	ArregloFiguras();
	~ArregloFiguras();
	void mostrar(Graphics^ g);
	void agregarFigura(Graphics^ g, char op);
};

ArregloFiguras::ArregloFiguras() {
	arrf = new vector<Figura*>();
}

ArregloFiguras::~ArregloFiguras() {
	delete arrf;
}

void ArregloFiguras::mostrar(Graphics^ g) {
	//accediendo a los elementos del arreglo
	for (int i = 0; i < arrf->size(); i++) {
		arrf->at(i)->borrar(g);
		arrf->at(i)->mover(g);
		arrf->at(i)->dibujar(g);
	}
}

void ArregloFiguras::agregarFigura(Graphics^ g, char op) {
	Random r;
	Figura* fig; // declaramos un objeto de tipo Figura
	switch (op) {
	case 'C':
		//aplicamos polimorfismo	
		fig = new Circulo(r.Next(g->VisibleClipBounds.Right), r.Next(g->VisibleClipBounds.Bottom), r.Next(10, 30));
		break;
	case 'D':
		fig = new Cuadrado(r.Next(g->VisibleClipBounds.Right), r.Next(g->VisibleClipBounds.Bottom), r.Next(10, 30));
		break;
	case 'E':
		fig = new Elipse(r.Next(g->VisibleClipBounds.Right), r.Next(g->VisibleClipBounds.Bottom), r.Next(10, 30));
		break;
	case 'R': 
		fig = new Rombo(r.Next(g->VisibleClipBounds.Right), r.Next(g->VisibleClipBounds.Bottom), r.Next(10, 30), r.Next(10, 30));
		break;
	case 'T': 
		fig = new Triangulo(r.Next(g->VisibleClipBounds.Right), r.Next(g->VisibleClipBounds.Bottom), r.Next(10, 30), r.Next(10, 30));
		break;
	default: 
		break;
	}

	arrf->push_back(fig); // fig es variable polifórmica
	
}

