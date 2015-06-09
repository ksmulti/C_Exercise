// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

void f1(int a, int b)
{
    printf("This is f1\n");
}

void print_star(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n-i; k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2*i-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void swap(char* a, char* b)
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

typedef struct Node
{
    int a;
    struct Node *next = NULL;
} node;

node *CreateNode(int a)
{
    node *N = (node*)malloc(sizeof(node));
    N->a = a;
    N->next = NULL;

    return N;
}

void Insert(struct Node *n1, struct Node *n2)
{
    n2->next = n1->next;
    n1->next = n2;
}

void Remove(struct Node *n1)
{
    free(n1->next);
    n1->next = n1->next->next;

}

void StolBubbleSort(int int_s[], int length)
{
    int tmp;
    int stop;
    for (int i = 0; i < length -1; i++)
    {
        stop = 1;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (int_s[j] > int_s[j+1])
            {
                tmp = int_s[j+1];
                int_s[j+1] = int_s[j];
                int_s[j] = tmp;
                stop = 0;
            }
        }
        if (stop == 1)
            break;
    }
}

void Reverse(char *str)
{
    int length = strlen(str);
    char tmp;
    for (int i = 0; i <= (length / 2) - 1; i++)
    {
        tmp = str[i];
        str[i] = str[length -1 - i];
        str[length -1 - i] = tmp;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    int i;
    float f;
    double d;
    char c;
    int* pi;
    float* pf;
    double* pd;
    char* pc;
    char s[] = "123";
    struct sst
    {
        int st_i;
        char st_c;
    } *pst;

    struct sst st = {5, 'a'};
    pst = &st;

    printf("i size: %d\n", sizeof(i));
    printf("f size: %d\n", sizeof(f));
    printf("d size: %d\n", sizeof(d));
    printf("c size: %d\n", sizeof(c));
    printf("pi size: %d\n", sizeof(pi));
    printf("pf size: %d\n", sizeof(pf));
    printf("pd size: %d\n", sizeof(pd));
    printf("pc size: %d\n", sizeof(pc));
    printf("s size: %d\n", sizeof(s));
    printf("st1 size: %d\n", sizeof(st));

    printf("pst : %d\n", (pst->st_i)+1);

   

    int a = 8;
    int b = 1;
    printf("a & b: %d\n", a);

    void (*pf1)(int, int);
    pf1 = &f1;
    pf1(1, 2);

    int ar[5] = { 1, 2, 3, 4, 5 };
    printf("ar: %d\n", &ar);
    printf("ar: %d\n", (int*) &ar+1);

    print_star(5);

    char aa = '9', bb = '7';
    swap(&aa, &bb);
    printf("aa: %c, bb: %c\n", aa, bb);

    node *n1 = CreateNode(1);
    node *n2 = CreateNode(2);
    Insert(n1, n2);
    printf("n1 int: %d\n", n1->a);
    printf("n2 int: %d\n", n1->next->a);

    //int iarray[10] = {6, 77, 2, 5, 3, 78, 106, 444, 3, 87};
    int iarray[] = { 5, 4, 3, 2 };
    int len = (int) sizeof(iarray) / sizeof(*iarray);
    StolBubbleSort(iarray, len);
    for (i = 0; i < len; i++)
        printf("%d ", iarray[i]);
    printf("\n");

    char mystring[] = "abcdef";
    Reverse(mystring);
    printf("mystring: %s\n", mystring);

    getchar();
	return 0;
}


