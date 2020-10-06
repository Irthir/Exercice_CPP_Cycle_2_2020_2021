#include "CPoint.h"
#include <iostream>

using namespace std;

void AffichePoint(CPoint pPoint);

int main()
{
	CPoint pPoint;
	//AffichePoint(pPoint);
	cout << "Notre point a pour coordonnees Abscisse : " << pPoint.Abscisse() << " Ordonnee : " << pPoint.Ordonnee() << endl;
	pPoint.DeplacePoint(94.2f, 54.8f);
	//AffichePoint(pPoint);
	cout << "Notre point a pour coordonnees Abscisse : " << pPoint.Abscisse() << " Ordonnee : " << pPoint.Ordonnee() << endl;
	return 0;
}

/*void AffichePoint(CPoint pPoint)
//BUT : Afficher les coordonnées d'un point.
//ENTREE : Le-dit point.
//SORTIE : Les coordonnées affichées sur la console.
{
	cout << "Notre point a pour coordonnees X = " << pPoint.getX() << " Y = " << pPoint.getY() << endl;
}*/