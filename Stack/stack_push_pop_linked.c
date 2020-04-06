#include<stdio.h>
#include<stdlib.h>

void push();
int pop();
int peek();
void display();

struct node{
    int data;
    struct node *next;
}*head;

void push(){
    int n;
    scanf("%d",&n);
    head= (struct node*)malloc(sizeof(struct node));
    struct node* temp, *newnode;
    newnode= (struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp!=NULL){
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        temp=temp->next;
    }

}
void pop(){
    struct node* temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    free(temp);
}

void peek(){
    struct node* temp;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("%d",temp->data);
}


int main(){



return 0;
}