#ifndef dischi_h
#define dischi_h

#include <stdio.h>
#include <string.h>
//definizione di una struct con le caratteristiche richieste
typedef struct {
	
	char titolo[50];
	char autore[50];
	char codice[11];
	int prezzo;
	int presente; 

}dischi;

void inserisci_disco(dischi *,int *); 
void genera_codice(int, dischi *);
void ricerca_autore (dischi [], int );
void stampa_elenco(dischi [], int );
int ricerca_prezzo(dischi [],int,int);

#endif
