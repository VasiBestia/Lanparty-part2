#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafurit2.h"

Nod *creeazaNodul()
{
    Nod *newNode = (Nod *)malloc(sizeof(Nod));

    newNode->team_name = (char *)malloc(50 * sizeof(char));

    newNode->next = NULL;
    return newNode;
}

Graph *createGraph()
{
    Graph *g = (Graph *)malloc(sizeof(Graph));

    g->head = NULL;
    g->a = (int **)malloc(32 * sizeof(int *));

    for (int i = 0; i < 32; i++)
    {
        g->a[i] = (int *)malloc(32 * sizeof(int));
        for (int j = 0; j < 32; j++)
        {
            g->a[i][j] = 0;
        }
    }
    return g;
}

void addNode(Graph *g, int position, char *team_name)
{
    Nod *newNode = creeazaNodul();
    strcpy(newNode->team_name, team_name);
    newNode->score = 0;
    newNode->position = position;
    newNode->victorii = 0;
    if (g->head == NULL)
    {
        g->head = newNode;
    }
    else
    {
        Nod *temp = g->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int isEMPTY(Graph *g)
{
    return g->head == NULL;
}

void printGraph(Graph *g, FILE *iesire)
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            fprintf(iesire, "%d ", g->a[i][j]);
        }
        fprintf(iesire, "\n");
    }
}

int findNode(char *team_name, Graph *g)
{
    Nod *temp = g->head;
    while (temp != NULL)
    {
        if (strcmp(temp->team_name, team_name) == 0)
        {
            return temp->position;
        }
        temp = temp->next;
    }
    return -1;
}
