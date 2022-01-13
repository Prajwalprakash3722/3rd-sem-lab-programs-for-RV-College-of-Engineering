#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int tree[2050], i, j, k;
void segmentalloc(int totsize, int request)
{
  int flevel = 0, size;
  size = totsize;
  if (request > totsize)

  {
    printf(" * The system don't have enough free memory\n");
    return;
  }
  while (1)

  {
    if (request < size && request > (size / 2))
      break;
    else
    {
      size /= 2;
      flevel++;
    }
  }

  for (i = power(2, flevel) - 1; i <= (power(2, flevel + 1) - 2); i++)
    if (tree[i] == 0 && place(i))

    {
      tree[i] = request;
      makedivided(i);
      printf(" Result : Successful Allocation\n");
      break;
    }
  if (i == power(2, flevel + 1) - 1)

  {
    printf(" * The system don't have enough free memory\n");
  }
}

void makedivided(int node)

{
  while (node != 0)

  {
    node = node % 2 == 0 ? (node - 1) / 2 : node / 2;
    tree[node] = 1;
  }
}

int place(int node)

{
  while (node != 0)

  {
    node = node % 2 == 0 ? (node - 1) / 2 : node / 2;
    if (tree[node] > 1)
      return 0;
  }
  return 1;
}
int power(int x, int y)
{
  int z, ans;
  if (y == 0)
    return 1;
  ans = x;
  for (z = 1; z < y; z++)
    ans *= x;
  return ans;
}

void makefree(int request)
{
  int node = 0;
  while (1)

  {
    if (tree[node] == request)
      break;
    else
      node++;
  }
  tree[node] = 0;

  while (node != 0)

  {
    if (tree[node % 2 == 0 ? node - 1 : node + 1] == 0 && tree[node] == 0)

    {
      tree[node % 2 == 0 ? (node - 1) / 2 : node / 2] = 0;
      node = node % 2 == 0 ? (node - 1) / 2 : node / 2;
    }
    else
      break;
  }
}

void printing(int totsize, int node)

{
  int permission = 0, llimit, ulimit, tab;
  if (node == 0)
    permission = 1;
  else if (node % 2 == 0)
    permission = tree[(node - 1) / 2] == 1 ? 1 : 0;
  else
    permission = tree[node / 2] == 1 ? 1 : 0;
  if (permission)

  {
    llimit = ulimit = tab = 0;

    while (1)

    {
      if (node >= llimit && node <= ulimit)
        break;
      else
      {
        tab++;

        llimit = ulimit + 1;
        ulimit = 2 * ulimit + 2;
      }
    }
    printf(" %d ", totsize / power(2, tab));

    if (tree[node] > 1)
      printf("---> Allocated %d", tree[node]);
    else if (tree[node] == 1)
      printf("---> Divided");
    else
      printf("---> Free");
    printing(totsize, 2 * node + 1);
    printing(totsize, 2 * node + 2);
  }
}

void main()

{
  int totsize, cho, req;
  printf(" * Enter the Size of the memory : \n");
  scanf("%d", &totsize);

  while (1)

  {

    printf(" B U D D Y S Y S T E M\n");
    printf("1:memory Allocation 2:memory deallocation 3:memory map 4:exit\n");
    printf(" * Enter your choice : \n");
    scanf("%d", &cho);
    switch (cho)

    {
    case 1:
      printf("\n M E M O R Y A L L O C A T I O N \n");
      printf(" * Enter the Process size :\n");
      scanf("%d", &req);
      segmentalloc(totsize, req);
      break;
    case 2:
      printf(" \n M E M O R Y D E A L L O C A T I O N \n");
      printf(" * Enter the process size : \n");
      scanf("%d", &req);
      makefree(req);
      break;
    case 3:

      printf(" M E M O R Y A L L O C A T I O N M A P\n");
      printing(totsize, 0);
      break;
    case 4:
      return;
    }
  }
}
