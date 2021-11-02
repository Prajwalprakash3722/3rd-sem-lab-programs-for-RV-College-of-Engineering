#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 100

struct queue
{
    int array[QUEUE_SIZE];
    int front, rear;
};

void enqueue(struct queue *q, int x)
{
    if (q->rear == QUEUE_SIZE - 1)
        printf("Queue Overflow \n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->array[q->rear] = x;
    }
}

void dequeue(struct queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", q->array[q->front]);
        q->front = q->front + 1;
    }
}

void show(struct queue *q)
{

    if (q->front == -1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = q->front; i <= q->rear; i++)
            printf("%d \n", q->array[i]);
    }
}
int main()
{
    struct queue q;
    q.front = -1;
    q.rear = -1;
    int choice, x;
    while (1)
    {
        printf("1.Enqueue Operation\n2.Dequeue Operation\n3.Display the Queue\n4.Exit\n\nEnter your choice of operations : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Element to be inserted in the Queue :\t");
            scanf("%d", &x);
            enqueue(&q, x);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            show(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Incorrect choice \n");
        }
    }
}