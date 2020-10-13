#include "CPoint.h"
#include "CCercle.h" //Forward Declaration de CCercle.h (Post-Déclaration)
#include <math.h>
#include <cmath>
#include <iostream>

int CPoint::m_nCompteur=0;

//Le constructeur par défaut :
CPoint::CPoint()
{
	this->m_fX = 0;
	this->m_fY = 0;
	this->m_fRho = 0;
	this->m_fTheta = 0;
	m_nCompteur++;
}

//Un autre constructeur possible :
CPoint::CPoint(float fX, float fY)
{
	float const PI = 3.1415926;
	this->m_fX = fX;
	this->m_fY = fY;
	this->m_fRho = (float)sqrt((double)fX * fX + (double)fY * fY);
	float fTheta;
	if (this->m_fX == 0.0)
	{
		if (this->m_fY < 0.0)
		{
			fTheta = (3 * PI) / 2;
		}
		else {
			fTheta = PI / 2;
		}
	}
	else if (fX < 0.0)
	{
		fTheta = atan(fY / fX) + PI;
	}
	else {
		if (fY < 0.0)
		{
			fTheta = atan(fY / fX); +2 * PI;
		}
		else {
			fTheta = atan(fY /  fX);
		}
	}
	this->m_fTheta = fTheta;
	m_nCompteur++;
}

CPoint::CPoint(CPoint& pt)
{
	std::cout << "Appelle du constructeur par copie" << std::endl;
	this->m_fX = pt.m_fX;
	this->m_fY = pt.m_fY;
	this->m_fRho = pt.m_fRho;
	this->m_fTheta = pt.m_fTheta;
	//this->m_strType = new char[100];
	//strcpy_s(this->m_strType, 100, pt.m_strType;
	m_nCompteur++;
}

//Le Destructeur :
CPoint::~CPoint()
{
	m_nCompteur--;
}

CPoint operator+(CPoint const& pPoing, CPoint const& pPoint)
{
	CPoint pResult(pPoing.m_fX + pPoint.m_fX, pPoing.m_fY + pPoint.m_fY);
	return pResult;
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


	if (this->m_fX == 0.0)
	{
		if (this->m_fY < 0.0)
		{
			fTheta = (3 * PI) / 2;
		}
		else {
			fTheta = PI / 2;
		}
	}
	else if (this->m_fX < 0.0)
	{
		fTheta = atan(this->m_fY / this->m_fX) + PI;
	}
	else {
		if (this->m_fY < 0.0)
		{
			fTheta = atan(this->m_fY / this->m_fX) + 2 * PI;
		}
		else {
			fTheta = atan(this->m_fY / this->m_fX);
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

bool CPoint::Coincide(CCercle &cCercle)
{
	return ((this->m_fX == cCercle.m_pCentre.m_fX) && (this->m_fY == cCercle.m_pCentre.m_fY));
}