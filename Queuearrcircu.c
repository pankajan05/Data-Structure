#include<stdio.h>

#define MAXQUEUE 20
#define TRUE 1
#define FALSE 0

typedef char QueueElement;

typedef struct Queue{
int count;
int front;
int rear;
QueueElement item[MAXQUEUE];
}queue;

void createQueue(queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = -1;
}

int IsQueueEmpty(queue *q)
{
    if(q->count == 0)
        return (TRUE);
    else
        return (FALSE);
}

int IsQueueFull(queue *q)
{
    if(q->count == MAXQUEUE-1)
        return (TRUE);
    else
        return (FALSE);
}



void Insert(queue *q, QueueElement ele)
{
    if(IsQueueFull(q))
    {
        printf("Queue is Full.\n");
        exit(1);
    }
    q->rear = (++q->rear) % MAXQUEUE;
    q->item[(q->rear)] = ele;

    q->count++;
}

int QueueSize(queue *q)
{
    return (q->count);
}

void Remove(queue *q, QueueElement *ele)
{
    if(IsQueueEmpty(q))
    {
        printf("Queue is Empty.\n");
        exit(1);
    }
    *ele = q->item[(q->front)];
    q->front = (++q->front)%MAXQUEUE;
    q->count--;
}

void main()
{
    QueueElement x[] = "I am a legend.";
    QueueElement c;
    queue q;
    int a;

    createQueue(&q);

    for( a=0; x[a] != '\0'; a++)
        Insert(&q, x[a]);

    while(!IsQueueEmpty(&q))
    {
        Remove(&q, &c);
        putchar(c);

    }

    puts("");

    QueueElement y[]="Kill the people who";
    for( a=0; y[a] != '\0'; a++)
        Insert(&q, y[a]);

     while(!IsQueueEmpty(&q))
    {
        Remove(&q, &c);
        putchar(c);

    }


}
