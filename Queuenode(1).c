#include<stdio.h>
#include<stdlib.h>

typedef char QueueElement;
typedef enum{FALSE,TRUE} boolean;

typedef struct Node{
QueueElement entry;
struct node *next;
}node;

typedef struct Queue{
int count;
boolean full;
node *front;
node *rear;
}queue;

void createQueue(queue *q)
{
    q->count = 0;
    q->full = FALSE;
    q->front = q->rear = NULL;

}

boolean IsQueueEmpty(queue *q)
{
    return (q->front == NULL && q->rear == NULL);
}

boolean IsQueueFull(queue *q)
{
    return (q->full);
}

void Insert(QueueElement ele, queue *q)
{
    node *np;
    np = (node *) malloc(sizeof(node));
    if(np==NULL)
    {
        printf("Not enough memory.\n");
        q->full = TRUE;
    }
    else
    {
        np->entry = ele;
        np->next = NULL;
        if(IsQueueEmpty((q)))
            q->front = q->rear = np;
        else
        {
            q->rear->next = np;
            q->rear = np;
        }
        q->count++;
    }
}

void Remove(QueueElement *ele, queue *q)
{
    node *np;
    if(IsQueueEmpty(q))
        printf("cann't remove from the empty queue...\n");
    else
    {
        q->count--;
        *ele = q->front ->entry;
        np = q->front;
        q->front = q->front->next;
        if(q->front == NULL)
            q->rear=NULL;
        free(np);
    }
}

void main()
{
    QueueElement x[] = "I am a legend. I like to kill the bad people. I like to be a villan.";
    QueueElement c;
    queue q;
    int a;

    createQueue(&q);


    for( a=0; x[a] != '\0'; a++)
        Insert(x[a], &q );

    while(!IsQueueEmpty(&q))
    {
        Remove( &c, &q);
        putchar(c);

    }

}
