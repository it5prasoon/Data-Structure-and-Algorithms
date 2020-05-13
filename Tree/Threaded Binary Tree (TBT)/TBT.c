// Advantages of Threaded Binary Tree
// Σ It enables linear traversal of elements in the tree.
// Σ Linear traversal eliminates the use of stacks which in turn consume a lot of memory space
// and computer time.
// Σ It enables to find the parent of a given element without explicit use of parent pointers.
// Σ Since nodes contain pointers to in-order predecessor and successor, the threaded tree enables
// forward and backward traversal of the nodes as given by in-order fashion

// A Simple Right-in threaded bianry tree

//=============================================================
#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int node;
    struct tree *right;
    struct tree *left;
    int thread;
};

struct tree *root=NULL;
struct tree* insert_node(struct tree *root, struct tree *ptr, struct tree *rt)
{
    if(root==NULL){
        root = ptr;
        if(rt!=NULL){
            root->right=rt;
            root->thread = 1;
        }

    }
    else if(ptr->node < root->node)
        root->left = insert_node(NULL,ptr,root);
        else{
            if(root->thread ==1){
                root->right = insert_node(NULL,ptr,rt);
                root->thread =0;
            }
            else{
                root->right = insert_node(root->right, ptr, rt);
            }
        }
        return root;
}

struct tree* create_threaded_tree()
{
    struct tree *ptr;
    int num;
    printf("Enter the elements: ");
    scanf("%d", &num);
    while(num != -1){
        ptr = (struct tree*)malloc(sizeof(struct tree));
        ptr->node = num;
        ptr->left = ptr->right =NULL;
        ptr->thread = 0;
        root = insert_node(root,ptr,NULL);
        printf("Enter the next element: ");
        scanf("%d",&num);
    }
 return root;   
}

void inorder(struct tree *root){
    struct tree *ptr = root, *prev;
    do
    {
        while(ptr!=NULL){
            prev = ptr;
            ptr = ptr->left;
        }
        if(prev!=NULL){
            printf("%d", prev->node);
            while(prev !=NULL && prev->thread){
                printf("%d",ptr->node);
                prev = ptr;
                ptr = ptr->right;
            }
        }
    } while (ptr!=NULL);
    
}

// void inorder(struct tree *root){
//     if(root){
//         inorder(root->left);
//         printf("%d->",root->node);
//         inorder(root->right);
//     }
// }
int main(){
    struct tree *root=NULL;
    create_threaded_tree();
    printf("The inorder traversal of the tree can be given as: ");
    inorder(root);

    return 0;
}






