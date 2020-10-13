#include "CPoint.h"
#include "CCercle.h"
#include <iostream>

using namespace std;

int main()
{
	CPoint point(10, 12);
	
	//Le constructeur par copie.
	CPoint pPoint(point); //Equivalent de CPoint pPoint = point;

	//La surcharge de l'opérateur +
	point = point + pPoint;// +point + pPoint;

	cout << " X = " << point.getX() << " Y = " << point.getY() << endl;

	return 0;
}