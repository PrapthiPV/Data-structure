
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create()
{
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
            temp->next = newnode;

        temp = newnode;
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void sort(struct node *head)
{
    struct node *temp, *p;
    int t;

    for(temp = head; temp != NULL; temp = temp->next)
    {
        for(p = temp->next; p != NULL; p = p->next)
        {
            if(temp->data > p->data)
            {
                t = temp->data;
                temp->data = p->data;
                p->data = t;
            }
        }
    }
}

struct node* reverse(struct node *head)
{
    struct node *prev = NULL, *current = head, *next;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct node* concatenate(struct node *head1, struct node *head2)
{
    struct node *temp = head1;

    if(head1 == NULL)
        return head2;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    return head1;
}

int main()
{
    struct node *head1, *head2;

    printf("\nEnter First Linked List:\n");
    head1 = create();

    printf("\nEnter Second Linked List:\n");
    head2 = create();

    printf("\nFirst Linked List:\n");
    display(head1);

    printf("\nSecond Linked List:\n");
    display(head2);

    sort(head1);
    printf("\nSorted First Linked List:\n");
    display(head1);

    head1 = reverse(head1);
    printf("\nReversed First Linked List:\n");
    display(head1);

    head1 = concatenate(head1, head2);
    printf("\nConcatenated Linked List:\n");
    display(head1);

    return 0;
}

