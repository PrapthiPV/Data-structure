#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10
void push(int);
void pop();
void display();
int stack[SIZE],top=-1;
void push(int value)
{

    if(top==SIZE-1)
    {
        printf("\nStack is full!Insertion is not possible");
    }
    else{
        top++;
        stack[top]=value;
        printf("\n Insertion success!!");
    }
}
void pop()
{

    if(top==-1)
    {
        printf("Stack empty");
        }
        else{
            printf("\n Deleted :%d",stack[top]);
            top--;
        }

}
void display()
{
    if(top==-1)
    {
        printf("Stack empty");
        }
        else{
          int i;
          printf("Stack element are:\n");
          for(i=top;i>=0;i--)
          {
              printf("%d\n",stack[i]);
          }
        }

}
void main()
{
int value,choice;

while(1)
{
printf("\nEnter your choice:1.Push 2.Pop 3.Display 4.exit:");
scanf("%d",&choice);
switch(choice){
case 1:
    printf("Enter the value to be inserted:");
    scanf("%d",&value);
    push(value);
    break;
case 2:
    pop();
    break;
case 3:
      display();
      break;
case 4:
    exit(0);
default:printf("\nWrong Selection!!TRy again!!");
}
}
}