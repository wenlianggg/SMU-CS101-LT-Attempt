// Name :
// Email:

#include <string.h>
#include <stdio.h>

int percent(char votes[], char candidate) {
    int v_for_candidate = 0;
    int total_candidate = 0;
    
    while(*votes != 0) {
        if (*votes == candidate) {
            v_for_candidate++;
        }
        total_candidate++;
        votes++;
    }

    int percentage = (total_candidate == 0) ? 0 : (v_for_candidate * 100 / total_candidate);
    return percentage;
}

// DO NOT MODIFY THE CODE BELOW!
int main(void) {
    int tc_num = 1;
    {
        char *votes = "BBBTTBBBTT";
        int result = percent(votes, 'T');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:40\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }   

    {
        char *votes = "BBBTTBBBTT";
        int result = percent(votes, 'B');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:60\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    } 

    {
        char *votes = "BBBT";
        int result = percent(votes, 'B');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:75\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        char *votes = "";
        int result = percent(votes, 'A');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        char *votes = "CDDDDDD";
        int result = percent(votes, 'C');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:14\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        char *votes = "CBD";
        int result = percent(votes, 'A');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        char *votes = "A";
        int result = percent(votes, 'A');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:100\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

}