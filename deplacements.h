#ifndef __deplacements_H__
#define __deplacements_H__
#include "prog.h"

#define MAXLINE 1000
#define NBLIN 64
#define NBCOL 152
#define SOL -1
#define SOL1 3
#define SOL2 5
#define SOL3 7
#define MUR -2
#define MUR1 -3
#define MUR2 -4
#define MUR3 -5
#define FEU_R -8
#define FEU_V -6
#define FEU_O -7
#define MURTI -9
#define POINT -10
#define MUR_M -14
#define MUR_A -15
#define MUR_S -16
#define MUR_O -17
#define MUR_N -18
#define MUR_T -19
#define MUR_H -20
#define MUR_I -21
#define MUR_E -22
#define MUR_U -23
#define MUR_R -24
#define MUR_W -25
#define MUR_P -26
#define MUR_K -27
#define MUR_G -28
#define MUR_F -29
#define MUR_C -30
#define MUR_Y -31
#define MUR_J -32
#define MUR_D -33
#define MUR_L -34
#define MUR_B -35
#define MUR_V -36

#define BUT 0
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define ORANGE  "\x1B[33m"
#define BLU  "\x1B[34m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int **workspace;
//int nbcolonne, nbligne;
int x_but, y_but;
int x_depart, y_depart;
int tab[NBLIN][NBCOL];
int tab_num[NBLIN][NBCOL];
int tab_trajet[NBLIN][NBCOL];
int maj_depart_x;
int maj_depart_y;
int musique;
int cpt;

int remplirWorkspace(char c, int *x, int *y);
void remplirManhattan();
void plusCourtChemin_1();
void plusCourtChemin_2();
void my_delay(double i);
void msg_bvn();
void anim_bvn();
int Menu();
void end();
void quitter();
int difficulte();
#endif
