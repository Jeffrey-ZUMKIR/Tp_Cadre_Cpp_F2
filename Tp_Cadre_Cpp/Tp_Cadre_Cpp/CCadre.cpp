#include "CCadre.h"
#include <iostream>
#include <string.h>

#define TAILLE 20
#define PI 3.14

using namespace std;

CCadre::CCadre()
{
	this->flt_x = 0;
	this->flt_y = 0;
	this->flt_larg = 0;
	this->flt_long = 0;
	this->pt_motif = new char[TAILLE];
	strcpy_s(this->pt_motif, TAILLE, "/");
	this->ptrCharNom_Cadre = new char[TAILLE];
	strcpy_s(this->ptrCharNom_Cadre, TAILLE, "/");
}

CCadre::CCadre(float flt_x, float flt_y, float flt_long, float flt_larg, char* pt_motif, char* c_nom)
{
	this->flt_x = flt_x;
	this->flt_y = flt_y;
	this->flt_larg = flt_larg;
	this->flt_long = flt_long;
	this->pt_motif = new char[TAILLE];
	strcpy_s(this->pt_motif, TAILLE, pt_motif);
	this->ptrCharNom_Cadre = new char[TAILLE];
	strcpy_s(this->ptrCharNom_Cadre, TAILLE, c_nom);
}

CCadre::CCadre(float flt_x, float flt_y, float flt_larg, char pt_motifBase, char c_nom)
{
	char *pt_motif = &pt_motifBase;
	char* pt_nom = &c_nom;
	this->flt_x = flt_x;
	this->flt_y = flt_y;
	this->flt_larg = flt_larg;
	this->flt_long = flt_larg*2;
	this->pt_motif = new char[TAILLE];
	strcpy_s(this->pt_motif, TAILLE, pt_motif);
	this->ptrCharNom_Cadre = new char[TAILLE];
	strcpy_s(this->ptrCharNom_Cadre, TAILLE, pt_nom);
}

CCadre::CCadre(CCadre& cdr)
{
	this->flt_x = cdr.flt_x;
	this->flt_y = cdr.flt_y;
	this->flt_long = cdr.flt_long;
	this->flt_larg = cdr.flt_larg;

	this->pt_motif = new char[TAILLE];
	strcpy_s(this->pt_motif, TAILLE, cdr.pt_motif);
	this->ptrCharNom_Cadre = new char[TAILLE];
	strcpy_s(this->ptrCharNom_Cadre, TAILLE, cdr.ptrCharNom_Cadre);
}

CCadre::~CCadre()
{
	delete[] pt_motif;
	delete[] ptrCharNom_Cadre;
}

float CCadre::getX() const
{
	return this->flt_x;
}

float CCadre::getY() const
{
	return this->flt_y;
}

float CCadre::getLong() const
{
	return this->flt_long;
}

float CCadre::getLarg() const
{
	return this->flt_larg;
}

char* CCadre::getMotif() const
{
	return this->pt_motif;
}

char* CCadre::getNom() const
{
	return this->ptrCharNom_Cadre;
}

void CCadre::setX(float flt_x)
{
	this->flt_x = flt_x;
}

void CCadre::setY(float flt_y)
{
	this->flt_y = flt_y;
}

void CCadre::setLong(float flt_long)
{
	this->flt_long = flt_long;
}

void CCadre::setLarg(float flt_larg)
{
	this->flt_larg = flt_larg;
}

void CCadre::setMotif(char* pt_motif)
{
	strcpy_s(this->pt_motif, TAILLE, pt_motif);
}

void CCadre::setNom(char* ptrCharNom_Cadre)
{
	strcpy_s(this->ptrCharNom_Cadre, TAILLE, ptrCharNom_Cadre);
}

void CCadre::afficheLog() const
{
	cout << "X : " << flt_x << endl;
	cout << "Y : " << flt_y << endl;
	cout << "Longueur : " << flt_long << endl;
	cout << "Largeur : " << flt_larg << endl;
	cout << "Motif : " << pt_motif << endl;
	cout << "Nom : " << ptrCharNom_Cadre << endl;
}

float CCadre::surfaceCadre() const
{
	float flt_surface = this->flt_larg * this->flt_long;
	return flt_surface;
}

float CCadre::perimetreCadre() const
{
	float flt_perimetre = this->flt_larg * 2 + this->flt_long * 2;
	return flt_perimetre;
}

bool CCadre::isCarre()
{
	if (this->flt_larg == this->flt_long) {
		return true;
	}
	else {
		return false;
	}
}

void CCadre::rotation(float flt_angle)
{
	this->flt_x = (this->flt_x - 0) * cos(flt_angle * PI / 180) + (this->flt_y - 0) * sin(flt_angle * PI / 180 + 0);
	this->flt_y = (this->flt_y - 0) * sin(flt_angle * PI / 180) + (this->flt_x - 0) * cos(flt_angle * PI / 180 + 0);
}
