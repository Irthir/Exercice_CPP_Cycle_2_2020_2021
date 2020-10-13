#include "CPoint.h"
#include "CCercle.h"
#include <iostream>

using namespace std;

int main()
{
	/*
	Dans la situation ou une fonction doit partager des membres priv�es de deux classes,
	on fait une m�thode d'une classe qui est amie d'une autre.
	Ne pas oublier la post et la pr�-d�claration de la deuxi�me classe dans la premi�re afin d'�viter une redondance dans les d�clarations.
	*/

	CPoint point(10, 12);
	CCercle cercle(8.8, 10, 12);

	cout << point.Coincide(cercle) << endl;

	return 0;
}