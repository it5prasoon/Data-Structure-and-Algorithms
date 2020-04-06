#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

void createList(int n);
void displaylistfromfirst();
void displaylistfromend();


int main()
{
    int n, choice;

    head = NULL;
    last = NULL;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createList(n);
    label:
    printf("\nPress 1 to display list from First and 2 for display from last: ");
    scanf("%d", &choice);

    if(choice==1)
    {
        displaylistfromfirst();
        goto label;
    }
    else if(choice == 2)
    {
        displaylistfromend();
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
        if(head != NULL)
        {
            printf("Node 1: ");
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
                    printf("Node %d: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last; 
                    newNode->next = NULL;

                    last->next = newNode; 
                    last = newNode;         
                }
                else
                {
                    printf("Unable to allocate.");
                    break;
                }
            }
        }
        else
        {
            printf("Unable to allocate.");
        }
    }
}

void displaylistfromfirst()
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
        printf("\n\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("Node %d= %d\n", n, temp->data);
            n++;   
            temp = temp->next;
        }
    }
}

void displaylistfromend()
{
    struct node * temp;
    int n = 1;

    if(last == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = last;
        printf("\n\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("Node %d: %d\n", n, temp->data);
            n++;
            temp = temp->prev; 
        }
    }
}