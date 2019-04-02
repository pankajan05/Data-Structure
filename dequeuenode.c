#include<stdio.h>
#include<stdlib.h>

typedef char dequeueEle;
typedef enum {TRUE,FALSE} boolean;

typedef struct node{
    dequeueEle entry;
    struct node *pre,*next;
}Node;

typedef struct dequeue{
    Node *front,*rear;
    int count;
    boolean Full;
}Dequeue;

void createDequeue(Dequeue *d)
{
    d->front = d->rear = NULL;
    d->count = 0;
    d->Full = FALSE;
}

boolean IsDequeueFull(Dequeue *d)
{
        return (d->Full);
}

boolean IsDequeueEmpty(Dequeue *d)
{
    if(d->count == 0)
        return TRUE;
    else
        return FALSE;
}

void insertFront(Dequeue *d, dequeueEle Ele)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));

    if(newnode == NULL)
    {
        printf("Overflow.....");
        d->Full = TRUE;
        exit(1);
    }
   else
    {
        newnode->entry = Ele;

         if( d->front == NULL)
            d->rear = d->front = newnode;
        else{
            newnode->next = d->front;
            d->front->pre = newnode;
            d->front = newnode;
            d->front->pre = NULL;
        }

    }

}

void insertRear(Dequeue *d, dequeueEle Ele)
{
     Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));

    if(newnode == NULL)
    {
        printf("Overflow.....");
        d->Full = TRUE;
        exit(1);
    }
    else
    {
        newnode->entry = Ele;

        if( d->rear == NULL)
            d->rear = d->front = newnode;
        else{
            newnode->pre = d->rear;
            d->rear->next = newnode;
            d->rear = newnode;
            d->rear->next = NULL;
        }

    }


}

void removeRear(Dequeue *d, dequeueEle *Ele)
{
    if(IsDequeueEmpty(d))
    {
        printf("Underflow....");
        exit(1);
    }
    else
    {
        Node *temp;
        temp=(Node *)malloc(sizeof(Node));
        temp = d->rear;

        d->rear = d->rear->pre;

        if(d->rear == NULL)
            d->front = NULL;
        else
        {
            d->rear->next = NULL;
        }
        *Ele = temp->entry;
        free(temp);
    }
}

void removeFront(Dequeue *d, dequeueEle *Ele)
{
     if(IsDequeueEmpty(d))
    {
        printf("Underflow....");
        exit(1);
    }
    else
    {
        Node *temp;
        temp = d->front;

        d->front = d->front->next;

        if(d->front == NULL)
            d->rear = NULL;
        else
        {
            d->front->pre = NULL;
        }

        *Ele = temp->entry;
        free(temp);
    }
}


int main()
{
    Dequeue d;
    char c;

    createDequeue(&d);

    insertFront(&d,'p');
    insertFront(&d,'d');
    insertFront(&d,'k');
    insertRear(&d,'k');
    removeFront(&d,&c);
    printf("%c\n",c);
    removeRear(&d,&c);
    printf("%c\n",c);
    removeRear(&d,&c);
    printf("%c\n",c);
    removeRear(&d,&c);
    printf("%c\n",c);
    
    return EXIT_SUCCESS;
}
