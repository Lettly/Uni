#include <stdio.h>
#include <stdlib.h>

typedef struct durata {
    int ore;
    int minuti;
    int secondi;
} D;

typedef struct video
{
    D durata;
    char titolo[50];
} V;

typedef struct node
{
    V video;
    struct node* next;
} node;


node* inserisciNodo(node* head, V video) {
    node* nuovoVideo = malloc(sizeof(node));
    nuovoVideo->video = video;
    nuovoVideo->next = NULL;
    if (head == NULL)
    {
        head = nuovoVideo;
        return head;
    }

    node* pointer = head;
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }
    pointer->next = nuovoVideo;
    return head;
    
}

void stampaTutto(node* head) {
    if (head != NULL)
    {
        while (head != NULL)
        {
            printf("Titolo: %s | Durata: %d:%d:%d\n", head->video.titolo, head->video.durata.ore, head->video.durata.minuti, head->video.durata.secondi);
            head = head->next;
        }
    } else {
        printf("Non sono presenti video\n");
    } 
}

node* cancellaIlVideoLungo(node* head) {
    node* beforeVideoMax = head;
    node* videoMax = head;
    node* pointer = head;
    while (pointer->next != NULL)
    {
        if (pointer->next->video.durata.ore > videoMax->video.durata.ore || (pointer->next->video.durata.ore >= videoMax->video.durata.ore && pointer->next->video.durata.minuti > videoMax->video.durata.minuti) || (pointer->next->video.durata.ore >= videoMax->video.durata.ore && pointer->next->video.durata.minuti >= videoMax->video.durata.minuti &&pointer->next->video.durata.secondi > videoMax->video.durata.secondi))
        {
            beforeVideoMax = pointer;
            videoMax = pointer->next;
        }
        pointer = pointer->next;
    }
    if (beforeVideoMax == videoMax)
    {
        //Rimovere il primo della lista
        head = videoMax->next;
    } else {
        //Rimovere il videomax
        beforeVideoMax->next = videoMax->next;
    }
    return head;
}

V aggiungiVideo() {
    V video;
    printf("Titolo: ");
    fgets(video.titolo, 50, stdin);
    printf("H: ");
    scanf("%d", &video.durata.ore);
    printf("m: ");
    scanf("%d", &video.durata.minuti);
    printf("s: ");
    scanf("%d", &video.durata.secondi);
    return video;
}

int main() {
    node *head = NULL;
    int nVideo;
    printf("Quanti video?");
    scanf("%d%*c", &nVideo);
    for (int i = 0; i < nVideo; i++)
    {
        printf("%d Video -------\n", i+1);
        head = inserisciNodo(head, aggiungiVideo());
    }
    
    // head = inserisciNodo(head, (V) {{1,1,1}, "Video Lungo"});
    // head = inserisciNodo(head, (V) {{1,2,3}, "Ciao Modo0"});
    // head = inserisciNodo(head, (V) {{1,2,4}, "Ciao Modo2"});
    // head = inserisciNodo(head, (V) {{1,2,5}, "Ciao Modo3"});
    head = cancellaIlVideoLungo(head);
    stampaTutto(head);
}