//remaining
#include <stdio.h>

int main()
{
    int arr[5] = {100,2,30,40,10};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    int largest_num = arr[0];
    int second_largest_num = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > largest_num) largest_num = arr[i];
        if(arr[i] < largest_num && arr[i+1] < second_largest_num) second_largest_num = arr[i];
    }
    printf("%d", second_largest_num);
    return 0;
}