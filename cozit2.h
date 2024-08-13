#ifndef COZIT2_H
#define COZIT2_H
#include "grafurit2.h"

typedef struct Node
{
    float points;
    char *team_name;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue();
Node *createNode(char *team_name, float points);
void enqueue(Queue *q, char *team_name, float points);
void printQueue(Queue *q);
void freeQueue(Queue *q);
int IsEmpty(Queue *q);
void runde(Queue *q, Graph *g);
void deleteNode(Queue *q, float value);
int findNodeQueue(char *team_name, Queue *q);

#endif