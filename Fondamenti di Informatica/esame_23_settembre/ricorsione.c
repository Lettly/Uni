#include <stdio.h>

//Input: valori x1 ... xn
//Precondizione: xn valori interi 
//Output: Booleano return
//Postcondizione: Ritora 1 se per ogni tre elementi all'interno dell'array la somma e la addizione risulta divisibile per 3
int TreDivisibiliTre(int *array, int lunghezza) {
    //Somma divisibile by 3
    //Prodotto divisibile by 3
    int somma = array[lunghezza-1] + array[lunghezza-2] + array[lunghezza-3];
    int prodotto = array[lunghezza-1] * array[lunghezza-2] * array[lunghezza-3];

    if (somma % 3 == 0 && prodotto % 3 == 0)
    {
        if (lunghezza > 3) {
            if(TreDivisibiliTre(array, lunghezza-1)){
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int main() {
    int lunghezza;
    printf("Lunghezza array: ");
    scanf("%d", &lunghezza);
    int array[lunghezza];
    for (int i = 0; i < lunghezza; i++)
    {
        printf("Inserisci l'%d valore: ", i);
        scanf("%d", &array[i]);
    }
    
    printf("La divisibilita' e' %d\n", TreDivisibiliTre(array, lunghezza));
}