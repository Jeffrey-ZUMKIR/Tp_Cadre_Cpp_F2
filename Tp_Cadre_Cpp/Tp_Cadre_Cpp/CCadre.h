#pragma once

using namespace std;

class CCadre {
private:
	float flt_x, flt_y, flt_long, flt_larg;
	char* pt_motif;
	char* ptrCharNom_Cadre;

public:
	//Constructeur
	//Sans paramètre
	CCadre();
	//Avec paramètre
	CCadre(float, float, float, float, char*, char*);
	//Avec valeur par défaut
	CCadre(float flt_x = 10, float flt_y = 5, float flt_larg = 5, char motifBase = '*', char c_nom='/');

	//Constructeur de copie
	CCadre(CCadre&);

	//Destructeur
	~CCadre();

	//Accesseurs
	float getX()const;
	float getY()const;
	float getLong()const;
	float getLarg()const;
	char* getMotif()const;
	char* getNom()const;

	//Mutateurs
	void setX(float);
	void setY(float);
	void setLong(float);
	void setLarg(float);
	void setMotif(char*);
	void setNom(char*);

	//Affichage
	void afficheLog()const;

	//Surface
	float surfaceCadre()const;

	//Perimètre
	float perimetreCadre()const;

	//Check si carré
	bool isCarre();

	//Rotation
	void rotation(float);
	
};