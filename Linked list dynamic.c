#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct node
{
    int data;
    struct node * next;
};

struct node * createnode(int data)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insend(struct node ** head, int data)
{
    struct node * newnode = createnode(data);
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    struct node * temp = *head;
    while(temp->next != NULL)
        temp=temp->next;
    temp->next = newnode;
}

void display(struct node * head)
{
    struct node * temp = head;
    printf("Doubly linked list :\n");
    while(temp != NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct node * head = NULL;
    int n, value, choice;

    printf("Enter number of nodes :\n");
    scanf("%d",&n);

    for(int i = 0;i<n;i++)
    {
        printf("Enter value of node %d :",i+1);
        scanf("%d",&value);
        insend(&head, value);
    }

    display(head);

    return 0;
}
