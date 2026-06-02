#include <stdio.h>

int main()
{
    int arr[4] = {10,2,30,40};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    printf("%d / %d = ", sum, n);
    double average = (double)sum / n;  
    printf("%.2f", average);
    return 0;
}