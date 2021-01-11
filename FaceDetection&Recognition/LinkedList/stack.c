#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <process.h>

struct node
{
    int info;
    struct node *link;
};
struct node *start = NULL;

void push(int data)
{
    struct node *q, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
        return;
    }
    else
    {
        q = start;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = temp;
    }
}
void pop(){
    if(start==NULL){
        printf("\nSTACK UNDERFLOW\n");
        return ;
    }
    else if(start->link==NULL){
        struct node *temp;
        temp=start;
        start=NULL;
        free(temp);
    }
    else{
    struct node* temp,*q;
    temp=start;
    while(temp->link->link!=NULL){
        temp=temp->link;
    }
        q=temp->link;
        temp->link=NULL;
        free(q->link);
    }
}
void peek(){
    struct node *temp;
    temp=start;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    printf("\nPEEK  %d \n",temp->info);
}

void display()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = start;
        while (temp != NULL)
        {
            printf(" %d ", temp->info);
            temp = temp->link;
        }
    }
}
void stackForm(struct node *temp)
{
    if (temp == NULL)
        return;
    stackForm(temp->link);
    printf("%d\n", temp->info);
}
int main(){
    int flag=1;
    while(flag){
        printf("1)PUSH\n");
        printf("2)POP\n");
        printf("3)PEEK\n");
        printf("4)STACK DISPLAY\n");
        printf("5)EXIT\n");
      

        int choice;
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d", &choice);
    switch(choice){
        case 1:
        printf("\nENTER DATA ->\n") ;
        int data;
        scanf("%d", &data);
        push(data);
        break;

        case 2:
        pop();
        break;

        case 3:
        peek();
        break;

        case 4:
        stackForm(start);
        break;

        case 5:
        flag=0;
        break;


        default:
        printf(" INVALID OPTION TRY AGAIN ");
       
        break;

    }


    }
  

}
