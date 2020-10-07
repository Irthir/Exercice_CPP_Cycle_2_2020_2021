#pragma once

class CPoint
//DEFINITION : Classe repr�sentant un point dans un espace en deux dimensions, poss�dant comme membres deux nombres en X et Y repr�sentant sa position dans cet espace.
{
private:
	//Membres de la classe
	float m_fX;
	float m_fY;

	float m_fRho;
	float m_fTheta;

	static int nCompteur;

public:
	//Le Constructeur par d�faut
	CPoint();
	//Un autre constructeur possible
	CPoint(float fX, float fY);
	//Le Destructeur
	~CPoint();

	//Les fonctions membres de la classe
	void DeplacePoint(float fX,float fY);
	float const Abscisse();
	float const Ordonnee();

	void Homothetie(CPoint &pCentre, float fRapport);
	void Rotation(CPoint& pCentre, float fAngle);
	float const Rho(CPoint& pCentre);
	float const Theta(CPoint& pCentre);

	inline static int getCompteur() {return nCompteur;}

	//Assesseurs :
	float const getX();
	float const getY();
	//Mutateurs
	void setX(float fX);
	void setY(float fY);
};