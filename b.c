//Doubly Linked List Implementation
//BY ADITYA KALRA, IT, 11912038

#include<stdio.h>
#include<stdlib.h>

//Structure of Node
struct node{
    int data;
    struct node *left;
    struct node *right;
}*head;

//Creating nodes
createNode(int n){
    head=(struct node*)malloc(sizeof(struct node));
    int data,i;
    printf("Enter node data:");
    scanf("%d",&data);
    struct node *temp;
    temp=head;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    for(i=1;i<n;i++)
	{
	   struct node *newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter node data:");
        scanf("%d",&data);
        newNode->data=data;
        newNode->right=NULL;
        newNode->left=temp;
        temp->right=newNode;
        temp=temp->right;
    }
 }
//Traversing the list
traverse()
{
    struct node *temp = head;
    while(temp)
	{
        printf("%d\t",temp->data);
        temp = temp->right;
    }
}

//Deleting a node with data n
void deleteNode(int n){
    struct node *temp=head;
    while(temp->right->data!=n){
        temp=temp->right;
    }
    struct node *temp1=temp->right;
    temp->right=temp1->right;
    free(temp1);
    temp1=NULL;
}
int main()
{
    int n;
    printf("Enter the number of nodes to be created:");
    scanf("%d",&n);
    createNode(n);
    printf("\nBefore deletion\n");
    traverse();
    printf("\nEnter the data of the node to be deleted:\n");
    scanf("%d",&n);
    deleteNode(n);
    printf("After Deletion\n");
    traverse();
    return 0;
}











//The program is created by ADITYA KALRA
