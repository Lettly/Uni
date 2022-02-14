#include <stdio.h>

void treSoloSeConti (char* string) {
    int removed = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '3') {
            if ( i < 2 || (string[i-1] != '2' && string[i-2] != '1')) {
                for (int j = i; string[j] != '\0'; j++)
                {
                    string[j] = string[j+1];
                }
                i--;
            } 
        }
    }
}
int main() {
    char string[50];
    int insStringa;
    FILE* fp;
    printf("Vuoi inserire una stringa[0/1]? ");
    scanf("%d", &insStringa);

    if (insStringa == 1)
    {
        printf("Inserisci la tua stringa: ");
        scanf("%s", string);
        printf("Ho recuperato la tua stringa: %s\n", string);
        treSoloSeConti(string);
        printf("La tua stringa modificata: %s\n", string);
    } else {
        //Non voglio inserire una stringa
        fp = fopen("stringhe.txt", "r");
        if (fp==NULL) {
            printf("Non sono riuscito ad apreire il file\n");
        } else {
            if (fscanf(fp, "%s", string) == EOF)
            {
                printf("Non ci sono stringhe all'interno del file\n");
            } else {
                printf("Ho recuperato la tua stringa: %s\n", string);
                treSoloSeConti(string);
                printf("La tua stringa modificata: %s\n", string);
            }
        }
    }
    
    return 1;
}