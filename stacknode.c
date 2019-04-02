#include<stdio.h>


typedef char datatype;
typedef enum {FALSE, TRUE} boolean;

typedef struct Node{
    datatype data;
    struct node *next;
}node;

typedef struct Stack{
    node *top;
    int count;
}stack;

void createStack(stack *s)
{
    s->top = NULL;
    s->count = 0;
}

boolean IsStackEmpty( stack *s)
{
    return (s->top == NULL);
}


void push( stack *s, datatype item)
{
    node *np;
    np = (node *) malloc (sizeof (node));
    np->data = item;
    np->next = s->top;
    s->top = np;
    s->count++;
}

void pop(stack *s, datatype *item)
{
    node *np;
    *item = (s->top)->data;
    np = s->top;
    s->top = np->next;
    s->count--;
    free(np);
}

void main()
{
char a;
char name[]= ("Pankajan");
stack s;
int i;
createStack(&s);

for( i=0; name[i] != '\0'; i++)
    push(&s, name[i]);

    printf("The stack is: ");

    while(!IsStackEmpty(&s))
    {
        pop(&s, &a);
        putchar(a);
    }

}
