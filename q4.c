/*
 * Name : Wen Liang
 * Email: wlgoh.2020
 */

#include <stdio.h>
#include <stdbool.h>

// write your answer below
int sum_of_digits_squared(int num) {
    int sum = 0;
    while (num > 0) {
        int last_digit = num % 10;
        sum += (last_digit * last_digit);
        num /= 10;
    }
    return sum;
}

bool is_infinite_number(int num) {
    while (num != 1) {
        int ans = sum_of_digits_squared(num);
        if (ans == 4) {
            return true;
        }
        num = ans;
    }
    return false;
}


// do not edit the main method.
int main_q4(void) {
    int tc_num = 1;

    {
        printf("Test %d\n", tc_num++);
        bool result = is_infinite_number(1);
        printf("Expected:false\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        bool result = is_infinite_number(2);
        printf("Expected:true\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        bool result = is_infinite_number(144);
        printf("Expected:true\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    return 0;
}