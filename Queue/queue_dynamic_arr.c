#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct queue{
    int front,rear;
    int cap;
    int size;
    int *ar;
};

struct queue *create(int cap){
    struct queue *q=malloc(sizeof(struct queue));
    if(!q)
        return NULL;
    q->cap=cap;
    q->front=q->rear=-1;
    q->size=0;
    q->ar=malloc(q->cap*sizeof(int));
    if(!q->ar)
        return NULL;
    return q;
}

int size(struct queue *q){
    return q->size;
}
int frontele(struct queue *q){
    return q->ar[q->front];
}
int rearele(struct queue *q){
    return q->ar[q->rear];
}
int isempty(struct queue *q){
    return (q->size==0);
}
int isfull(struct queue *q){
    return (q->size==q->cap);
}
void resize(struct queue *q){
    int size=q->cap;
    q->cap=q->cap*2;
    q->ar=realloc(q->ar,sizeof(int)*q->cap);
    if(!q->ar){
        printf("Memory error");
        return;
    }
    if(q->front>q->rear)
    {
        int i;
        for(i=0;i<q->front;i++){
            q->ar[i+size]=q->ar[i];
        }
        q->rear=q->rear+size;
    }
}

void enqueue(struct queue *q, int data){
    if (isfull(q))
        resize(q);
    q->rear=(q->rear+1)%q->cap;
    q->ar[q->rear]=data;
    if(q->front==-1)
        q->front=q->rear;
    q->size+=1;
}
int dequeue(struct queue *q){
    int data=INT_MIN;
    if(isempty(q)){
        printf("Queue is Empty");
        return data;
    }
    data=q->ar[q->front];
    if(q->front==q->rear){
        q->front=q->rear=-1;
        q->size=0;
    }
    else{
        q->front=(q->front+1)%q->cap;
        q->size-=1;
    }
    return data;
}
void delete(struct queue *q){
    if(q){
        if(q->ar)
            free(q->ar);
        free(q);
    }
}

int main(){
    struct queue *q;
    q=create(3);
enqueue(q,2);
enqueue(q,5);
enqueue(q,10);
enqueue(q,30);
enqueue(q,56);
enqueue(q,88);
enqueue(q,90);

printf("\nSize of queue= %d\n",size(q));
printf("Front Element= %d\n",frontele(q));
printf("Rear Element= %d\n",rearele(q));

printf("Dequeued Element: %d\n",dequeue(q));
printf("Dequeued Element: %d\n",dequeue(q));
printf("Dequeued Element: %d\n",dequeue(q));
printf("Dequeued Element: %d\n",dequeue(q));
printf("Dequeued Element: %d\n",dequeue(q));
printf("Dequeued Element: %d\n",dequeue(q));
printf("Dequeued Element: %d\n",dequeue(q));

enqueue(q,15);
enqueue(q,100);
printf("\nSize of queue= %d\n",size(q));
delete(q);

    return 0;
}




