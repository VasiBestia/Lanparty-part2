#pragma once
#include "fisiere.h/cozit2.h"
#include "fisiere.h/grafurit2.h"
#include <math.h>
#define Teams_Number 32
#define Prestige_factor 0.15
#define Num_of_wins 6

int main()
{
    FILE *file = fopen("test1.in", "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    Queue *q = createQueue();
    for (int i = 0; i < 32; i++)
    {
        char team_name[50];
        float points;
        fscanf(file, "%f %[^\n]", &points, team_name);
        enqueue(q, team_name, points);
    }

    Graph *g = createGraph();
    Node *aux = q->front;
    for (int i = 0; i < 32; i++)
    {
        addNode(g, i, aux->team_name);
        aux = aux->next;
    }

    int kickoff = 32;
    while (kickoff > 1)
    {
        runde(q, g);
        kickoff /= 2;
    }

    FILE *iesire = fopen("rezultate.txt", "w");

    if (iesire == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    printGraph(g, iesire);

    Nod *temp = g->head;
    while (temp != NULL)
    {
        temp->score = (Prestige_factor*pow(2-Prestige_factor,temp->victorii))/((1<<Num_of_wins)+pow(2-Prestige_factor,Num_of_wins)*(Prestige_factor-1));
        temp = temp->next;
    }

    sortQueue(g);
    temp = g->head;
    while (temp != NULL)
    {
        printf("%.4f %s\n", temp->score, temp->team_name);
        temp = temp->next;
    }

    fclose(iesire);
    fclose(file);
}