
/* 
 * File:   main.c
 * Author: Pankajan
 * Purpose: understand the list array implementation
 * Created on December 9, 2018, 10:07 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 30

typedef char datatype;
typedef enum{FALSE,TRUE} Boolean;
typedef int position;

typedef struct List{
    int count;
    datatype entry[MAXSIZE];
}list;

void createlist(list *l)
{
    l->count = 0;
}

Boolean isListEmpty(list *l)
{
    return l->count == 0;
}

Boolean isListFull(list *l)
{
    return l->count == MAXSIZE;
}

int listSize(list *l)
{
    return l->count;
}

void InsertLast(list *l, datatype x)
{
    if(isListFull(l))
    {
        printf("Sorry list is Full.");
        exit(0);
    }
    else
    {
        l->entry[l->count++] = x;
    }
}

void InsertList(list *l, datatype x, position p)
{
    int i;
    
    if(isListFull(l))
    {
        printf("Sorry list is Full.");
        exit(0);
    }
    else if(p<0 || p >= l->count)
    {
        printf("Sorry please Enter the correct position.");
        exit(0);
    }
    else{
        for(i = l->count-1; i>=p; i--)
            l->entry[i+1] = l->entry[i];
        l->entry[p] = x;
        l->count++;
    }
}

void replaceList(list *l, datatype x, position p)
{
    if(p<0 || p>MAXSIZE-1)
    {
        printf("Sorry please enter the correct position.");
        exit(0);
    }
    else
    {
        l->entry[p] = x;
    }
}

void deleteList(list *l, datatype *x, position p)
{
    int i;
    
    if(isListEmpty(l))
    {
        printf("Sorry list is Empty.");
        exit(0);
    }
    else if(p<0 || p >= l->count){
        printf("Please Enter the correct position.");
        exit(0);
    }
    else{
        *x = l->entry[p];
        for(i=p; i<l->count-1; i++)
            l->entry[i] = l->entry[i+1];
        l->count--;
    }
}

void retriveList(list *l, datatype *x, position p)
{
    if( p<0 || p >= l->count)
    {
        printf("Sorry the position is empty");
        exit(0);
    }
    else
    {
        *x = l->entry[p];
    }
}

int main(int argc, char** argv) {
    
    list l;
    int i;
    datatype c;
    
    createlist(&l);
    InsertLast(&l, 'k');
    InsertLast(&l, 'a');
    InsertLast(&l, 'a');
    InsertLast(&l, 'g');
    InsertLast(&l, 'a');
    InsertList(&l, 'j',2);
    deleteList(&l, &c, 5);
    replaceList(&l, 'n',4);
    
    printf("%d\n\n", l.count);
    
    for(i =0; i<l.count; i++){
        retriveList(&l, &c, i);
        printf("%c\t",c);
    
    }
    return (EXIT_SUCCESS);
}

