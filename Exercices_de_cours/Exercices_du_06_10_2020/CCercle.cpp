#include "CCercle.h"

int CCercle::m_nCompteur = 0;

CCercle::CCercle(float fRayon, float fX, float fY):m_pCentre(fX,fY)
{
	this->m_fRayon = fRayon;
	m_nCompteur++;
}

float CCercle::Diametre()
//BUT :
//ENTREE : 
//SORTIE : 
{
	return 0.0f;
}

float CCercle::Circonference()
{
	return 0.0f;
}

float CCercle::Aire()
{
	return 0.0f;
}

bool CoincideAmi(CCercle& cCercle, CPoint pPoint)
{
	return ((pPoint.m_fX == cCercle.m_pCentre.m_fX) && (pPoint.m_fY == cCercle.m_pCentre.m_fY));
}
