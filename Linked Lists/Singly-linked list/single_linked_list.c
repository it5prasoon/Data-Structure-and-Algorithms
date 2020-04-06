#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void displaylinkedlist(struct node *s)
{
    while(s != NULL){
        printf("%d->",s->data);
        s=s->next;
    }

}


void main(){
    struct node* head=NULL;
    struct node* second=NULL;
    struct node* third=NULL;

    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;
    displaylinkedlist(head);
}








