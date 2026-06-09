#include <stdio.h>

int main(){

    int arr[5] = {10, 5, 30, 2, 40};
    int smallest_num = arr[0];
    int second_smallest_num = arr[0];

    size_t n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if(smallest_num > arr[i]){
            second_smallest_num = smallest_num;
            smallest_num = arr[i];
        }
        // {5, 2, 3} this will not work here
        else if(arr[i] > second_smallest_num && arr[i] < smallest_num){
            second_smallest_num = arr[i];
        }
    }
    
    printf("%d \n", smallest_num);
    printf("%d \n", second_smallest_num);
    return 0;
}