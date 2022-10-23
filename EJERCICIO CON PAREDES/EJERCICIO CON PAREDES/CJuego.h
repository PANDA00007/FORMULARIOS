#pragma once
#include "CElipse.h"
#include "CRombo.h"
#include "CTriangulo.h"
#include "CRectangulo.h"
#include "CEscenario.h"
#include <vector>

class Juego {
private: 
	vector <CMovil*> vecFiguras;
	Escenario* mapita;

public: 

	Juego() {
		// La cantidad de figuras
		for (int i = 0; i < 8; i++) {
			vecFiguras.push_back(new Rectangulo(1));
			vecFiguras.push_back(new Elipse(1));
			vecFiguras.push_back(new Triangulo(1));
			vecFiguras.push_back(new Rombo(1));
		}
		mapita = new Escenario();
		for (int i = 0; i < vecFiguras.size(); i++) {
			while (mapita->colision(vecFiguras.at(i)->getRec()))
				vecFiguras.at(i)->reposicion();
		}
	}

	~Juego(){}

	void jugar(Graphics^ g) {
		mapita->dibujar(g);
		for (int i = 0; i < vecFiguras.size(); i++) {
			// borrar
			int aux = vecFiguras.at(i)->validarMov();
			if (aux || mapita->colision(vecFiguras.at(i)->getFutRec())) {
				vecFiguras.at(i)->movInvalido(4);
			}
			else vecFiguras.at(i)->mover();

			vecFiguras.at(i)->dibujar(g);
		}
	}

};