#include "CPoint.h"
#include <iostream>

using namespace std;

void AffichePoint(CPoint pPoint);

int main()
{
	cout << "Nombre de poins actuels : " << CPoint::getCompteur() << "." << endl;
	CPoint pPoint;
	cout << "Nombre de poins actuels : " <<CPoint::getCompteur() << "." << endl;

	//AffichePoint(pPoint);
	cout << "Notre point a pour coordonnees Abscisse : " << pPoint.Abscisse() << " Ordonnee : " << pPoint.Ordonnee() << endl;
	pPoint.DeplacePoint(40, 60);
	//AffichePoint(pPoint);
	cout << "Notre point a pour coordonnees Abscisse : " << pPoint.Abscisse() << " Ordonnee : " << pPoint.Ordonnee() << endl;
	CPoint pCentre(10, 15);
	cout << "Nombre de poins actuels : " << CPoint::getCompteur() << "." << endl;

	cout << "Homothetie de notre point par rapport a un point en (10,15) de rapport 0,25." << endl;
	pPoint.Homothetie(pCentre, 0.25f);
	cout << "Notre point a pour coordonnees Abscisse : " << pPoint.Abscisse() << " Ordonnee : " << pPoint.Ordonnee() << endl;
	cout << "Rotation de notre point par rapport a un point en (10,15) d'angle 170." << endl;
	pPoint.Rotation(pCentre, 170);
	cout << "Notre point a pour coordonnees Abscisse :  "<< pPoint.Abscisse() << " Ordonnee : " << pPoint.Ordonnee() << endl;

	cout << "Notre point par rapport au centre en (10,15) a pour coordonnees polaires : Rho = " << pPoint.Rho(pCentre) << " Theta = " << pPoint.Theta(pCentre) << "." << endl;

	cout << "Nombre de poins actuels : " << CPoint::getCompteur() << "." << endl;

	return 0;
}

/*void AffichePoint(CPoint pPoint)
//BUT : Afficher les coordonnées d'un point.
//ENTREE : Le-dit point.
//SORTIE : Les coordonnées affichées sur la console.
{
	cout << "Notre point a pour coordonnees X = " << pPoint.getX() << " Y = " << pPoint.getY() << endl;
}*/