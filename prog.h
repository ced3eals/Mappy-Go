#ifndef __prog_H__
#define __prog_H__

struct maillon;

typedef struct maillon *file;

struct maillon {
	int x;
	int y;
	int valeur;
	file suivant;
};

file creer_file_vide();
file inserer(file f, int x, int y, int valeur);
file extraire(file f, int *x, int *y, int *valeur);
int est_file_vide(file f); //qui doit retourner 1 si la file est vide
int Menu();
#endif