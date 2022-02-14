#include <stdio.h>


/* Specifica
INPUT: Una sequenza x1, ..., xn
PRECOND: I valori x1 ... xn Sono interi
OUTPUT: un valore booleano return 
POSTCOND: retrun true se per ogni 3 elementi adiacenti ne sono presenti almeno 2 compresi tra -9 e 9
*/ 
int dueSingolaCifra(int* array, int lunghezza) {
    int numeriCompresi;
    for (int i = 2; i < lunghezza; i++)
    {
        numeriCompresi = 0;
        for (int j = i-2; j <= i && numeriCompresi < 2 ; j++)
        {
            if (array[j] >= -9 && array[j] <= 9) {
                numeriCompresi++;
            }
        }
        if (numeriCompresi < 2)
        {
            return 0;
        }
    }
    return 1;
    
}

int main() {
    int lunghezza;			// lunghezza array

	/*INPUT*/
	printf("Benvenuto, questo programma ha a che fare con sequenze di numeri interi\n");
	printf("Inserisci il numero di elementi che compongono la sequenza: ");
	scanf("%d",&lunghezza);
	int sequenza[lunghezza];
    
    if (lunghezza < 3)
    {
        printf("La lunghezza e' inferiore a 3");
        return 1;
    }
    

	for (int i=0; i<lunghezza;i++)	{
		printf("Inserisci un elemento: ");
		scanf("%d",&sequenza[i]);
	}

	/* OUTPUT */

	if(dueSingolaCifra(sequenza,lunghezza))
		printf("Ogni 3 interi consecutivi ne contengono due ad una cifra\n");
	else
		printf("Non ogni 3 interi consecutivi ne contengono due ad una cifra\n");
    return 1;
}