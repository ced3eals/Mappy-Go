#include "prog.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

file creer_file_vide(){
	return NULL;
}

file inserer(file f, int x, int y, int valeur){
	file nouveau; 
	//pour un nouveau maillon
	nouveau = (file)malloc(sizeof(struct maillon));
	nouveau->x = x;
	nouveau->y = y;
	nouveau->valeur = valeur;

	nouveau->suivant = f;
	f = nouveau;
	return f;
}

file extraire(file f, int *x, int *y, int *valeur){
	file courant;

	if (f!= NULL){
		courant = f;
		*x = courant->x;
		*y = courant->y;
		*valeur = courant->valeur;
		f = courant->suivant;
		free(courant);
	}
	return f;
}

int est_file_vide(file f){
	return f == NULL;
}

/*void remplirManhattan(){
	int i;//ligne
	int j;//colonne

	file f = creer_file_vide();
	int x,y,val;

	x = x_but;
	y = y_but;
	f = inserer(f,x,y,0); //inserer le point de depart, on peut le faire apparaitre aléatoirement en ne prenant que les 0
	while(!est_file_vide(f)){
		f = extraire(f,&x,&y,&val);

		if(workspace[x][y]!=2){ //Ajouter si case dispo
			if(x-1 && workspace[x-1][y]==-1 && workspace[x-1][y]!=-2){
				f = inserer(f,x-1,y,val+1);
				workspace[x-1][y]=val+1;
			}
			if(x+1 && workspace[x+1][y]==-1 && workspace[x+1][y]!=-2){
				f = inserer(f,x+1,y,val+1);
				workspace[x+1][y]=val+1;
			}
			if(y-1>=0 && workspace[x][y-1]==-1 && workspace[x][y-1]!=-2){
				f = inserer(f,x,y-1,val+1);
				workspace[x+1][y]=val+1;
			}
			if(y+1<nbcolonne && workspace[x][y+1]==-1 && workspace[x][y+1]!=-2){
				f = inserer(f,x,y+1,val+1);
				workspace[x][y+1]=val+1;
			}
		}
	}
	//Afficher resultat
	printf("Matrice de distance\n");
	for(i=0;i < nbligne;i++){
		for (j=0; j < nbcolonne; j++){
			if(workspace[i][j]>=0)
				printf("\t %d ",workspace[i][j]);
			else
				printf("\t%d ",workspace[i][j]);
		}
		printf("\n");
	}
}


//while(getchar() != '\n');

//Calculer et afficher le plus court chemin du départ à l'arrivée

void plusCourtChemin(){
	printf("Affichage du plus court chemin \n\n Position x, y et valeur de la case courante\n");
	int x,y,xmin,ymin,min,cpt;
	x=x_depart;
	y=y_depart;
	xmin=x;
	ymin=y;
	min = workspace[x][y];
	printf("x=%d y=%d et min =%d\n",x,y,min); //pour afficher la position courante
if(workspace[x][y]!= -1){
	while(workspace[x][y] != 0){ //tant que le but n'est pas arrivé
		if(x-1>=0 && workspace[x-1][y] < min && workspace[x-1][y]!=-2){ //haut
			min = workspace[x-1][y];
			xmin = x-1;
			ymin = y;
		suivant}

		if(x+1<nbligne && workspace[x+1][y] < min && workspace[x+1][y]!=-2){ //bas
			min = workspace[x+1][y];
			xmin = x+1;
			ymin = y;
		}
		if(y-1>=0 && workspace[x][y-1] < min && workspace[x][y-1]!=-2){ //gauche
			min = workspace[x][y-1];
			xmin = x;
			ymin = y-1;
		}
		if(y+1< nbcolonne && workspace[x][y+1] < min && workspace[x][y+1]!=-2){ //droite
			min = workspace[x][y+1];
			xmin = x;
			ymin = y+1;
		}
		x=xmin;
		y=ymin;
		//printf("%d %d %d\n",x,y,min );//déplacement à effectuer
		cpt++;
		}
		printf("établit en %d étapes\n", cpt);
	}
	else{
		printf("Impossible à résoude !\n");
	}
}*/