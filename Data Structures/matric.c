#include <stdio.h>
#include <stdlib.h>

struct node
{
  int row, col, data;
  struct node *prev, *next;
};

typedef struct node *NODE;

NODE insertend(NODE start, int data, int row, int col)
{
  NODE temp, cur;

  temp = (NODE)malloc(sizeof(struct node));

  temp->data = data;
  temp->row = row;
  temp->col = col;
  temp->prev = NULL;
  temp->next = NULL;

  if (start == NULL)
    return temp;
  else
  {
    cur = start;
    while (cur->next != NULL)
      cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return start;
  }
}

void display(NODE start)
{
  NODE temp;
  if (start == NULL)
    printf("\nThe list is empty\n");
  else
  {
    printf("\nRow\tcolumn\tdata\n");
    temp = start;
    while (temp != NULL)
    {
      printf("\n%d\t%d\t%d\n", temp->row, temp->col, temp->data);
      temp = temp->next;
    }
  }
}

void displaymatrix(NODE start, int m, int n)
{
  NODE temp;
  int i, j;
  temp = start;

  for (i = 1; i <= m; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (temp != NULL && temp->row == i && temp->col == j)
      {
        printf("%d\t", temp->data);
        temp = temp->next;
      }
      else
        printf("0\t");
    }
    printf("\n");
  }
}

void main()
{
  int m, n, i, j, item;
  NODE start = NULL;

  printf("\nEnter the order of the matrix:\n");
  scanf("%d%d", &m, &n);

  printf("\nEnter the elements row-wise:\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
    {
      scanf("%d", &item);
      if (item != 0)
        start = insertend(start, item, i + 1, j + 1);
    }
  printf("\n The list elements are:\n");

  display(start);

  printf("\nThe Matrix is :\n");
  displaymatrix(start, m, n);
}
