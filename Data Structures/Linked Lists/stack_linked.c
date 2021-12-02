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
        printf("Stack OverFlow \n");
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
        printf("Stack UnderFlow\n");
        exit(1);
        return start;
    }
    NODE cur, prev;
    if (start == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    prev = NULL;
    cur = start;
    while (cur->addr != NULL)
    {
        prev = cur;
        cur = cur->addr;
    }
    prev->addr = NULL;
    printf(";Popped %d\n", cur->data);
    free(cur);
    count--;
    return start;
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
    display(start);
    pop(start);
    display(start);
    return 0;
}