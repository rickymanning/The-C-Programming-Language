/* 3-1 Our binary search makes two tests inside the loop, when one would 
suffice (at the price of more tests outside). Write a version with only one 
test inside the loop and measure the difference in run-time, page 58 */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int x, n, i;
    x = 5;
    n = 10;

    int v[10] = {1,2,3,4,5,6,7,8,9,10};
    
    printf("%d\n", binsearch(x, v, n));
}

/* binsearch: find x in v[0] <= v[1] <= ...  v[n-1] (my version) */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low+high+1) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid;
    }
    return (x == v[low]) ? low : -1;  /* no match */
}
