#include "CCercle.h"

int CCercle::m_nCompteur = 0;

CCercle::CCercle(float fRayon, float fX, float fY)
{
	this->m_fRayon = fRayon;
	CPoint pCentre(fX, fY);
	this->m_pCentre = pCentre;
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