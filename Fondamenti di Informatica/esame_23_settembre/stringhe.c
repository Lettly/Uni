#include <stdio.h>
#include <string.h>

void nascondiNumeri(char* stringa) {
    for (int i = 0; stringa[i]!='\0'; i++)
    {
        if (stringa[i] >= '0' && stringa[i] <= '9')
        {
            stringa[i] = '#';
            if (i > 0 && stringa[i] == stringa[i-1])
            {
                for (int j = i; stringa[j]; j++)
                {
                    stringa[j] = stringa[j+1];
                }
                i--;
            }
        }
        
    }  
}

int main() {
    int scelta;
    char stringa[50];
    FILE* fp;
    printf("Vuoi inserire la stringa[0/1]: ");
    scanf("%d%*c", &scelta);
    if (scelta)
    {
        printf("Inserisci la stringa: ");
        fgets(stringa, 50, stdin);
        stringa[strlen(stringa)-1] = '\0';
        nascondiNumeri(stringa);
        printf("\n%s", stringa);
        //Save to file
        fp = fopen("stringhe.txt", "w");
        if (fp==NULL)
        {
            printf("Errore nell'apertura del file");
        } else {
            fprintf(fp, "%s", stringa);
            fclose(fp);
        }        
    } else {
        fp = fopen("stringhe.txt", "r");
        if (fgets(stringa, 50, fp) == NULL)
        {
            printf("Il file è vuoto");
        } else {
            nascondiNumeri(stringa);
            printf("\n%s", stringa);
        }
        fclose(fp);
    }
    
    printf("\n");
}