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

void 

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

    

    return 0;
}




