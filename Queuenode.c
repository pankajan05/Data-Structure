#include<stdio.h>

typedef char QueueElement;
typedef enum {TRUE, FALSE} Boolean;

typedef struct node {
QueueElement entry;
struct node *next;
}Node;

typedef struct{
int count;
Boolean full;
Node *front;
Node *rear;
}Queue;

void createQueue (Queue *q)
{
    q->count = 0;
    q->front = q->rear = NULL;
    Boolean full = FALSE;
}

Boolean IsQueueEmpty(Queue *q)
{
    return q->count == 0;
}

Boolean IsQueueFull(Queue *q)
{
    return q->full;
}

void insert(Queue *q, QueueElement ele)
{
    Node *np;
    np = (Node *) malloc(sizeof(Node));
    if(np == NULL)
    {
        printf("Not enough memory....");
        q->full = TRUE;
        exit(1);
    }
    else
    {
        np->entry = ele;
        np->next = NULL;
        if(IsQueueEmpty(q))
            q->front = q->rear = np;
        else
        {
            q->rear->next = np;
            q->rear = np;
        }
      q->count++;
    }
}

void Remove(QueueElement *ele, Queue *q)
{
    Node *np;
    if( IsQueueEmpty(q))
    {
        printf("can not remove from the empty queue...");
        exit(1);
    }
    else
    {
        q->count--;
        *ele = q->front->entry;
        np = q->front;
        q->front = q->front->next;
        if( q->front == NULL)
            q->rear = NULL;
        free(np);
    }
}


void main()
{
int x;
char str[] = "kajan is the legend.",c;
Queue q;

createQueue(&q);

for(x=0; str[x] != '\0'; x++)
{
    insert(&q, str[x]);
}

printf("This is the text from the Queue: ");

while(!IsQueueEmpty(&q))
{
    Remove(&c, &q);
    putchar(c);
}
}
