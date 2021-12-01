#include <stdio.h>
#include <stdlib.h>

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

NODE insert_end(NODE start, int x)
{
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
    return temp;
}

NODE insert_begin(NODE start, int x)
{
    NODE temp;
    temp = getnode();
    temp->data = x;
    temp->addr = start;
    return temp;
}

NODE delete_begin(NODE start)
{
    NODE temp = start;
    if (start == NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    // while
    // temp = getnode();
    // temp = start;
    start = start->addr;
    printf("Removed Data: %d\n", temp->data);
    free(temp);
    return start;
}

NODE delete_end(NODE start)
{
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
    printf("Removed Data: %d\n", cur->data);
    free(cur);
    return start;
}

void printList(NODE n)
{
    while (n != NULL)
    {
        printf(" %d \n", n->data);
        n = n->addr;
    }
}

int main()
{

    NODE start;
    start = getnode();
    insert_end(start, 5);
    insert_end(start, 2);
    delete_begin(start);
    delete_end(start);
    // insert_begin(start, 51);
    insert_end(start, 3);
    insert_end(start, 5);

    printList(start);
    return 0;
}
