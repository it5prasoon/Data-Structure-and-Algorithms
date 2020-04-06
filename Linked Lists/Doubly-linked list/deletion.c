#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

void createList(int n);
void displayList();
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromN(int position);
void deletionafter(int val);
void deletionbefore(int val);


int main()
{
    int n, data1,data2, choice=1;
    head = NULL;
    last = NULL;
    while(choice != 0)
    {
        printf("1. Create List\n");
        printf("2. Delete node - from beginning\n");
        printf("3. Delete node - from end\n");
        printf("4. Delete node - from N\n");
        printf("5. Delete node - after a given node\n");
        printf("6. Delete node - before a given node\n");
        printf("0. Exit\n");
        label:
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                displayList();
                break;
            case 2:
                deleteFromBeginning();
                displayList();
                break;
            case 3:
                deleteFromEnd();
                displayList();
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &n);
                deleteFromN(n);
                displayList();
                break;
            case 5:
                printf("\nEnter element after which you want to delete: ");
                scanf("%d", &data1);
                deletionafter(data1);
                displayList();
                break;
            case 6:
                printf("\nEnter element before which you want to delete: ");
                scanf("%d", &data2);
                deletionbefore(data2);
                displayList();
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-5");
        }
        printf("\n");
        goto label;

    }

    return 0;
}

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->prev = last; 
            newNode->next = NULL;
            last->next = newNode; 
            last = newNode; 
        }

    }
}


void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");
        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}



void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;
        head = head->next; 
        if (head != NULL)
            head->prev = NULL; 

        free(toDelete); 
        
    }
}


void deleteFromEnd()
{
    struct node * toDelete;

    if(last == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = last;
        last = last->prev; 
        if (last != NULL)
            last->next = NULL; 
        free(toDelete);       
    }
}


void deleteFromN(int position)
{
    struct node *current;
    int i;

    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); 

    }
    else
    {
        printf("Invalid position!\n");
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

void deletionbefore(int val)
{
    struct node *todelete, *nextnode;

    todelete=last;
    nextnode=todelete;
    while(nextnode->data!=val){
        nextnode=todelete;
        todelete=todelete->prev;
    }
    nextnode->prev=todelete->prev;
    free(todelete);
    return;
}