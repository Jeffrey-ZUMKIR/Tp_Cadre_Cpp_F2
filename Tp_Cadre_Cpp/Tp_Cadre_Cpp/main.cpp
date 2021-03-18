#include "CCadre.h"
#include <string.h>
#include <iostream>

#define TAILLE 20

using namespace std;

int main() {

	char* pt_motif = new char[TAILLE];
	strcpy_s(pt_motif, TAILLE, "carreaux");
	char* ptrCharNom_Cadre = new char[TAILLE];
	strcpy_s(ptrCharNom_Cadre, TAILLE, "nom1");
	CCadre c1(2,4,6,8,pt_motif, ptrCharNom_Cadre);
	CCadre c2 = c1;

	//Affichage
	c1.afficheLog();
	c2.afficheLog();

	//Modification des valeurs longueur, largeur et le motif
	c1.setLarg(10);
	c1.setLong(9);
	strcpy_s(pt_motif, TAILLE, "pointille");
	c1.setMotif(pt_motif);
	c1.afficheLog();

	//Calcul de la surface et périmètre
	float surface = c1.surfaceCadre();
	float perim = c1.perimetreCadre();

	//Vérification si c'est un carré
	if (c1.isCarre()) {
		cout << "C'est un carré!" << endl;
	}
	else {
		cout << "Ce n'est pas un carré!" << endl;
	}

	c1.rotation(2, 1, 2);
	c1.afficheLog();
	

	delete[] pt_motif;
	delete[] ptrCharNom_Cadre;

	return 0;
}