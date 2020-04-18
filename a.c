//Linked List Implementation
//By ADITYA KALRA, IT, 11912038

#include<stdio.h>
#include<stdlib.h>

//Structure of Node
struct node{
    int data;
    struct node *link;
}*head;

//Creating nodes
createnode(int n)
{
    int data,i;
    struct node *temp;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        printf("Head Node not created");
        return;
    }
    printf("Enter Node data:");
    scanf("%d",&data);
    head->data=data;
    head->link=NULL;
    temp=head;
    for(i=2;i<=n;i++)
	{
        struct node *newNode=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data:");
        scanf("%d",&data);
        newNode->data=data;
        temp->link=newNode;
        newNode->link=NULL;
        temp=temp->link;
    }
}
//Traverse a List
traverse()
{
    struct node* temp=head;
    while(temp)
	{
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}
//Deleting a Node
void deleteNode(int n)
{
    struct node *temp = head;
    while(temp->link->data!=n)
	{
        temp=temp->link;
    }
    struct node *del = temp->link;
    temp->link=del->link;
    free(del);
    del = NULL;
}
int main(){
    int n;
    printf("Enter the number of nodes to be created:");
    scanf("%d",&n);
    createnode(n);
    printf("Before Deletion:\n");
    traverse();  
    printf("\nEnter the node data to be deleted:\n");
    scanf("%d",&n);
    deleteNode(n);
    printf("After Deletion\n");
    traverse();
    return 0;
}










//By ADITYA KALRA
