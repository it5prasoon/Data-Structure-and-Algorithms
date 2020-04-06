#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;          
    struct node *next;  
}*head;
void createList(int n);
void insertnodelast(int data);
void insertnodefront(int data);
void insertnodemiddle(int data,int position);
void deletionfromfront();
void deletionfromlast();
void deletionafter(int val);
void displayList();

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Node 1: ");
        scanf("%d", &data);

        head->data = data; 
        head->next = NULL; 

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Node %d: ", i);
                scanf("%d", &data);
                newNode->data = data; 
                newNode->next = NULL; 
                temp->next = newNode; 
                temp = temp->next; 
            } } }
}

void insertnodelast(int data)
{
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL; 
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}
void insertnodefront(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = head; 
        head = newNode;         
    }
}

void insertnodemiddle(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = NULL;

        temp = head;
        for(i=2; i<=position-1; i++)
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
void deletionfromfront(){
    struct node *todelete;

    if(head==NULL){
        printf("can't perform deletion \n");
    }
    else
    {
        todelete=head;
        head=head->next;
        free(todelete);
    }  
}
void deletionfromlast(){
    struct node *todelete, *ndlastnode;

    if(head==NULL){
        printf("List is empty.\n");
    }
    else
    {
        todelete=head;
        ndlastnode=head;

        while(todelete->next!=NULL){
            ndlastnode=todelete;
            todelete=todelete->next;
        }

        if(todelete==head){
            head=NULL;
        }
        else
        {
            ndlastnode->next=NULL;
        }
        free(todelete);
        
    }
    
}
void deletionafter(int val){
    struct node *todelete, *prevnode;

    todelete=head;
    prevnode=todelete;
    while(prevnode->data!=val){
        prevnode=todelete;
        todelete=todelete->next;
    }
    prevnode->next=todelete->next;
    free(todelete); 
    return;
    
}

void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("empty");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data); 
            temp = temp->next;         
        }
    }
}
int main()
{
    int n, data,position,key;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    insertnodelast(data);
    displayList();

    printf("\nEnter data to insert at front of the list: ");
    scanf("%d", &data);
    insertnodefront(data);
    displayList();

    printf("\nEnter data to insert at any position of the list: ");
    scanf("%d", &data);
    printf("Enter position to insert: ");
    scanf("%d",&position);
    insertnodemiddle(data,position);
    displayList();

    printf("\n\nDeletion from front: ");
    deletionfromfront();
    displayList();

    printf("\nDeletion from last: ");
    deletionfromlast();
    displayList();

    printf("\nEnter element after which you want to delete: ");
    scanf("%d", &data);
    deletionafter(data);
    displayList();

return 0;
}