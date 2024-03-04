#ifndef risiko_h
#define risiko_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	
	char nome[50];  //nome del giocatore
	int cannoni;	//numero di cannoni
	int x;			//posizione nella mappa
	int y;			//posizione nella mappa
	
}giocatori;

void crea_giocatori (giocatori *,int);
void stampa_mappa(int [4][4] ,giocatori *); 
void crea_mappa( int [4][4] , giocatori *,int);
void trova_max_min(giocatori [3],int *,int *,int );
void aggiorna_mappa (int [4][4],giocatori *,int , int );
int  tira_dadi();
void scontro (giocatori *,int, int, int [4][4]);
#endif
