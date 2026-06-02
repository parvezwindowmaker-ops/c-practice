#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5] = {10,20,30,40};

    // cause int is 4 bytes
    int length = sizeof(arr) / sizeof(arr[0]) ;
    arr[5] = 50;
    // you wrote to memory that doesn't belong to the array and then immediately read from the same location. On your system, 
    // that memory happened to be writable and still contained 50, so it printed:
    printf("%d \n", arr[5]);
    for(int i = 0; i < length; i++)
    {
        // Used internally: Address(arr[i])=Base+i×Size
        printf("%d \n", arr[i]);
    }
    return 0;
}