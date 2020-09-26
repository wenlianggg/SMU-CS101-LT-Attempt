/*
 * Name : Wen Liang
 * Email: wlgoh.2020
 */

#include <stdio.h>
#include <stdlib.h>

// write your answer below
int sum_of_neighbours(int arr[], int n){
    int temp_arr[n];
    for (int i = 0; i < n; i++) {
        temp_arr[i] = arr[i];
        if (i < n - 1) {
            temp_arr[i] += arr[i + 1];
        }
        if (i != 0) {
            temp_arr[i] += arr[i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] = temp_arr[i];
    }
    return 0;
}

// do not edit the main method.
int main_q1(void) {
    int test_num = 1;

    {
        int arr[] = {1};
        int n = sizeof(arr) / sizeof(int);
        sum_of_neighbours(arr, n);
        printf("Test %d\n", test_num++);
        printf("Expected:1\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    {
        int arr[] = {1, 2};
        int n = sizeof(arr) / sizeof(int);
        sum_of_neighbours(arr, n);
        printf("Test %d\n", test_num++);
        printf("Expected:3 3\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    {
        int arr[] = {1, 2, 3};
        int n = sizeof(arr) / sizeof(int);
        sum_of_neighbours(arr, n);
        printf("Test %d\n", test_num++);
        printf("Expected:3 6 5\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    {
        int arr[] = {10, 20, 30, 40, 50};
        int n = sizeof(arr) / sizeof(int);
        sum_of_neighbours(arr, n);
        printf("Test %d\n", test_num++);
        printf("Expected:30 60 90 120 90\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    return 0;
}