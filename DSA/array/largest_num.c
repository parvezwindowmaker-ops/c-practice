#include <stdio.h>

int main()
{
    int arr[4] = {100,2,30,40};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    int largest_num = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > largest_num) largest_num = arr[i];
    }
    printf("%d", largest_num);
    return 0;
}