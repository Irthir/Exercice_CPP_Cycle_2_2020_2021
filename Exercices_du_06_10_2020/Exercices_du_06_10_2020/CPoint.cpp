#include "CPoint.h"

//Le constructeur par défaut :
CPoint::CPoint()
{
	this->m_fX = 0;
	this->m_fY = 0;
}

void CPoint::DeplacePoint(float fX, float fY)
//BUT : Déplacer un point selon X et Y.
//ENTREE : Le-dit point et les valeurs de translations en X et en Y.
//SORTIE : Le point déplacé.
{
	this->m_fX += fX;
	this->m_fY += fY;
}

float CPoint::Abscisse()
//BUT : Retourner la valeur en X d'un point.
//ENTREE : Le-dit point.
//SORTIE : La valeur en X du-dit point.
{
	return this->getX();
}

float CPoint::Ordonnee()
//BUT : Retourner la valeur en Y d'un point.
//ENTREE : Le-dit point.
//SORTIE : La valeur en Y du-dit point.
{
	return this->getY();
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
