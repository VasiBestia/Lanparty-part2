#ifndef GRAFURIT2_H
#define GRAFURIT2_H
#include <stdio.h>

typedef struct Nod
{
    int position;
    char *team_name;
    float score;
    int victorii;
    struct Nod *next;
} Nod;

typedef struct Graph
{
    Nod *head;
    int **a;
} Graph;

Nod *creeazaNodul();
Graph *createGraph();
int isEMPTY(Graph *g);
int findNode(char *team_name, Graph *g);
void addNode(Graph *g, int position, char *team_name);
void printGraph(Graph *g, FILE *iesire);

#endif