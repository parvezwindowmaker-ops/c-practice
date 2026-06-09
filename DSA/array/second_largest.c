//remaining
#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    int largest_num = arr[0];
    int second_largest_num = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > largest_num) largest_num = arr[i];
        if(arr[i] < largest_num && arr[i] > second_largest_num){
            second_largest_num = arr[i];
        } 
    }
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < largest_num && arr[i] > second_largest_num){
            second_largest_num = arr[i];
        } 
    }
    
    printf("Largest : %d \n", largest_num);
    printf("Second: %d \n", second_largest_num);
    return 0;
}

// for (int i = 1; i < n; i++) {
//     if (arr[i] > largest_num) {
//         second_largest_num = largest_num;
//         largest_num = arr[i];
//     }
//     else if (arr[i] > second_largest_num) {
//         second_largest_num = arr[i];
//     }
// }