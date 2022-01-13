#include <stdio.h>
void main()
{
  int process, resource, i, j, instance, k = 0;
  int count1 = 0, count2 = 0;
  printf("Enter number of processes");
  scanf("%d", &process);
  printf("Enter number of resources");
  scanf("%d", &resource);
  int avail[resource], max[process][resource], allot[process][resource], need[process][resource], completed[process];
  for (i = 0; i < process; i++)
    completed[i] = 0;
  printf("Enter the no. of available instances");
  for (i = 0; i < resource; i++)
  {
    scanf("%d", &instance);
    avail[i] = instance;
  }
  printf("Enter man no. of instances of resource that a process need");
  for (i = 0; i < process; i++)
  {
    printf("For P[%d]", i);
    for (j = 0; j < resource; j++)
    {
      scanf("%d", &instance);
      max[i][j] = instance;
    }
  }
  printf("Enter the no. of instances already alloted to process of a resource");
  for (i = 0; i < process; i++)
  {
    printf("For P[%d]", i);
    for (j = 0; j < resource; j++)
    {
      printf("\t");
      scanf("%d", &instance);
      allot[i][j] = instance;
      need[i][j] = max[i][j] - allot[i][j];
    }
  }
  printf("Safe sequence");
  while (count1 != process)
  {
    count2 = count1;
    for (i = 0; i < process; i++)
    {
      for (j = 0; j < resource; j++)
      {
        if (need[i][j] <= avail[j])
        {
          k++;
        }
      }
      if (k == resource && completed[i] == 0)
      {
        printf("P[%d]\t", i);
        completed[i] = 1;
        for (j = 0; j < resource; j++)
        {
          avail[j] = avail[j] + allot[i][j];
        }
        count1++;
      }
      k = 0;
    }
    if (count1 == count2)
    {
      printf("Stop after the deadlock");
      break;
    }
  }
}