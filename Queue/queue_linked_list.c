#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct list{
    int data;
    struct list *next;
};
struct queue{
    struct list *front;
    struct list *rear;
};

struct queue *create()
{
    struct queue *q;
    struct list *temp;
    q=malloc(sizeof(struct queue));
    if(!q)
        return NULL;
    temp=malloc(sizeof(struct list));
    q->front=q->rear=NULL;
    return q;
};

int size(struct queue *q){
    struct list *temp=q->front;
    int count=0;
    if(q->front==NULL &&q->rear==NULL)
        return 0;
    while(temp!=q->rear){
        count++;
        temp=temp->next;
    }
    if(temp==q->rear)
        count++;
    return count; 
}
int frontele(struct queue *q){
    return (q->front->data);
}
int rearele(struct queue *q){
    return q->rear->data;
}
void isempty(struct queue *q){
    if(q->front==NULL && q->rear==NULL)
        printf("Empty\n");
    else
        printf("NOT Empty\n");       
}
void enqueue(struct queue *q, int num){
    struct list *temp;
    temp=(struct list *)malloc(sizeof(struct list));
    temp->data=num;
    temp->next=NULL;
    if(q->rear==NULL)
        q->front=q->rear=temp;
    else{
        q->rear->next=temp;
        q->rear=temp;
    }
}

void dequeue(struct queue *q){
    struct list *temp;
    if(q->front==NULL){
        printf("Queue is empty.\n");
        return;
    }
    else
    {
        temp=q->front;
        q->front=q->front->next;
        if(q->front==NULL)
            q->rear=NULL;
        printf("Removed element: %d\n",temp->data);
        free(temp);
    }
    
}
void print(struct queue *q){
    struct list *temp=q->front;
    if((q->front==NULL) && q->rear==NULL){
        printf("Empty queue.\n");
        return;
    }
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
        if(temp!=NULL)
            printf("-->");
    }
}
void delete(struct queue *q){
    struct list *temp;
    while (q->front)
    {
        temp=q->front;
        printf("Element being delete: %d\n",temp->data);
        q->front=q->front->next;
        free(temp);
    }
    free(q);
}
int main(){
    struct queue *q;
    q=create();
    enqueue(q,2);
    enqueue(q,5);
    enqueue(q,10);
    enqueue(q,30);
    enqueue(q,56);
    enqueue(q,88);
    enqueue(q,90);

    print(q);
    printf("\nSize of queue= %d\n",size(q));
    printf("Front Element= %d\n",frontele(q));
    printf("Rear Element= %d\n",rearele(q));

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    enqueue(q,15);
    enqueue(q,100);
    print(q);
    printf("\nSize of queue= %d\n",size(q));
    delete(q);

    return 0;
}








