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

typedef struct listNode
{
    int a;
    struct listNode *next = NULL;
} ListNode;

ListNode *ListCreateNode(int a)
{
    ListNode *N = (ListNode*)malloc(sizeof(ListNode));
    N->a = a;
    N->next = NULL;

    return N;
}

void ListNodeInsert(ListNode *n1, ListNode *n2)
{
    n2->next = n1->next;
    n1->next = n2;
}

void ListNodeRemove(ListNode *n1)
{
    free(n1->next);
    n1->next = n1->next->next;
}
/*
node *ListInverse(node *start)
{
    node *tmp = NULL;
    node *n1 = NULL;
    node *n2 = NULL;
    
    n1 = start;
    n2 = start->next;
    start->next = NULL;
    while (n2 != NULL)
    {
        tmp = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = tmp;
    }
    return n1;
}
*/
ListNode *ListInverse(ListNode *start)
{
    ListNode *nextNode = NULL;
    ListNode *preNode = NULL;
    
    nextNode = start->next;
    start->next = NULL;
    preNode = start;
    start = nextNode;

    while (start != NULL)
    {
        nextNode = start->next;
        start->next = preNode;
        preNode = start;
        start = nextNode;
    }
    return preNode;
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

void StrReverse(char *str)
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

void My_strcpy(char *dest, char *source)
{
    int i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
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

    ListNode *n1 = ListCreateNode(1);
    ListNode *n2 = ListCreateNode(2);
    ListNode *n3 = ListCreateNode(3);
    ListNode *n4 = ListCreateNode(4);
    ListNodeInsert(n1, n2);
    ListNodeInsert(n2, n3);
    ListNodeInsert(n3, n4);
    ListNode *start = n1;
    int i1 = 1;
    while (start != NULL)
    {
        printf("n%d int: %d\n", i1, start->a);
        start = start->next;
        i1++;
    }
    start = ListInverse(n1);
    while (start != NULL)
    {
        printf("n%d int: %d\n", i1, start->a);
        start = start->next;
        i1++;
    }


    //int iarray[10] = {6, 77, 2, 5, 3, 78, 106, 444, 3, 87};
    int iarray[] = { 5, 4, 3, 2 };
    int len = (int) sizeof(iarray) / sizeof(*iarray);
    StolBubbleSort(iarray, len);
    for (i = 0; i < len; i++)
        printf("%d ", iarray[i]);
    printf("\n");

    char mystring[] = "abcdef";
    StrReverse(mystring);
    printf("mystring reverse: %s\n", mystring);

    char mystring2[100];
    My_strcpy(mystring2, mystring);
    printf("My_strcpy mystring2 : %s\n", mystring2);

    int twodIntarray[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    int *iptr = &twodIntarray[0][1];
    printf("%d\n", iptr[2]);


    getchar();
	return 0;
}


