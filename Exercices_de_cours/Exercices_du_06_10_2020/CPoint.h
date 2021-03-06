#pragma once
#ifndef CPOINT_H
#define CPOINT_H

class CCercle; //Pr�-d�claration de la classe cercle.
class CPoint
//DEFINITION : Classe repr�sentant un point dans un espace en deux dimensions, poss�dant comme membres deux nombres en X et Y repr�sentant sa position dans cet espace.
{
private:
	//Membres de la classe
	float m_fX;
	float m_fY;

	float m_fRho;
	float m_fTheta;

	static int m_nCompteur;

public:
	//Le Constructeur par d�faut
	CPoint();
	//Un autre constructeur possible
	CPoint(float fX, float fY);
	//Le constructeur par copie
	CPoint(CPoint&); //Dans un singleton si on met son prototype en priv�e et sa d�finition vide pour l'emp�cher de l'utiliser.
	//Le Destructeur
	~CPoint();

	//La surcharge de l'op�rateur +
	//Cas Fonction Membre.
	//CPoint operator+(CPoint const pPoint);
	//Cas passage par pointeur
	//CPoint* CPoint::operator+(const CPoint pt);
	//Cas Fonction Amie.
	friend CPoint operator+(CPoint const& pPoing, CPoint const& pPoint);

	//Surcharge = (assignation de CPoint)
	CPoint operator=(const CPoint&);

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