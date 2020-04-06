#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node * next;
    struct node *prev;
}*head;


void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtN(int data, int position);
void deleteFromBeginning();
void deleteAll(struct node ** head, int key);


int main()
{
    int n, data, choice=1;

    head = NULL;

    while(choice != 0)
    {
        printf("*********************************************\n");
        printf("1. Create List\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at any position\n");
        printf("4. Delete node - from begining\n");
        printf("5. Delete node - from end\n");
        printf("6. Delete specified node\n");
        printf("0. Exit\n");
        printf("*********************************************\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                displayList();
                break;
            case 2:
                printf("Enter data to be inserted at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                displayList();
                break;
            case 3:
                printf("Enter node position: ");
                scanf("%d", &n);
                printf("Enter data you want to insert at %d position: ", n);
                scanf("%d", &data);
                insertAtN(data, n);
                displayList();
                break;
            case 4:
                printf("List after Deletion from begining:");
                deleteFromBeginning();
                displayList();
                break;
            case 4:
                printf("List after Deletion from begining:");
                deleteAll(head,);
                displayList();
                break;

            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-4");
        }

        printf("\n\n");
    }

    return 0;
}




void createList(int n)
{
    int i, data;
    struct node *prevNode, *newNode;

    if(n >= 1)
    {
      
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        prevNode = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            prevNode->next = newNode;
            prevNode = newNode;
        }

        prevNode->next = head;

    }
}



void displayList()
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do {
            printf("Data %d = %d\n", n, current->data);

            current = current->next;
            n++;
        }while(current != head);
    }
}


void insertAtBeginning(int data)
{
    struct node *newNode, *current;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
    
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;

        current = head;
        while(current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        head = newNode;

    }
}


void insertAtN(int data, int position)
{
    struct node *newNode, *current;
    int i;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else if(position == 1)
    {
        insertAtBeginning(data);
    }
    else
    {
      
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;


        current = head;
        for(i=2; i<=position-1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;

    }
}

void deleteFromBeginning()
{
    struct node *toDelete, *prevNode;

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

void deleteAll(struct node ** head, int key)
{
    int i, count;
    struct node *prev, *cur;

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    count = 0;
    cur   = *head;
    prev  = cur;


    while (prev->next != *head) 
    {
        prev = prev->next;
        count++;
    }

    i = 0;
    while (i <= count)
    {
        if (cur->data == key)
        {
            if (cur->next != cur)
                prev->next = cur->next;
            else
                prev->next = NULL;

            if (cur == *head)
                *head = prev->next;
            free(cur);
            if (prev != NULL) 
                cur = prev->next;
            else
                cur = NULL;
        }
        else 
        {
            prev = cur;
            cur  = cur->next;
        }


        i++;

    }
}
