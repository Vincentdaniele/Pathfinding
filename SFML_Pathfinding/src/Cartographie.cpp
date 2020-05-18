#include "Cartographie.h"
#include <iostream>
#include "AStar.hpp"

using namespace std;
using namespace AStar;

	Cartographie::Cartographie(Generator* Gen)
	{
		//initialisation des attributs
		NbCellulesCarteLongueur = 21;
		taille = 0;
		murs = new Vec2i[taille];
		generator = Gen;
		generator->setWorldSize({ NbCellulesCarteLongueur, NbCellulesCarteLongueur });
		generator->setHeuristic(Heuristic::euclidean);
		generator->setDiagonalMovement(false);

		// On initialise la carte : 1 = pas de mur , 9 = pr�sence d'un mur
		// Par d�faut, il n'y a aucun mur dans le labyrinthe sauf sur les bords


		for (int i = 0; i < NbCellulesCarteLongueur; i++) {
			(*generator).addCollision({ i,0 });
			addElement(i, 0);
			(*generator).addCollision({ i,NbCellulesCarteLongueur - 1 });
			addElement(i, NbCellulesCarteLongueur - 1);
			(*generator).addCollision({ 0,i });
			addElement(0, i);
			(*generator).addCollision({ NbCellulesCarteLongueur - 1,i });
			addElement(NbCellulesCarteLongueur - 1, i);
		}
	}

	Cartographie::~Cartographie()
	{

		delete[] murs;
	}


	bool Cartographie::addWall(Vec2i celluleA)
	{

				generator->addCollision(celluleA);
				addElement(celluleA.x, celluleA.y);
				return true;
	}

	bool Cartographie::addElement(int x, int y)
	{
		Vec2i* temp = murs;
		taille += 1;
		Vec2i coordonnees;
		coordonnees.x = x;
		coordonnees.y = y;

		murs = new Vec2i[taille];

		for (int i = 0; i < taille - 1; i++)
			murs[i] = temp[i];

		murs[taille - 1] = coordonnees;

		delete[] temp;

		return false;
	}
