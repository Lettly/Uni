#include <stdio.h>
#include <stdlib.h>

typedef struct punto
{
    int x;
    int y;
} punto;

typedef struct quadrato
{
    punto bassoSinistra;
    int lunghezzaLato;
} quadrato;

typedef struct lista
{
    quadrato quadrato;
    struct lista *pun;
} NODE;

void stampaQuadrati(NODE* HEAD) {
    if (HEAD == NULL)
    {
        printf("nonp");
        return;
    }
    while (HEAD != NULL)
    {
        printf("Lato: X:%d Y:%d, Lunghezza: %d\n", HEAD->quadrato.bassoSinistra.x, HEAD->quadrato.bassoSinistra.y, HEAD->quadrato.lunghezzaLato);
        HEAD = (NODE*) HEAD->pun;
    }
}

NODE* aggiungiQuadrato(NODE* HEAD, quadrato quadrato) {
    NODE* nuovoElm = (NODE *) malloc(sizeof(NODE));
    nuovoElm->quadrato = quadrato;
    nuovoElm->pun = NULL;
    if (HEAD == NULL)
    {
        HEAD = nuovoElm;
    } else {
        NODE* nodoCorrente = HEAD;
        while (nodoCorrente->pun != NULL)
        {
            nodoCorrente = nodoCorrente->pun;
        }
        nodoCorrente->pun = nuovoElm;
    } 
    return HEAD;
}

void rimuoviDuplicati(NODE* head) {
    int cancellati = 0;
    while (head!=NULL && head->pun!=NULL)
    {
        NODE* nodo = head;
        while (nodo->pun!=NULL)
        {
            if (head->quadrato.bassoSinistra.x == nodo->pun->quadrato.bassoSinistra.x && head->quadrato.bassoSinistra.y == nodo->pun->quadrato.bassoSinistra.y && head->quadrato.lunghezzaLato == nodo->pun->quadrato.lunghezzaLato)
            {
                NODE* daDeallocare = nodo->pun;
                nodo->pun = nodo->pun->pun;
                free(daDeallocare);
                cancellati = 1;
            } else {
                nodo=nodo->pun;
            }
        }
        head=head->pun;
    }
    if(cancellati)
		printf("Ho cancellato tutti gli elementi duplicati!\n\n");
	else
		printf("Non c'erano elementi duplicati!\n\n");
    
}

quadrato inserisciQuadrato() {
    quadrato quadrato1;
    printf("Inserisci x bassoSinistra:");
    scanf("%d", &quadrato1.bassoSinistra.x);
    printf("Inserisci y bassoSinistra:");
    scanf("%d", &quadrato1.bassoSinistra.y);
    printf("Inserisci LunghezzaLato:");
    scanf("%d", &quadrato1.lunghezzaLato);
    return(quadrato1);
}

int main() {
    NODE *HEAD = NULL;
    HEAD = aggiungiQuadrato(HEAD, inserisciQuadrato());
    HEAD = aggiungiQuadrato(HEAD, inserisciQuadrato());
    HEAD = aggiungiQuadrato(HEAD, (quadrato) {{2, 1}, 1});
    HEAD = aggiungiQuadrato(HEAD, (quadrato) {{2, 2}, 1});
    HEAD = aggiungiQuadrato(HEAD, (quadrato) {{1, 1}, 1});
    stampaQuadrati(HEAD);
    rimuoviDuplicati(HEAD);
    stampaQuadrati(HEAD);
    return 1;
}
