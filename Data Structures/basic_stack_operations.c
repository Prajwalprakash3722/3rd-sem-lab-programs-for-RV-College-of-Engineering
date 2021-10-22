#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 50

struct stack
{
    int array[STACK_SIZE];
    int top;
};

struct stack s;

void push(int x)
{
    if (s.top == STACK_SIZE - 1)
        printf("Stack is full\n");
    else
    {
        s.top++;
        s.array[s.top] = x;
    }
}

int pop()
{
    if (s.top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        s.top--;
        return s.array[s.top];
    }
}

void display()
{
    if (s.top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = 0; i <= s.top; i++)
        {
            printf("%d\t", s.array[i]);
        }
    }
}

int main()
{
    int x;
    s.top = -1;
    printf("Implementation Of Stack and Basic Operations\n");
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter the element to be pushed\n");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            printf("Popped element is %d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}