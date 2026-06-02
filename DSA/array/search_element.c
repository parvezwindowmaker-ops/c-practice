#include <stdio.h>

int main()
{
    int arr[4] = {10,2,30,40};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    int num = 30;
    for(int i = 0; i < n; i++)
    {
        if(num == arr[i]){
            printf("On Index: %d", i);
            return 0;
        }
    }
    printf("Not Found");
    return 1;
}