#include "risiko.h"
/*Programma che simula la fase di attacco del gioco Risiko
Step:
Inseririmento nomi dei giocatori, gli verrà assegnato automaticamente un numero random di cannoni
Creazione mappa di gioco
Controllo del numero dei cannoni, per la ricerca del max e del min
Inizio della fase di attacco
Ogni round tramite la pressione del tasto invio verrà simulato il lancio dei dadi
per determinare il vincitore di ogni scontro
Lo scontro finsisce quando uno dei due giocatori termina i cannoni
*/

int main ( ) {
	
	srand ( time(NULL) ); 		//genera il seme per la scelta casuale dei numeri (in questo caso in base all'orario del sistema)
	int size=3;
	//	printf("\nQuanti giocatori ci sono? ");
	//	scanf(" %d",&size);   	//nel caso in cui si volesse modificare il numero di giocatori
	giocatori id[size];      	//crea un array di struct giocatore 
	int mappa [4][4]={0};	 	//inizializza una matrice 4x4 che formerò la nostra mappa,tutte le caselle vengono poste a zero
	int max=0,min=0;	  		//indici per determinare chi è il giocatore con più cannoni e chi quello con meno
	printf("\nBenvenuto in Risiko!");
	crea_giocatori (id,size);
	trova_max_min(id,&max,&min,size);
	crea_mappa(mappa,id,size);
	
	printf("\n%s con %d cannoni attacca %s che si difende con %d cannoni",id[max].nome,id[max].cannoni,id[min].nome,id[min].cannoni);
	//lo scontro termina quando uno dei due giocatori termina i cannoni
	while(id[max].cannoni>0 && id[min].cannoni>0) scontro(id,max,min,mappa);
	
	
	
	
	return 0;
}


