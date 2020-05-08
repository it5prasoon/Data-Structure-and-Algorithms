/* Binary Tree 
Basic operations--> Insertion, Deletion, Searching, Traversing
Auxiliary Operations--> Finding the size of tree, Finding the height of the tree, Finding the level which has maximum sum, Finding the least common ancestor(LCA)
for a given pair of nodes and many more.

Applications of Binary Tree
1. Expression trees are used in compilers.
2. Huffmann coding that are used in data compression algorithms.
3. Binary search tree
4. Priority queue

Preorder(L)
Inorder(D)
Postorder(R)
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct list{
    int data;
    struct list *next;
};
struct Queue{
    struct list *front;
    struct list *rear;
};

struct Queue *createQueue()
{
    struct Queue *q;
    struct list *temp;
    q=malloc(sizeof(struct Queue));
    if(!q)
        return NULL;
    temp=malloc(sizeof(struct list));
    q->front=q->rear=NULL;
    return q;
};

int isEmpty(struct Queue *q){
    if(q->front==NULL && q->rear==NULL)
        return 0;
    else
        return 1;       
}
void enQueue(struct Queue *q, int num){
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

void deQueue(struct Queue *q){
    struct list *temp;
    if(q->front==NULL){
   //     printf("Queue is empty.\n");
        return;
    }
    else
    {
        temp=q->front;
        q->front=q->front->next;
        if(q->front==NULL)
            q->rear=NULL;
    //    printf("Removed element: %d\n",temp->data);
    
        free(temp);
    }
    
}

void deleteQueue(struct Queue *q){
    struct list *temp;
    while (q->front)
    {
        temp=q->front;
     //   printf("Element being delete: %d\n",temp->data);
        q->front=q->front->next;
        free(temp);
    }
    free(q);
}

struct Node* newNode(int data){
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(struct Node *root){
    if(root){
        printf("%d->",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root){
    if(root){
        inorder(root->left);
        printf("%d->",root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d->",root->data);
    }
}

void levelorder(struct Node *root){
    struct Node *temp;
    struct Queue *Q = createQueue();
    if(!root)
        return;
    enqueue(Q,root);
    while(!isEmpty(Q)){
        temp = deQueue(Q);
        printf("%d",temp->data);
        if(temp->left)
            enQueue(Q,temp->left);
        if(temp->right)
            enQueue(Q,temp->right);
        
    }
    deleteQueue(Q);
    
}
int main(){
    struct Node* root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->right = newNode(9);
    root->right->left=newNode(15);
    root->right->right = newNode(8);

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    
    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}




