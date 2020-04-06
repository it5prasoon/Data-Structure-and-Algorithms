#include <stdio.h>
#include <stdlib.h>
#define MAX 10


int st[MAX], top=-1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);


int main() {
int val, op;
do
{
    printf("1. PUSH 2. POP 3. PEEK 4. DISPLAY 5. EXIT");
    printf("\nEnter your option: ");
    scanf("%d", &op);
    switch(op)
    {
    case 1:
        printf("\nPush the number: \n");
        scanf("%d", &val);
        push(st, val);
        break;
    case 2:
        val = pop(st);
        if(val != -1)
        printf("\nPop the element: %d\n", val);
        break;
    case 3:
        val = peek(st);
        if(val != -1)
        printf("\nPeek the element: %d\n", val);
        break;
    case 4:
        display(st);
    break;
    }
    }while(op != 5);
return 0;
}

void push(int st[], int val)
{
    if(top == MAX-1)
    {
        printf("\nStack is Overflowed.");
    }
    else
    {
        top++;
        st[top] = val;
    }
}

int pop(int st[])
{
    int val;
    if(top == -1)
    {
        printf("\nStack is Overflowed.");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;
    }
}

void display(int st[])
{
    int i;
    if(top == -1)
        printf("\n STACK IS EMPTY");
    else
    {
        for(i=top;i>=0;i--)
            printf("\n%d",st[i]);
            printf("\n"); 
    }
}

int peek(int st[])
{
    if(top == -1)
    {
        printf("\nSTACK IS EMPTY");
        return -1;
    }
    else
        return (st[top]);
}