#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};


struct node *root = NULL;


//--------------------------------------------------------------
struct node* insert(int data);
void Inorder(struct node* node);
void Preorder(struct node* node);
void Postorder(struct node* node);
int size(struct node* node);

//--------------------------------------------------------------

int main()
{ 
    int choice, ch=1 ,s;

    do{
        printf("\n\n-----------------Binary Search Tree---------------\n");
        printf("Select operation : \n");
        printf("1. Create list.\n");
        printf("2. Inorder\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. no of nodes\n");
        printf("8. Exit. \n");

        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 : 
                root = insert(1);  
                root->left        = insert(2);
                root->right       = insert(3);
                root->left->left  = insert(4);
                root->left->right  = insert(5);
            break;

            case 2 : Inorder(root); break;
            case 3 : Preorder(root); break;
            case 4 : Postorder(root); break;
            case 5 : s = size(root);  printf("Size = %d \n",s);break;
            case 8 : ch=0; break;
            default : printf("You entered a wrong choice.\n");
        }
    }
    while (ch==1);

    return 0;
}


struct node* insert(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return(node);
}


void Inorder(struct node* node)
{
    if (node == NULL)
        return;

    Inorder(node->left);
    printf("%d ", node->data);
    Inorder(node->right);
}



void Preorder(struct node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);  
    Preorder(node->left);
    Preorder(node->right);
}



void Postorder(struct node* node)
{
    if (node == NULL)
        return;

    Postorder(node->left);
    Postorder(node->right);
    printf("%d ", node->data);
}

int size(struct node* node) 
{  
  if (node==NULL) 
    return 0;
  else    
    return(size(node->left) + 1 + size(node->right));  
}