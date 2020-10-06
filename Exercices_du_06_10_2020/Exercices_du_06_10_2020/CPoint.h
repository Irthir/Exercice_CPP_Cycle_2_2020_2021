#pragma once

class CPoint
//DEFINITION : Classe représentant un point dans un espace en deux dimensions, possédant comme membres deux nombres en X et Y représentant sa position dans cet espace.
{
private:
	//Membres de la classe
	float m_fX;
	float m_fY;

public:
	//Le Constructeur par défaut
	CPoint();

	//Les fonctions membres de la classe
	void DeplacePoint(float fX,float fY);

	//Assesseurs :
	float const getX();
	float const getY();
	//Mutateurs
	void setX(float fX);
	void setY(float fY);
};