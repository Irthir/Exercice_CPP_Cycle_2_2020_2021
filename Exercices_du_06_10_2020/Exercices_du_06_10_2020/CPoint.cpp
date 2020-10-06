#include "CPoint.h"

//Le constructeur par d�faut :
CPoint::CPoint()
{
	this->m_fX = 0;
	this->m_fY = 0;
}

void CPoint::DeplacePoint(float fX, float fY)
//BUT : D�placer un point selon X et Y.
//ENTREE : Le-dit point et les valeurs de translations en X et en Y.
//SORTIE : Le point d�plac�.
{
	this->m_fX += fX;
	this->m_fY += fY;
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
