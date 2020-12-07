// Name :
// Email:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stutter(char word[], int n, char sep[]) {
    int length = (strlen(word) * n) + (strlen(sep) * n-1) + 1;
    char* answer = calloc(sizeof(char), length);
    int position = 0;

    while (*word != '\0') {
        for (int j = 0; j < n; j++) {
            answer[position++] = *word;
        }

        word++;

        for (int k = 0; k < strlen(sep) && *word != '\0'; k++) {
            answer[position++] = sep[k];
        }
    }

    return answer;
}

// DO NOT MODIFY THE CODE BELOW!

int main(void) {

    int tc_num = 1;
    {
        char *answer = stutter("abc", 1, "#");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:a#b#c\n");
        printf("Actual  :%s\n", answer);
        printf("\n");
        free(answer);
    }

    {
        char *answer = stutter("happy", 5, "");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:hhhhhaaaaappppppppppyyyyy\n");
        printf("Actual  :%s\n", answer);
        printf("\n");
        free(answer);
    }

    {
        char *answer = stutter("happy", 2, "|");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:hh|aa|pp|pp|yy\n");
        printf("Actual  :%s\n", answer);
        printf("\n");
        free(answer);
    }

    {
        char *answer = stutter("happy", 3, "**");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:hhh**aaa**ppp**ppp**yyy\n");
        printf("Actual  :%s\n", answer);
        printf("\n");
        free(answer);
    }

    {
        char *answer = stutter("A", 5, "[###]");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:AAAAA\n");
        printf("Actual  :%s\n", answer);
        printf("\n");
        free(answer);
    }

    {
        char *answer = stutter("", 2, "%%%%%");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:[]\n");
        printf("Actual  :[%s]\n", answer);
        printf("\n");
        free(answer);
    }
}