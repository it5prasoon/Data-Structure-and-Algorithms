#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

void createList(int n);
void display();
void insertatbeginning(int data);
void insertatend(int data);
void insertatposition(int data, int pos);



int main()
{
    int n, ele1, ele2,ele3,pos;
    head = NULL;
    last = NULL;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("List Created: \n");
    display();

    printf("\nElement to be inserted at front: ");
    scanf("%d",&ele1);
    insertatbeginning(ele1);
    display();

    printf("\nElement to be inserted at end: ");
    scanf("%d",&ele2);
    insertatend(ele2);
    display();

    printf("\nEnter position: ");
    scanf("%d",&pos);
    printf("\nElement to be inserted: ");
    scanf("%d",&ele3);
    insertatposition(ele3,pos);
    display();
    return 0;
}

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        if(head != NULL)
        {
            scanf("%d", &data);
            head->data = data;
            head->prev = NULL;
            head->next = NULL;
            last = head;
            for(i=2; i<=n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                if(newNode != NULL)
                {
                    scanf("%d", &data);
                    newNode->data = data;
                    newNode->prev = last; 
                    newNode->next = NULL;
                    last->next = newNode; 
                    last = newNode;         
                }
                else
                {
                    printf("Unable to allocate memory.");
                    break;
                }
            }
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
}

void insertatbeginning(int data)
{
    struct node * newNode;

    if(head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = head; 
        newNode->prev = NULL; 
        head->prev = newNode;
        head = newNode;
    }
}
void insertatend(int data)
{
    struct node * newNode;
    if(last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
}
void insertatposition(int data, int pos){
    int i;
    struct node *newNode,*temp;
    if(newNode==NULL)
        printf("Unable to allocate\n");
    else{
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data=data;
        newNode->next=NULL;
        newNode->prev=NULL;
        temp=head;
        for(i=2; i<=pos-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }
        if(temp != NULL)
        {
            newNode->next = temp->next; 
            temp->next = newNode;
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }

}


void display()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        printf("\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("%d ",temp->data);
            n++;   
            temp = temp->next;
        }
    }
}