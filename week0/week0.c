#include <stdio.h>
int main()
{

    int n, t;
    printf("enter no.of test cases");
    scanf("%d", &t);
    while (t--)
    {

        printf("Enter number of elements in array\n");
        scanf("%d", &n);

        int a[n], k, i;

        printf("Enter the elements of an array");

        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);

        printf("Enter a number to check\n");
        scanf("%d", &k);

        for (i = 0; i < n; i++)
        {
            if (a[i] == k)
            {
                printf("%d is present at location %d.\n", k, i + 1);
                break;
            }
        }
        if (i == n)
            printf("%d isn't present in the array.\n", k);
    }
    return 0;
}