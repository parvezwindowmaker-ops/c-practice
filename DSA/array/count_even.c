#include <stdio.h>

int main()
{
    int arr[4] = {10,2,30,40};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0) count++;
    }
    printf("%d", count);
    return 0;
}