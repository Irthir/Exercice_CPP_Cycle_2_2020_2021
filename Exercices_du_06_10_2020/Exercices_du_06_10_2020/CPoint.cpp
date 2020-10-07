#include "CPoint.h"
#include <math.h>
#include <cmath>

int CPoint::nCompteur=0;

//Le constructeur par défaut :
CPoint::CPoint()
{
	this->m_fX = 0;
	this->m_fY = 0;
	this->m_fRho = 0;
	this->m_fTheta = 0;
	nCompteur++;
}

//Un autre constructeur possible :
CPoint::CPoint(float fX, float fY)
{
	this->m_fX = fX;
	this->m_fY = fY;
	this->m_fRho = (float)sqrt((double)fX * fX + (double)fY * fY);
	if (fX > 0.001 || fX < -0.001) {
		this->m_fTheta = atanf(fY / fX);
	}
	else
	{
		if (fY > 0)
		{
			this->m_fTheta = 90;
		}
		else
		{
			this->m_fTheta = -90;
		}
	}
	nCompteur++;
}

//Le Destructeur :
CPoint::~CPoint()
{
	nCompteur--;
}

void CPoint::DeplacePoint(float fX, float fY)
//BUT : Déplacer un point selon X et Y.
//ENTREE : Le-dit point et les valeurs de translations en X et en Y.
//SORTIE : Le point déplacé.
{
	this->m_fX += fX;
	this->m_fY += fY;
}

float const CPoint::Abscisse()
//BUT : Retourner la valeur en X d'un point.
//ENTREE : Le-dit point.
//SORTIE : La valeur en X du-dit point.
{
	return this->getX();
}

float const CPoint::Ordonnee()
//BUT : Retourner la valeur en Y d'un point.
//ENTREE : Le-dit point.
//SORTIE : La valeur en Y du-dit point.
{
	return this->getY();
}

void CPoint::Homothetie(CPoint& pCentre, float fRapport)
//BUT : Réaliser l'homothétie de notre point par selon à un point central et un rapport.
//ENTREE : Notre point, le point central et le rapport.
//SORTIE : Notre point déplacé par rapport à ces paramètres.
{
	if (pCentre.m_fX == 0 && pCentre.m_fY == 0)
	{
		this->m_fX = this->m_fX * fRapport;
		this->m_fY = this->m_fY * fRapport;
	}
	else
	{
		this->m_fX = (this->m_fX - pCentre.m_fX) * fRapport + pCentre.m_fX;
		this->m_fY = (this->m_fY - pCentre.m_fY) * fRapport + pCentre.m_fY;
	}
}

void CPoint::Rotation(CPoint& pCentre, float fAngle)
//BUT : Effectuer une rotation pour notre point en fonction d'un point central et d'un angle.
//ENTREE : Notre point, le point central et l'angle de rotation.
//SORTIE : Notre point déplacé après la rotation.
{
	float const PI = 3.1415926;

	while(fAngle >= 360)
	{
		fAngle -= 360;
	}
	float fX = this->m_fX - pCentre.m_fX;
	float fY = this->m_fY - pCentre.m_fY;

	float fRad=(PI / 180);
	float fCos = (float)cos((double)fAngle * fRad);
	float fSin = (float)sin((double)fAngle * fRad);

	this->m_fX = fX * fCos + fY * fSin + pCentre.m_fX; // X1' = X1*cos + Y1*sin +Y2
	this->m_fY = fX * fSin + fY * fCos + pCentre.m_fY; // Y1' = X1*sin + Y1*cos +Y2
}

float const CPoint::Rho(CPoint &pCentre)
//BUT : Récupérer la coordonnée polaire Rho à partir de notre point et d'un point central.
//ENTREE : Notre point et le point central.
//SORTIE : La coordonnée polaire Rho calculée.
{
	float fX = this->m_fX - pCentre.m_fX;
	float fY = this->m_fY - pCentre.m_fY;
	float fRho = (float)sqrt((double)fX * fX + (double)fY * fY);
	return fRho;
}

float const CPoint::Theta(CPoint &pCentre)
//BUT : Récupérer la coordonnée polaire Thêta à partir de notre point et d'un point central.
//ENTREE : Notre point et le point central.
//SORTIE : La coordonnée polaire Thêta calculée.
{
	const float PI = 3.14159265;
	float fX = this->m_fX - pCentre.m_fX;
	float fY = this->m_fY - pCentre.m_fY;
	float fTheta;
	if (fX > 0.001 || fX < -0.001) {
		fTheta = atanf(fY/fX);
	}
	else
	{
		if (fY > 0)
		{
			fTheta = 0.5*PI;
		}
		else
		{
			fTheta = -0.5*PI;
		}
	}
	return fTheta;
}

//Les assesseurs :
float const CPoint::getX()
{
	return this->m_fX;
}

float const CPoint::getY()
{
	return this->m_fY;
}

//Les mutateurs :
void CPoint::setX(float fX)
{
	this->m_fX = fX;
}

void CPoint::setY(float fY)
{
	this->m_fY = fY;
}
