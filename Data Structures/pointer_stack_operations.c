#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

struct stack
{
    int array[STACK_SIZE];
    int top;
};

void push(struct stack *s, int x)
{
    if (s->top == STACK_SIZE - 1)
        printf("Stack is full\n");
    else
    {
        s->top++;
        s->array[s->top] = x;
    }
}

int pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        s->top--;
        return s->array[s->top];
    }
}

void display(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = 0; i <= s->top; i++)
        {
            printf("%d\t", s->array[i]);
        }
    }
}

int main()
{
    struct stack s;
    int x;
    s.top = -1;
    printf("\nImplementation Of Stack Using Pointers and Basic Operations\n");
    while (1)
    {
        printf("\n1:\tPush\n2:\tPop\n3:\tDisplay\n4:\tExit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter the element to be pushed\n");
            scanf("%d", &x);
            push(&s, x);
            break;
        case 2:
            printf("Popped element is %d\n", pop(&s));
            break;
        case 3:
            display(&s);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}