#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cozit2.h"
#include "grafurit2.h"

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

Node *createNode(char *team_name, float points)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->team_name = (char *)malloc(50 * sizeof(char));
    strcpy(newNode->team_name, team_name);
    newNode->points = points;
    newNode->next = NULL;
    return newNode;
}

int IsEmpty(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, char *team_name, float points)
{
    Node *newNode = createNode(team_name, points);
    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void printQueue(Queue *q)
{
    Node *temp = q->front;
    while (temp != NULL)
    {
        printf("%.2f %s\n", temp->points, temp->team_name);
        temp = temp->next;
    }
}

void freeQueue(Queue *q)
{
    Node *temp = q->front;
    while (temp != NULL)
    {
        Node *aux = temp;
        temp = temp->next;
        free(aux->team_name);
        free(aux);
    }
    free(q);
}

void deleteNode(Queue *q, float value)
{
    if (q->front == NULL)
    {
        printf("Coada este goală.\n");
        return;
    }

    Node *temp = q->front, *prev = NULL;

    // Dacă nodul de șters este primul nod
    if (temp != NULL && temp->points == value)
    {
        q->front = temp->next;
        if (q->front == NULL)
        { // Dacă coada devine goală
            q->rear = NULL;
        }
        free(temp);
        return;
    }

    // Caută nodul de șters
    while (temp != NULL && temp->points != value)
    {
        prev = temp;
        temp = temp->next;
    }

    // Dacă nodul nu a fost găsit
    if (temp == NULL)
    {
        printf("Nodul cu valoarea %d nu a fost găsit.\n", value);
        return;
    }

    // Deconectează nodul din listă
    prev->next = temp->next;

    // Dacă nodul șters era ultimul nod
    if (temp == q->rear)
    {
        q->rear = prev;
    }

    free(temp->team_name);
    free(temp);
}

int findNodeQueue(char *team_name, Queue *q)
{
    Node *temp = q->front;
    while (temp != NULL)
    {
        if (strcmp(temp->team_name, team_name) == 0)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void runde(Queue *q, Graph *g)
{
    Queue *winners = createQueue();
    Queue *losers = createQueue();

    Node *temp = q->front;
    int winnerposition = -1;
    int losersposition = -1;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->points > temp->next->points)
        {
            enqueue(winners, temp->team_name, temp->points);
            winnerposition = findNode(temp->team_name, g);

            enqueue(losers, temp->next->team_name, temp->next->points);
            losersposition = findNode(temp->next->team_name, g);

            g->a[losersposition][winnerposition] = 1;
        }
        else if (temp->points < temp->next->points)
        {
            enqueue(winners, temp->next->team_name, temp->next->points);
            winnerposition = findNode(temp->next->team_name, g);

            enqueue(losers, temp->team_name, temp->points);
            losersposition = findNode(temp->team_name, g);

            g->a[losersposition][winnerposition] = 1;
        }
        else if (temp->points == temp->next->points)
        {
            if (strcmp(temp->team_name, temp->next->team_name) < 0)
            {
                enqueue(losers, temp->team_name, temp->points);
                losersposition = findNode(temp->team_name, g);

                enqueue(winners, temp->next->team_name, temp->next->points);
                winnerposition = findNode(temp->next->team_name, g);

                g->a[losersposition][winnerposition] = 1;
            }
            else
            {
                enqueue(losers, temp->next->team_name, temp->next->points);
                losersposition = findNode(temp->next->team_name, g);

                enqueue(winners, temp->team_name, temp->points);
                winnerposition = findNode(temp->team_name, g);

                g->a[losersposition][winnerposition] = 1;
            }
        }
        temp = temp->next->next;
    }
    printf("\nwinners:\n");
    printQueue(winners);
    printf("\nlosers:\n");
    printQueue(losers);

    temp = losers->front;
    while (temp != NULL)
    {
        deleteNode(q, temp->points);
        temp = temp->next;
    }
    temp = winners->front;
    while (temp != NULL)
    {
        if (findNodeQueue(temp->team_name, q) == 1)
        {
            Nod *aux = g->head;
            while (aux != NULL)
            {
                if (strcmp(aux->team_name, temp->team_name) == 0)
                {
                    aux->victorii++;
                }
                aux = aux->next;
            }
        }
        temp = temp->next;
    }

    freeQueue(winners);
    freeQueue(losers);
}
int IsEmptyGraph(Graph *q)
{
    return q->head == NULL;
}

void sortQueue(Graph *g)
{
    Nod *current = g->head;
    Nod *index = NULL;
    char *temp_team_name;
    float temp_summary;
    int temp_position;

    if (IsEmptyGraph(g))
    {
        printf("Graful este gol.\n");
        return;
    }
    else
    {
        while (current != NULL)
        {
            index = current->next;

            while (index != NULL)
            {
                if (current->score > index->score)
                {
                    // Swap team names
                    temp_team_name = current->team_name;
                    current->team_name = index->team_name;
                    index->team_name = temp_team_name;

                    // Swap summaries
                    temp_summary = current->score;
                    current->score = index->score;
                    index->score = temp_summary;

                    temp_position = current->position;
                    current->position = index->position;
                    index->position = temp_position;
                }
                else if(current->score==index->score)
                {
                    if(current->position>index->position)
                    {
                        // Swap team names
                        temp_team_name = current->team_name;
                        current->team_name = index->team_name;
                        index->team_name = temp_team_name;

                        // Swap summaries
                        temp_summary = current->score;
                        current->score = index->score;
                        index->score = temp_summary;

                        temp_position = current->position;
                    current->position = index->position;
                    index->position = temp_position;
                    }
                }

                index = index->next;
            }

            current = current->next;
        }
    }
}
    