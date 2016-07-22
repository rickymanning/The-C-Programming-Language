/* 3.1 binsearch(), page 58 */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int x, n;
    x = 5;
    n = 10;

    int v[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("%d\n", binsearch(x, v, n));
}

/* binsearch: find x in v[0] <= v[1] <= ...  v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1;  /* no match */
}
