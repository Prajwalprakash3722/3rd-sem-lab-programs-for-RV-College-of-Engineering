#include <stdio.h>
#include <stdlib.h>

struct node
{
  int co, po;
  struct node *addr;
};

typedef struct node *NODE;

NODE insertend(NODE start, int co, int po)
{
  NODE temp, cur;

  temp = (NODE)malloc(sizeof(struct node));

  temp->co = co;
  temp->po = po;
  temp->addr = NULL;

  if (start == NULL)
    return temp;

  cur = start;

  while (cur->addr != NULL)
    cur = cur->addr;
  cur->addr = temp;

  return start;
}

void display(NODE start)
{
  NODE temp;

  if (start == NULL)
    printf("Polynomai is empty");
  else
  {
    temp = start;
    while (temp->addr != NULL)
    {
      printf("%d*x^%d + ", temp->co, temp->po);
      temp = temp->addr;
    }
    printf("%d*x^%d ", temp->co, temp->po);
  }
}

NODE addterm(NODE start, int co, int po)
{
  int flag = 0;
  NODE temp, cur;

  temp = (NODE)malloc(sizeof(struct node));

  temp->co = co;
  temp->po = po;

  temp->addr = NULL;

  if (start == NULL)
    return temp;

  cur = start;

  while (cur != NULL)
  {
    if (cur->po == temp->po)
    {
      cur->co = cur->co + temp->co;
      flag = 1;
      return start;
    }
    cur = cur->addr;
  }

  if (flag == 0)
  {
    free(temp);
    return insertend(start, co, po);
  }
}

NODE multiply(NODE poly1, NODE poly2)
{
  NODE first, second, res = NULL;

  for (first = poly1; first != NULL; first = first->addr)
    for (second = poly2; second != NULL; second = second->addr)
      res = addterm(res, first->co * second->co, first->po + second->po);
  return res;
}

int main()
{
  NODE poly1 = NULL, poly2 = NULL, poly = NULL;

  int m, n, co, po, i;

  printf("\n Enter no of terms of 1st polynomial:\n");
  scanf("%d", &m);

  for (i = 1; i <= m; i++)
  {
    printf("\n Enter the coefficient and power for %d term ", i);
    scanf("%d%d", &co, &po);
    poly1 = insertend(poly1, co, po);
  }

  printf("The first polynomial is:");
  display(poly1);

  printf("\n Enter no of terms of 2nd polynomial:\n");
  scanf("%d", &n);

  for (i = 1; i <= n; i++)
  {
    printf("\n Enter the coefficient and power for %d term ", i);
    scanf("%d%d", &co, &po);
    poly2 = insertend(poly2, co, po);
  }

  printf("The second polynomial is:");
  display(poly2);

  poly = multiply(poly1, poly2);
  printf("\n The resultant polynomial is:");
  display(poly);

  return 0;
}
