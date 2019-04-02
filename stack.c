#include<stdio.h>

#define MAXSIZE 50

typedef char StackEntryType;
typedef enum{FALSE,TRUE} boolean;

typedef struct{
int top;
StackEntryType entry[MAXSIZE];
}stack;

void createStack(stack *s)
{
    s->top = -1;
}

boolean IsStackEmpty(const stack *s)
{
    return(s->top == -1);
}

boolean IsStackFull(const stack *s)
{
    return(s->top == MAXSIZE - 1);
}

void push(StackEntryType item, stack *s)
{
    if(IsStackFull(&s))
       {
         printf("Stack is full.\n");
         exit(1);
       }
    s->entry[++s->top] = item;

}

void pop(StackEntryType *item, stack *s)
{
    if(IsStackEmpty(&s))
    {
        printf("Stack is Empty.\n");
    }
    *item = s->entry[s->top--];
}


void main()
{
stack s;
char *c;
int i;
char str[50] = "This is an sample test";

createStack(&s);

printf("The test inserted to the stack : %s\n\n",str);

for(i=0; str[i] != '\0'; i++)
{
    if(!IsStackFull(&s))
  push(str[i],&s);
}


printf("The stack out put is: ");

for(; !IsStackEmpty(&s) ;)
{
  pop(&c, &s);
  putchar(c);
}

}
