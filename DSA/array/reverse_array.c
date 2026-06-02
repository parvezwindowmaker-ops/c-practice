#include <stdio.h>

int main()
{
    int arr[4] = {10,2,30,40};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    for(int i = n; i > 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // correct one 
    for(int i = n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}