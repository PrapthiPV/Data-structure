#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

// STACK PUSH
void push()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;

    printf("Element pushed\n");
}

// STACK POP
void pop()
{
    struct node *temp;

    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        temp = top;
        printf("Deleted element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

// STACK DISPLAY
void displayStack()
{
    struct node *temp = top;

    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        printf("Stack: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// QUEUE INSERT
void insert()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(front == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element inserted\n");
}

// QUEUE DELETE
void delete()
{
    struct node *temp;

    if(front == NULL)
        printf("Queue is empty\n");
    else
    {
        temp = front;
        printf("Deleted element: %d\n", front->data);

        front = front->next;

        if(front == NULL)
            rear = NULL;

        free(temp);
    }
}

// QUEUE DISPLAY
void displayQueue()
{
    struct node *temp = front;

    if(front == NULL)
        printf("Queue is empty\n");
    else
    {
        printf("Queue: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// MAIN FUNCTION
int main()
{
    int ch, op;

    while(1)
    {
        printf("\n1. Stack Operations");
        printf("\n2. Queue Operations");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\n1. Push");
                printf("\n2. Pop");
                printf("\n3. Display");
                printf("\nEnter choice: ");
                scanf("%d", &op);

                switch(op)
                {
                    case 1: push(); break;
                    case 2: pop(); break;
                    case 3: displayStack(); break;
                    default: printf("Invalid choice\n");
                }
                break;

            case 2:
                printf("\n1. Insert");
                printf("\n2. Delete");
                printf("\n3. Display");
                printf("\nEnter choice: ");
                scanf("%d", &op);

                switch(op)
                {
                    case 1: insert(); break;
                    case 2: delete(); break;
                    case 3: displayQueue(); break;
                    default: printf("Invalid choice\n");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
