#include "CPoint.h"
#include <iostream>

using namespace std;

void AffichePoint(CPoint pPoint);

int main()
{
	CPoint pPoint;
	AffichePoint(pPoint);
	pPoint.DeplacePoint(94.2f, 54.8f);
	AffichePoint(pPoint);
	return 0;
}

void AffichePoint(CPoint pPoint)
//BUT : Afficher les coordonn�es d'un point.
//ENTREE : Le-dit point.
//SORTIE : Les coordonn�es affich�es sur la console.
{
	cout << "Notre point a pour coordonnees X = " << pPoint.getX() << " Y = " << pPoint.getY() << endl;
}