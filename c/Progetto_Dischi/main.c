#include "dischi.h"
/*
Si vuole simulare la gestione automatizzata di un archivio di dischi musicali.
Si suppone di avere un archivio di massimo 100 dischi identificati dal titolo, 
nome dell’autore o gruppo, da un codice identificativo e dal prezzo di prestito. 
Un disco può essere presente o in prestito. Permettere all’utente di:
Inserire un nuovo disco nell’archivio (automaticamente gli viene assegnato un codice).
Visualizzare tutti i dischi di uno stesso autore o gruppo. 
Cercare nell’archivio il disco più costoso (usare un approccio divide-et impera ricorsivo) 
*/
int main () {
	//inizializzo un archivio di tipo dischi (struct) formato da 100 elementi
	dischi archivio[100];
	//variabile opzione per il funzionamento dello switch..case
	int opzione;
	//contatore per il riempimento della struct
	int count=0;
	//variabile intera usata falso booleano per l'uscita dal do..while
	int i=0;
	//int test[9]={10,24,3,30,5,9,1,8,10}; test rapido per la ricerca del massimo
	
	//menu di selezione operazione, ripete il ciclo fin quando non viene inserito il valore esci
	printf("\nBenvenuto nel negozio musicale\nChe operazione vuoi effettuare?");
	do{
		printf("\n\n1)Inserisci Disco\n2)Cerca Per Autore\n3)Cerca Piu' costoso\n4)Stampa Elenco Completo\n5)Esci");
		printf("\n\nScelta: ");
		scanf(" %d",&opzione);
		switch (opzione) {
	    	case 1:
	    		inserisci_disco(archivio,&count);
	      		break;
	
	   		 case 2:
	   			ricerca_autore(archivio,count);
	     	 	break;
			
			case 3:
				stampa_disco_costoso(archivio,count);
				break;  	
			case 4:
				stampa_elenco(archivio,count);
				printf("\n\n");
				break;
			case 5:
				printf("\nAlla prossima!");
				i=1;	
				break;
		}
	}while(i!=1);
	return 0;
}
