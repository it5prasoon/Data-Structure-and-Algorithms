#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stack{
    int top;
    int cap;
    int *ar;
};

struct stack *create(int cap){
    struct stack *s=malloc(sizeof(struct stack));
    if(!s)
        return NULL;
    s->cap=cap;
    s->top=-1;
    s->ar=malloc(s->cap *sizeof(int));
    if(!s->ar)
        return NULL;
    return s;
}

int isempty(struct stack *s){
    return (s->top==-1);
}

int size(struct stack *s){
    return (s->top+1);
}
int isfull(struct stack *s){
    return (s->top==s->cap-1);
}

void push(struct stack *s,int data){
    if(isfull(s))
        printf("Stack Overflow.\n");
    else
        s->ar[++s->top]=data; 
}

int pop(struct stack *s){
    return (s->ar[s->top--]);
}
int peek(struct stack *s){
    return (s->ar[s->top]);
}

void delete(struct stack *s){
    if(s){
        if(s->ar)
            free(s->ar);
                free(s);
    }
}

int main()
{
    int i=0,cap=5;
    struct stack *stk=create(cap);
    for(i=0;i<cap;i++){
        push(stk,i);
    }
    printf("Top element= %d\n",peek(stk));
    printf("Size= %d\n",size(stk));
     for(i=0;i<cap;i++){
        printf("Popped element is= %d\n",pop(stk));
    }
    delete(stk);
    return 0;
}