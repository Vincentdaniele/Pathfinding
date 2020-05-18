#ifndef CARTOGRAPHIE_H
#define CARTOGRAPHIE_H
#include "AStar.hpp"
#include <cmath>

using namespace AStar;
	class Cartographie
	{
	private:
		Vec2i* murs;
		int taille;
		int NbCellulesCarteLongueur;
		Generator* generator;

	public:
		// Contructeur : on renseigne le nombre de cellules en longueur et en largeur de notre labyrinthe
		Cartographie(Generator* generator);
		virtual ~Cartographie();
		// Ajoute un mur dans la cartographie entre la cellule A et la cellule B, le bool�en renvoie true si l'op�ration s'est bien d�roul�e
		// CelluleA et Cellule B sont des tableaux de deux �l�ments contenant les coordonn�es de la cellule
		// ex : CelluleA = [1 3] : cette cellule est sur la deuxi�me ligne et quatri�me colonne
		bool addWall(Vec2i celluleA);
		bool addElement(int x, int y);

		//Retourne les attributs priv�s de la classe

		int recupererNbCellulesCarteLongueur();
		int recupererNbCellulesCarteLargeur();


	};



#endif // !CARTOGRAPHIE_H
