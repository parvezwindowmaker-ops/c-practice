#include <stdio.h>

int main()
{
    int arr[4] = {100,2,30,40};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    int smallest_num = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < smallest_num) smallest_num = arr[i];
    }
    printf("%d", smallest_num);
    return 0;
}