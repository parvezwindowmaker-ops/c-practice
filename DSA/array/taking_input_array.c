#include <stdio.h>

int main(){
    int arr[5];
    size_t n = sizeof(arr)/sizeof(arr[0]);
    for (size_t i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &arr[i]);
    }

    for (size_t i = 0; i < n; i++)
    {
        if (i == 0) printf("[ ");
        printf("%d", arr[i]);
        if (i < n-1) printf(", ");
        if (i == n-1) printf(" ] \n");
    }

    return 0;
}