#pragma once
#ifndef CCERCLE_H
#define CCERCLE_H
#include "CPoint.h"

class CCercle
//DEFINITION : Classe représentant un cercle.
{
private:
	//Membres de la classe
	float m_fRayon;
	CPoint m_pCentre;

	static int m_nCompteur;
public:
	//Constructeur
	CCercle(float fRayon = 0.0f, float fX = 0.0f, float fY = 0.0f);
	//Destructeur
	inline ~CCercle() { m_nCompteur--; }

	float Diametre();
	float Circonference(); //
	float Aire();

	//Assesseurs :
	inline float const getRayon() { return this->m_fRayon; }
	inline CPoint const getCentre() { return this->m_pCentre; }
	//Mutateurs
	inline void setRayon(float fRayon) { this->m_fRayon = fRayon; }
	inline void setCentre(CPoint pCentre) { this->m_pCentre = pCentre; }

	inline static int getCompteur() { return m_nCompteur; }

	//Fonction membre de la classe CPoint amie de la classe CCercle.
	friend bool CPoint::Coincide(CCercle &cCercle);

	friend bool CoincideAmi(CCercle& cCercle, CPoint pPoint);
};
#endif