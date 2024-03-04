#include "dischi.h"

void genera_codice(int count,dischi *archivio) {
	
	//generazione di un codice identificativo unico
	char temp_code[20]="dsk00"; //formato da una radice comune a tutti
	int i;
	for(i=0;i<2;i++) {
		temp_code[5+i]=archivio[count].titolo[i];  //dalle prime due lettere del titolo
	}
	for (i=0;i<2;i++) {
		temp_code[7+i]=archivio[count].autore[i];  //dalle prime due lettere dell'autore
	}
	char temp[2];
	sprintf(temp, "%d", count);                    //trasforma l'indicatore posizione del disco, intero, in una stringa
	
	for (i=0;i<2;i++) {
		temp_code[9+i]=temp[i];                    //la inserisce nel codice
	}
	strcpy(archivio[count].codice,temp_code);      //copia il codice temporaneo nello spazio codice della struct
	
}

void inserisci_disco (dischi *archivio, int *count) {
	
	//inserisce un nuovo disco nella libreria e aumenta il contatore di posizione generale
	printf("\nInserimento nuovo disco...\nInserisci il titolo: ");
	scanf(" %[^\n]",&archivio[*count].titolo);
	printf("Inserisci il nome dell'autore: ");
	scanf(" %[^\n]",&archivio[*count].autore);
	printf("Inserisci il prezzo del disco: ");
	scanf(" %d",&archivio[*count].prezzo);	
	archivio[*count].presente=1;
	genera_codice(*count,archivio); //chiamata di funzione che genera il codice in base ai dati appena inseriti
	*count=*count+1;
	printf("\nFatto!");
	
}

void stampa_elenco(dischi archivio[], int count) {
	//stampa l'elenco completo della libreria, mostra i file presenti e quelli non presenti
	printf("\nStampo elenco...");
	int i;
	for (i=0;i<count;i++) {
		printf("\n%d Disco:\nTitolo: %s\nAutore: %s",i+1,archivio[i].titolo,archivio[i].autore);
		printf("\nCodice: %s\nPrezzo: %d euro",archivio[i].codice,archivio[i].prezzo);
		if (archivio[i].presente==1) printf("\nPresente");
		else printf("\nNon Presente");
	}
	
	
}

void ricerca_autore (dischi archivio[], int count) {
	int i;
	int trovato=0;
	char nome[50];
	if (count==0) printf("\nNon e' presente alcun disco nella libreria, impossibile effettuare la ricerca!");
	else{
		
		printf("\nInserire autore da ricercare: ");
		scanf(" %[^\n]",nome);
	
	 	for(i=0;i<count;i++) {	
			
			if(strcmp(nome, archivio[i].autore) == 0) {    //esegue il confronto tra le due stringhe, se da come risultato 0 le due stringhe sono uguali
				trovato=1;
				printf("\n%d Disco:\nTitolo: %s\nAutore: %s",i+1,archivio[i].titolo,archivio[i].autore);
				printf("\nCodice: %s\nPrezzo: %d euro",archivio[i].codice,archivio[i].prezzo);			
				if (archivio[i].presente==1) printf("\nPresente");
				else printf("\nNon Presente");
			}
		}
		if (trovato==0) printf("\nMi dispiace, nessun disco trovato..");
	}
		
	
} 


int ricerca_prezzo(dischi archivio [],int primo,int ultimo) {
	//approccio divide et impera
	int max=0,max1=max;  //inizializzo il massimo, come primo elemento dell'array
	int mediano;
	if (ultimo<0)  {    //controllo che il vettore abbia almeno un elemento altrimenti ritorno un valore alert
			max=-1;	 
			return max;
	} 

		if (primo == ultimo) {      //caso banale, array di dimensione 1
	    	max=primo;				//il max è l'unico elemento presente
			
		}
	    else if (primo==ultimo-1) { //array di dimensione 2,effettuo il confronto dei due valori  
	    
			if (archivio[primo].prezzo>archivio[ultimo].prezzo) {  
				max=primo;			
			}
			else { 
				max=ultimo;
			}
	   }
	    else { 					 //nel caso in cui l'array sia formato da più di due valori, richiamo la function e continuo la divisione
	    	mediano = (primo + ultimo) / 2;     				//calcola il valore medio dell'array considerato
			max=ricerca_prezzo(archivio,primo, mediano);  		//effettua il divida et impera sulla prima metà dell'array 
		   	max1=ricerca_prezzo(archivio,mediano+1, ultimo);	//effettua il divida et impera sula seconda metà dell'array     
		    if(archivio[max].prezzo<archivio[max1].prezzo)		//effettua il confronto tra i valori trovati 
				max=max1;										//e seleziona l'indice di quello maggiore
			}
		return max;
	
}


void stampa_disco_costoso(dischi archivio[],int count) {
	
	int i=ricerca_prezzo(archivio,0,count-1);
	if (i==-1) printf("\nErrore! Non c'e' nessun disco!");  //se l'indice è -1 significa che non vi era alcun elemento!
	else {
		
		printf("\nIl disco piu' caro e': ");
		printf("\n%d Disco:\nTitolo: %s\nAutore: %s",i+1,archivio[i].titolo,archivio[i].autore);
		printf("\nCodice: %s\nPrezzo: %d euro",archivio[i].codice,archivio[i].prezzo);	
		if (archivio[i].presente==1) printf("\nPresente");
		else printf("\nNon Presente");	
	
	}

}






