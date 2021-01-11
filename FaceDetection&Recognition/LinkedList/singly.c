#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <process.h>

struct node{
    int info;
    struct node *link;
};
struct node *start=NULL;
void createList(int data){
    struct node *q,*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(start==NULL){
        start=temp;
    return ;
    }
    else{
        q=start;
        while(q->link!=NULL){
            q=q->link;
        }
        q->link=temp;
    }
}
void addBegin(int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start=temp;
}

void display(){
    struct node *temp;
    if(start==NULL){
            printf("List is empty");
        }
    else
    {
        temp = start;
        while (temp!= NULL)
        {
            printf(" %d ", temp->info);
            temp = temp->link;
        }
    }
}
void delete(int data){
    struct node *temp,*trav;
    if(start->info==data){
        temp=start;
        start=start->link;
        free(temp);
        return;
    }
    else{
        trav=start;
        while(trav->link->link!=NULL){

            if(trav->link->info==data){
                temp=trav->link;
                trav->link=temp->link;
                free(temp);
                return;
            }
            trav=trav->link;
        }
        if(trav->link->info==data){
            temp=trav->link;
            trav->link=NULL;
            free(temp);
            return ;
        }
        }
    }

void reverseLinkedList(struct node *temp){
    if(temp==NULL)
    return;
    reverseLinkedList(temp->link);
    printf("%d ",temp->info);
}

void reverse(){
        struct node *current,*next,*prev;
        // next=current->link;
        prev=NULL;
        current=start;
        while(current!=NULL){
            next=current->link;
            current->link=prev;
            prev=current;
            current=next;
            }
        start=prev;
}


void reverseALink(){
    struct node *curr,*nex,*prev;
    prev=NULL;
    curr=start;
    while(curr!=NULL)
    {
        nex=curr->link;
        curr->link = prev; //NULL
        prev=curr;
        curr =nex;  
    }
    start=prev;
    }
int main(){
   createList(10);
   createList(21);
   createList(31);
   createList(67);
   display();
   reverseALink();
   display();
   return 0;
}