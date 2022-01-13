//Write a C program to implement Hashing using Linear probing.
//Implement insertion, deletion, search and display
#include <stdio.h>
#define max 10

int hash(int HT[], int key)
{
  return (key % max);
}

void display(int HT[])
{
  int i;
  printf("HASH TABLE : \n");
  for (i = 0; i < max; i++)
    printf("\n%d->%d", i, HT[i]);
}

void insert_LinerProbing(int HT[], int key)
{
  int index, i;
  index = hash(HT, key);
  if (HT[index] == -1)

  {
    HT[index] = key;
    printf("\nSuccesful Insertion");
    return;
  }

  // Linerly serach for the array  index+1 to max-1  or 0 to index-1
  for (i = index + 1; i < max; i++)
  {
    if (HT[i] == -1)
    {
      HT[i] = key;
      printf("\nSuccesful Insertion");
      return;
    }
  }

  for (i = 0; i < index; i++)
  {
    if (HT[i] == -1)
    {
      HT[i] = key;
      printf("\nSuccesful Insertion");
      return;
    }
  }

  printf("\nUnsuccessful Insertion : Hash Table is FULL");
}
void Delete_LinerProbing(int HT[], int key)
{
  int index, i;
  index = hash(HT, key);
  if (HT[index] == key)
  {
    HT[index] = -1;
    printf("\nSuccesful Deletion");
    return;
  }

  // Linerly serach for the array  index+1 to max-1  or 0 to index-1
  for (i = index + 1; i < max; i++)
  {
    if (HT[i] == key)
    {
      HT[i] = -1;
      printf("\nSuccesful Deletion");
      return;
    }
  }

  for (i = 0; i < index; i++)
  {
    if (HT[i] == key)
    {
      HT[i] = -1;
      printf("\nSuccesful Deletion");
      return;
    }
  }

  printf("\nUnsuccessful Deletion: Key Not Found");
}
void Search_LinerProbing(int HT[], int key)
{
  int index, i;
  index = hash(HT, key);
  if (HT[index] == key)
  {

    printf("\nSuccesful Search");
    return;
  }

  // Linerly serach for the array  index+1 to max-1  or 0 to index-1
  for (i = index + 1; i < max; i++)
  {
    if (HT[i] == key)
    {

      printf("\nSuccesful Search");
      return;
    }
  }

  for (i = 0; i < index; i++)
  {
    if (HT[i] == key)
    {

      printf("\nSuccesful Search");
      return;
    }
  }

  printf("\nUnsuccessful Search: Key Not Found");
}
void main()
{
  int HT[max]; // hash table
  int key, i, choice;

  printf("\n hash table\n");
  for (i = 0; i < max; i++)
    HT[i] = -1;

  while (1)
  {
    printf("\nEnter the choice \n1 : insert \n2 : delete\n3 : display\n 4 : display\n 5 : exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("\nEnter the key to be inerted  :");
      scanf("%d", &key);
      insert_LinerProbing(HT, key);
      break;
    case 2:
      printf("\nEnter the key to be deleted  :");
      scanf("%d", &key);
      Delete_LinerProbing(HT, key);
      break;
    case 3:
      printf("\nEnter the key to be Searched  :");
      scanf("%d", &key);
      Search_LinerProbing(HT, key);
      break;
    case 4:
      display(HT);
      break;
    default:
      exit(0);
    }
  }
}
