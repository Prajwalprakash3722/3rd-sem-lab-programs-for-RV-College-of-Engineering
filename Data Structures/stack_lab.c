

#include <stdio.h>
#include <stdlib.h>
/********** STACK DEFINITION **************************************/
#define STACKSIZE 5
struct stack
{
    int items[STACKSIZE];
    int top;
};

/********** DEFINITION OF PRIMITIVE OPERATIONS : push ,pop**************/
void push(struct stack *s, int x)
{
    if (s->top == (STACKSIZE - 1))
    {
        printf("Stack Overflow\n");
        exit(0);
    }
    s->top++;
    s->items[s->top] = x;
}
int pop(struct stack *s)
{
    int x;
    if (s->top == -1)
    {
        printf("Stack Underflow!\n");
        exit(0);
    }

    x = s->items[s->top];
    s->top--;
    return x;
}

int stackTop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Underflow");
        exit(0);
    }
    return (s->items[s->top]);
}

/*************************** Display function to check the Stack Contenets****/
void display(struct stack *s)
{
    int i;
    if (s->top == -1)
    {
        printf("Stack Empty!\n");
        return;
    }
    printf("Stack Elements are");
    for (i = 0; i <= s->top; i++)
        printf("\n%d", s->items[i]);
}

int main()
{

    int i, x, choice, flag, y, x1, x2, n;
    /*********** Stack and temporary Declaration ******************/
    struct stack st, tempst;
    /***************** Stack and temporary Intialization : Empty Stack **/
    st.top = -1;
    tempst.top = -1;
    printf("Demonstration of Working of data structure STACK\n\n");
    while (1)
    {

        printf("\n1:PUSH\n2:POP\n3:Display\n4:Third Element from Top\n5:Pop n Elements\n6:Third Element from bottom\n7:exit ");
        printf("\nEnter the Choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the element to be pushed ");
            scanf("%d", &x);
            push(&st, x);
            break;
        case 2:
            x = pop(&st);
            printf("Poped element is %d", x);
            break;
        case 3:
            display(&st);
            break;
            // Third Element from the top   case 4
        case 4:
            if (st.top >= 2) // atlest 3 elements must be in stack
            {
                x1 = pop(&st);
                x2 = pop(&st);
                y = stackTop(&st); // 3 element from top
                push(&st, x2);
                push(&st, x1);
                printf("\nThird Element From Top %d", y);
            }
            else
            {
                printf("\nStack has less then  3 elements");
            }
            break;
        case 5:
            printf("Enter the number of elements to be popped");
            scanf("%d", &n);
            if (n <= (st.top + 1))
            {
                printf("\npopped elements are : ");
                for (i = 1; i <= n; i++)
                {
                    x = pop(&st);
                    printf("  %d", x);
                }
            }
            else
                printf("\n No of elements in stack  is less than %d", n);
            break;
            // Third element from BOTTOM
        case 6:
            if (st.top >= 2) // atlest 3 elements must be in stack
            {
                n = st.top - 2;
                for (i = 1; i <= n; i++)
                {
                    x = pop(&st);     // pop from original stack
                    push(&tempst, x); // push on temporary stack
                }
                y = stackTop(&st); // 3rd element from bottom
                for (i = 1; i <= n; i++)
                {
                    x = pop(&tempst); // pop from temporary stack
                    push(&st, x);     // push on original stack
                }
                printf("\nThird Element From Top %d", y);
            }
            else
                printf("\nStack has less then  3 elements");

            break;
        case 7:
            exit(0);

        } //switch

    } //while
    return 0;
} //main