#pragma once
#ifndef CPOINT_H
#define CPOINT_H

class CCercle; //Pré-déclaration de la classe cercle.
class CPoint
//DEFINITION : Classe représentant un point dans un espace en deux dimensions, possédant comme membres deux nombres en X et Y représentant sa position dans cet espace.
{
private:
	//Membres de la classe
	float m_fX;
	float m_fY;

	float m_fRho;
	float m_fTheta;

	static int m_nCompteur;

public:
	//Le Constructeur par défaut
	CPoint();
	//Un autre constructeur possible
	CPoint(float fX, float fY);
	//Le constructeur par copie
	CPoint(CPoint&); //Dans un singleton si on met son prototype en privée et sa définition vide pour l'empêcher de l'utiliser.
	//Le Destructeur
	~CPoint();

	//La surcharge de l'opérateur +
	friend CPoint operator+(CPoint const& pPoing,CPoint const& pPoint);

	//Les fonctions membres de la classe
	void DeplacePoint(float fX,float fY);
	float const Abscisse();
	float const Ordonnee();

	void Homothetie(CPoint &pCentre, float fRapport);
	void Rotation(CPoint& pCentre, float fAngle);
	float const Rho(CPoint& pCentre);
	float const Theta(CPoint& pCentre);

	//Fonction membre de la classe point.
	bool Coincide(CCercle& cCercle);

	friend bool CoincideAmi(CCercle &cCercle, CPoint pPoint);

	inline static int getCompteur() {return m_nCompteur;}

	//Assesseurs :
	float const getX();
	float const getY();
	//Mutateurs
	void setX(float fX);
	void setY(float fY);
};

#endif // !CPOINT_H