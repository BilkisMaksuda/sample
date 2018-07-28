#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

void print();
void clear_screen(void);
void view(int n,int A[]);
void insert(int n, int A[]);
void search(int n,int A[]);
void deletee(int n, int A[]);
void sort(int n,int A[]);
void sort1(int n,int A[]);
void FindingLocation(int n, int A[]);
void operation();

int main()
{
    int n,i,x;
    printf("Enter the size of n :");
    scanf("%d", &n);
    int *A = (int*)malloc(MAX * sizeof(int));
    //dynamically memory allocation
    if(A == 0)
        printf("unable to allocate memory");


    printf("Enter array elements :");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    while(1)
    {
        print();
        printf("\n\nplease enter a number from above : ");
        scanf("%d",&x);
        operation(A,x,n);
        clear_screen();

    }

    return 0;
}

void print()
{
    printf("\n\nfollow the following guidelines:\n");
    printf("0.Exit\n");
    printf("1.View all elements\n");
    printf("2.Insert new element\n");
    printf("3.Search an element\n");
    printf("4.Delete an element (user should input item to be searched and delete)\n");
    printf("5.Sort elements in ascending order\n");
    printf("6.Sort elements in descending order\n");
    printf("7.Find memory location of an element (user should input index number).\n") ;
}


void view(int n,int A[])
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf( "%d    ", A[i]);
    }
}


void insert(int n, int A[])
{
    int a,i,l;
    printf("Enter a location where you want to insert a value :");
    scanf("%d", &l);
    printf("Enter a number for inserting :");
    scanf("%d", &a);
    for(i = n; i >= l; i--)
    {
        A[i+1] = A[i];
    }
    A[l] = a;
    printf("final array :");
    for(i = 0; i < n + 1; i++)
    {
        printf("%d  ", A[i]);
    }
}


void search(int n,int A[])

{
    int s,i, L = 0;
    printf("Enter a element for searching :");
    scanf("%d", &s);
    for( i = 1; i <= n; i++)
    {
        if(s == A[i])
        {
            L = i;
        }
    }

    if ( L == 0)
        printf("Item is not in the array");
    else
        printf("Item found and location = %d\n", L);
}


void deletee(int n, int A[])
{
    int d,l, i;
    printf("Enter a location where you want to delete a value :");
    scanf("%d", &l);
    if(l > n)
        printf("Deletion is not possible\n");
    else
    {
        for(i = l; i <= n-1; i++)
        {
            A[i] = A[i+1];
        }

        printf("Final array :");
        for(i = 0; i < n-1; i++)
        {
            printf("%d  ", A[i]);
        }
        printf("\n");
    }
}

void sort(int n,int A[])
{
    int i,j,t;
    for (i = 0 ; i < n - 1; i++)
    {
        for (j = 0 ; j < n - i - 1; j++)
        {
            if (A[j] > A[j+1])
            {
                t= A[j];
                A[j]= A[j+1];
                A[j+1] = t;
            }
        }
    }
    printf("The numbers arranged in ascending order :\n");
    for(i = 0; i < n; i++)
        printf("%d  ",A[i]);
}

void sort1(int n,int A[])
{
    int i,j,t;
    for (i = 0 ; i < n - 1; i++)
    {
        for (j = 0 ; j < n - i - 1; j++)
        {
            if (A[j] < A[j+1])
            {
                t= A[j];
                A[j]= A[j+1];
                A[j+1] = t;
            }
        }
    }
    printf("The numbers arranged in descending order :\n");
    for(i = 0; i < n; i++)
        printf("%d  ",A[i]);
}
void FindingLocation(int n, int A[])
{
    unsigned int base,l;
    int m,s;
    base = &A[0];
    printf("base address = %u\n", base);
    printf("Enter the index number to find memory location :");
    scanf("%d", &m);
    if(m < 0 || m > n)
        printf("ERROR ! No such index is present. ");
    else
    {
        s = sizeof(int);
        printf("byte size = %d\n", s);
        l= base + s*(m - 1);
        printf("The memory location of index %d is = %u", m,l);
    }

}


void clear_screen(void)
{
    printf("\n\npress any key to clear the screen  : ");
    getch();
    system("cls");
}
void operation(int A[],int x,int n)
{


    if(x < 0 || x > 7)
        printf("invalid keyword");
    else
    {
        if(x == 0)
            exit(0);
        else if (x == 1)
            view(n,A);
        else if(x == 2)
            insert(n,A);
        else if(x == 3  )
            search(n,A);
        else if (x == 4)
            deletee(n,A);
        else if(x == 5)
            sort(n,A);
        else if(x == 6)
            sort1(n,A);
        else if(x == 7)
            FindingLocation(n,A);

    }
}





