#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <process.h>

struct node{
    int data;
    struct node *link;
} *data;

int main(){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=18;
    temp->link=NULL;

    return 0;
}