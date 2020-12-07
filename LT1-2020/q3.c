/*
 * Name : Wen Liang
 * Email: wlgoh.2020
 */

#include <stdio.h>
#include <math.h>

// write your answer below
int extract(int num, int start, int end) {
    int ncopy = num;
    int extracted = 0;
    int digits = 0;
    int exponent = 0;
    while (ncopy > 0) {
        digits++;
        ncopy /= 10;
    }
    while (num > 0) {
        digits--;
        if (digits >= start && digits < end) {
            int currdigit = num % 10;
            extracted += (currdigit * pow(10, exponent));
            exponent++;
        }
        num /= 10;
    }
    return extracted;
}


// do not edit the main method.
int main_q3(void) {
    int tc_num = 1;

    {
        printf("Test %d\n", tc_num++);
        int x = 123456; 
        int result = extract(x, 1, 3);
        printf("Expected:23\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        int x = 374512; 
        int result = extract(x, 3, 4);
        printf("Expected:5\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        int x = 374512; 
        int result = extract(x, 3, 8);
        printf("Expected:512\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        int x = 1; 
        int result = extract(x, 0, 1);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }


    {
        printf("Test %d\n", tc_num++);
        int x = 11; 
        int result = extract(x, 0, 1);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    return 0;
}