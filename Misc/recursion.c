// Recursion Programs
// Recursion is one fascinating topic and it can be used extensively in competitive programming, But in production it has to be used carefully because a silly mistake can make the loop to run indefinite times thus making the memory wastage and also incareasing server run cost time.
// Down below are some examples of recursion, do you know that we can print array using recursion, I didn't :)

// Examples I liked:
// Printing a array using recursion
// what happens here is we are inputting 3 paramenters namely array, i, and n.
// where array is the array we are printing, i is the index of the array and n is the size of the array.
// condition inside the function is that if i == n (index == size) the recursion must stop and for each recurssion call we are increasing the index by 1

#include <stdio.h>

void tower(int n, char s, char t, char d)
{
    if (n == 0)
    {
        printf("no movement required!!\n");
    }
    else if (n == 1)
    {
        printf("move ring %d from %c to %c\n", n, s, d);
    }
    else
    {

        tower(n - 1, s, d, t);
        printf("move ring %d from %c to %c\n", n, s, d);
        tower(n - 1, t, s, d);
    }
}

void display(int a[], int i, int n)
{
    if (i != n)
    {
        printf("%d\t", i);
        display(a, i + 1, n);
    }
}

// binary search using recursion

void binary_search(int a[], int n, int key)
{
    int mid = n / 2;
    if (n == 0)
    {
        printf("key not found\n");
    }
    else if (a[mid] == key)
    {
        printf("key found at %d\n", mid + 1);
    }
    else if (a[mid] > key)
    {
        binary_search(a, mid, key);
    }
    else
    {
        binary_search(a + mid + 1, n - mid - 1, key);
    }
}

void reversed(int a[], int i, int n)
{
    if (i != n)
    {
        reversed(a, i + 1, n);
        printf("%d\t", a[i]);
    }
}

void reverseNumber(int num, int reverse)
{
    if (num != 0)
    {
        int rem = num % 10;
        reverse = reverse * 10 + rem;
        num = num / 10;
        reverseNumber(num, reverse);
    }
    else
    {
        printf("%d\n", reverse);
    }
}
void factorial(int n)
{
    if (n != 1)
        printf() n * factorial(n - 1);
}
void arr_sum(int arr[], int n)
{

    if (n < 0)
    {
        return 0;
    }

    return arr[n] + arr_sum(arr, --n);
}
int main()
{
    int reverse = 0;
    int a[5] = {
        1, 2, 3, 4, 5};
    int i = 0;
    int n = 4;
    int *ptr = NULL;
    ptr = &n;
    tower(*ptr, 'a', 'b', 'c');
    display(a, i, n);
    binary_search(a, n, 1);
    reversed(a, i, n);
    reverseNumber(12345, 0);
    factorial(5);
    arr_sum(a, n);
}
