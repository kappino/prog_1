#include "risiko.h"

//funzione per la creazione dei giocatori
void crea_giocatori (giocatori *id,int size){
	
	printf("\nCreazione giocatori..\n");
	//Giocatori di default
	strcpy(id[0].nome,"Pippo");
	strcpy(id[1].nome,"Pluto");
	strcpy(id[2].nome,"Paperino");
	
	int i;
	for(i=0;i<size;i++) {
		//se si usano i giocatori di default commentare le prossime due righe di codice
	//	printf("Inserisci nome giocatore %d: ",i+1);
	//	scanf(" %[^\n]",&id[i].nome);
		id[i].cannoni=rand() % (10 + 1 - 2) + 2;
	}
	
	printf("\nLista Giocatori: \n");
	
	for (i=0;i<size;i++) {
		printf("\nNome: %s",id[i].nome);
		printf("\nCannoni: %d",id[i].cannoni);
	}
}
void stampa_mappa(int mappa [4][4],giocatori *id) {
	
	char x ='X';
	printf("\n\nMappa di gioco:\n");  
	printf("\n|*********************|\n");
	int i,j;
	for (i=0;i<4;i++) {
		//printf("|                     |\n");
		for (j=0;j<4;j++) {
			if (mappa[i][j]==0) printf("| %c | ",x);
			else printf("| %d | ",mappa[i][j]);
		}//---------------------        
		printf("\n|*********************|\n");
	}
	
}

//funzione che assegna una posizione ai giocatori in una mappa 4x4
void crea_mappa ( int mappa [4][4],giocatori *id,int size) {
	int i,j;
	int k;
	for (i=0;i<size;i++) {
		//assegno una posizione random ad ogni giocatore, controllando che non sia già occupata
		id[i].x=rand() % (3 + 1 - 0) + 0;
		id[i].y=rand() % (3 + 1 - 0) + 0; 
		int k=0;
		while(k<i) {
			//Controllo se i valori sono uguali
			if(id[i].x==id[k].x && id[i].y==id[k].y) {
				//Valori uguali, li riscrivo
				id[i].x=rand() % (3 + 1 - 0) + 0;
				id[i].y=rand() % (3 + 1 - 0) + 0;
			} 
			else k++;
		} 
		
		mappa[id[i].x][id[i].y]=id[i].cannoni;
	}
	
		stampa_mappa(mappa,id);
	
}

//funzione che aggiorna il numero di cannoni dei giocatori dopo ogni scontro
void aggiorna_mappa (int mappa [4][4],giocatori *id,int max, int min) {
	
	mappa[id[max].x] [id[max].y]=id[max].cannoni;
	mappa[id[min].x] [id[min].y]=id[min].cannoni;
	stampa_mappa(mappa,id);

}

//funzione che trova il giocatore con più cannoni e quello con meno cannoni, determina chi attacca per primo
void trova_max_min(giocatori id[3], int *max,int *min,int size) {

	int i,t_max,t_min;	
		
	t_max=id[0].cannoni;
	t_min=id[0].cannoni;
	
	for (i=0;i<size;i++) {
		if(id[i].cannoni>t_max){
			t_max=id[i].cannoni;
			*max=i;
		} 
		else if (id[i].cannoni<t_min){
			t_min=id[i].cannoni;
			*min=i;
		} 
	}
}

//funzione che lancia e confronta i dadi 
int tira_dadi () {

	int vincitore;
	int x=(rand() % 6) + 1;
	int y=(rand() % 6) + 1;
	
	printf("\nAtt: %d Dif: %d",x,y);
	if(x>y) return 1;
	else return 0;
	
	
	
}

//funzione che regola lo scontro,controlla il numero di cannoni rimanenti e chiama le funzioni tira_dadi e aggiorna_mappa
void scontro (giocatori *id,int max,int min,int mappa [4][4]) {
	fflush(stdin);
	printf("\nPremi invio per tirare i dadi...");
	getchar();
	int i,n,z;
		if(id[max].cannoni < 3 ) n=id[max].cannoni;
		else if(id[min].cannoni < 3) n=id[min].cannoni;
		else n=3;
		for(i=0;i<n;i++) {
			z=tira_dadi();
			if(z==1)  {
				id[min].cannoni--;
				printf("  il difensore perde un cannone!\n");
			}
			if (z==0) {
				id[max].cannoni--;
				printf("  l'attaccante perde un cannone!\n");
			}
		}
		printf("\nAlla fine dello scontro %s ha %d cannoni e %s ha %d cannoni",id[max].nome,id[max].cannoni,id[min].nome,id[min].cannoni);
		aggiorna_mappa(mappa,id,max,min);

	
}




