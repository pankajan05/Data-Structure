#include<stdio.h>
#include<stdlib.h>

typedef char datatype;
typedef enum {FALSE,TRUE} boolean;
typedef int position;

typedef struct node{
    datatype entry;
    struct node *next;
}Node;

typedef struct List{
    Node *head;
    int count;
    boolean Full;
}list;

void createList(list *l)
{
    l->head = NULL;
    l->count = 0;
    l->Full = FALSE;
}

boolean IsListFull(list *l)
{
        return (l->Full);
}

boolean IsListEmpty(list *l)
{
    if(l->count == 0)
        return TRUE;
    else
        return FALSE;
}

void inserttop(list *l, datatype Ele)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));

    if(newnode == NULL)
    {
        printf("Overflow.....");
        l->Full = TRUE;
        exit(1);
    }
   else
    {
        newnode->entry = Ele;

         if( l->head == NULL)
            newnode->next = NULL;
        else
            newnode->next = l->head;
        l->head = newnode;
        l->count++;
    }

}

void insertLast(list *l, datatype Ele)
{
     Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));

    if(newnode == NULL)
    {
        printf("Overflow.....");
        l->Full = TRUE;
        exit(1);
    }
    else
    {
        newnode->entry = Ele;
        newnode->next = NULL;
        
        if(l->head == NULL)
            l->head = newnode;
        else{
        Node *temp = l->head;
        
        while(temp->next != NULL)
            temp = temp->next;
        
        temp->next = newnode;
        }
        l->count++;
    }
}

void insert(list *l, datatype Ele, position p)
{
     Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));

    if(newnode == NULL)
    {
        printf("Overflow.....");
        l->Full = TRUE;
        exit(1);
    }
    else if(p > l->count || p<1)
    {
        printf("Sorry your position is not available.");
        exit(0);
    }
    else{
        newnode->entry = Ele;
        Node *temp;
        temp = l->head;
        int j = 1;
        while(j++ < p)
            temp = temp->next;
        
        newnode->next = temp->next;
        temp->next = newnode;
        l->count++;
        
    }
    
}


void removeLast(list *l, datatype *Ele)
{
    if(IsListEmpty(l))
    {
        printf("Underflow....");
        exit(1);
    }
    else
    {
        
        if(l->head->next == NULL)
        {
            *Ele = l->head->entry;
            l->head = NULL;
        }
        else{
        Node *temp;
        temp = l->head;
        while(temp->next->next != NULL)
            temp = temp->next;
        
        *Ele = temp->next->entry;
        temp->next = NULL;
        free(temp);
        }
        l->count--;
    }
}

void removeTop(list *l, datatype *Ele)
{
     if(IsListEmpty(l))
    {
        printf("Underflow....");
        exit(1);
    }
    else
    {
        *Ele = l->head->entry;
        l->head = l->head->next;
        l->count--;
       
    }
}

void delete(list *l, datatype *Ele, position p)
{
    if(IsListEmpty(l))
    {
        printf("list is Empty.");
        exit(0);
    }
   else if(p > l->count || p<1)
    {
        printf("Sorry your position is not available.");
        exit(0);
    }
   else{
       Node *temp = l->head;
       int i=1;
       while(i++<p)
           temp = temp->next;
       *Ele - temp->next->entry;
       temp->next = temp->next->next;
       l->count--;
   }
}

void traversal(list *l)
{
    if(IsListEmpty(l))
    {
        printf("Sorry list is empty.");
        exit(0);
    }
    else{
        Node *temp = l->head;
        while(temp->next != NULL){
            printf("%c\t",temp->entry);
            temp = temp->next;   
        }
        printf("%c\t",temp->entry);
        free(temp);
    }
}

int main()
{
    list l;
    char c;

    createList(&l);

    inserttop(&l,'p');
    inserttop(&l,'d');
    insertLast(&l,'k');
    insertLast(&l,'k');
    traversal(&l);
    
    
    puts("");
    
    
   removeTop(&l,&c);
    printf("%c\n",c);
    removeTop(&l,&c);
    printf("%c\n",c);
    removeTop(&l,&c);
    printf("%c\n",c);
    removeTop(&l,&c);
    printf("%c\n",c);
 
    return (EXIT_SUCCESS);
}