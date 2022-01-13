#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int count = 0;

struct node
{
    int data;
    struct node *addr;
};

typedef struct node *NODE;

NODE getnode()
{
    return (NODE)malloc(sizeof(struct node));
}

NODE push(NODE start, int x)
{
    if (count >= SIZE)
    {
        printf("Queue OverFlow \n");
        return start;
        exit(0);
    }
    NODE temp, cur;

    temp = getnode();
    temp->data = x;
    temp->addr = NULL;
    if (start == NULL)
    {
        return temp;
    }
    cur = start;
    while (cur->addr != NULL)
    {
        cur = cur->addr;
    }
    cur->addr = temp;
    count++;
    return temp;
}
NODE pop(NODE start)
{
    if (count == 0)
    {
        printf("Queue UnderFlow\n");
        exit(1);
        return start;
    }
    NODE temp = start;
    start = start->addr;
    printf("Dequeued Data: %d\n", temp->data);
    free(temp);
    return start;
    count--;
}

void display(NODE start)
{
    while (start != NULL)
    {
        printf("%d  ", start->data);
        start = start->addr;
    }
}

int main()
{

    NODE start;
    start = getnode();
    push(start, 1);
    push(start, 2);

    push(start, 3);

    display(start);
    pop(start);
    display(start);

    // pop(start);

    display(start);
    return 0;
}