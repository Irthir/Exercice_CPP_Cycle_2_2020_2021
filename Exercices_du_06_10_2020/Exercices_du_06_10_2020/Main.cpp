#include "CPoint.h"
#include "CCercle.h"
#include <iostream>

using namespace std;

int main()
{
	/*
	Dans la situation ou une fonction doit partager des membres privées de deux classes,
	on fait une méthode d'une classe qui est amie d'une autre.
	Ne pas oublier la post et la pré-déclaration de la deuxième classe dans la première afin d'éviter une redondance dans les déclarations.
	*/

	CPoint point(10, 12);
	CCercle cercle(8.8, 10, 12);

	cout << point.Coincide(cercle) << endl;

	return 0;
}