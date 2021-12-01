#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
pthread_t tid[5];
int count1;
void *thread1(void *arg)
{
    char str[8], rev[8];
    strcpy(str, arg);
    //strcpy(str,strrev(arg));
    int i = 0;
    char ch;
    int count = 0;
    for (i = strlen(str) - 1; i >= 0; i--)
    {
        ch = str[i];
        rev[count] = ch;
        count++;
    }
    rev[count] = '\0';
    if (strcmp(str, rev) == 0)
    {
        printf("%s is a palindrome\n", str);
        count1++;
    }
    printf(" %s ", rev);
    pthread_exit(0);
}
int main(int argc, char *argv[])
{
    int i;
    pthread_attr_t attr;
    //printf("%d",argc);
    if (argc < 2)
    {
        printf("More arguments");
        exit(0);
    }
    char str1[8];
    char str2[8];
    char str3[8];
    char str4[8];
    char str5[8];
    printf("Into copies\n\n");
    //strcpy(argv[5],"end");
    printf("Into copies2\n\n");
    strcpy(str1, argv[1]);
    strcpy(str2, argv[2]);
    strcpy(str3, argv[3]);
    if (argc == 4)
        strcpy(str4, "end");
    else
        strcpy(str4, argv[4]);
    if (argc <= 5)
        strcpy(str5, "end");
    else
        strcpy(str5, argv[5]);
    pthread_attr_init(&attr);
    pthread_create(&tid[0], NULL, thread1, str1);
    //printf("\n\ncreated first process\n\n");
    pthread_create(&tid[1], NULL, thread1, str2);
    //printf("\n\ncreated second process\n\n");
    pthread_create(&tid[2], NULL, thread1, str3);
    pthread_create(&tid[3], NULL, thread1, str4);
    pthread_create(&tid[4], NULL, thread1, str5);
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
    pthread_join(tid[4], NULL);
    printf("\nThe number of palindromes = %d", count1);
}