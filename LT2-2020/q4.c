// Name: Wen Liang Goh (Audit Student)
// Email: wlgoh.2020

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *get_variable(char *variables[], char* variable, int n) {
    for (int i = 0; i < n; i += 2) {
        if (strcmp(variables[i], variable) == 0) {
            return variables[i+1]; 
        }
    }
    return "{NF}";
}

char *merge(char template[], char *variables[], int n) {
    char *result = calloc(sizeof(char), 500);
    char *varname = calloc(sizeof(char), 100);
    int BRACKET_LEVEL = 0;

    for (int i = 0; i < strlen(template); i++) {
        switch (template[i]) {
            case '{':
                BRACKET_LEVEL++;
                break;
            case '}':
                BRACKET_LEVEL--;
                if (BRACKET_LEVEL == 0) {
                    char *toInsert = get_variable(variables, varname, n);
                    sprintf(result, "%s%s", result, toInsert);
                    free(varname);
                    varname = calloc(sizeof(char), 100);
                }   
                break;
            default:
                if (BRACKET_LEVEL == 0) {
                    sprintf(result, "%s%c", result, template[i]);
                } else if (BRACKET_LEVEL == 1) {
                    sprintf(varname, "%s%c", varname, template[i]);
                } else {
                    return "ERROR!!!";
                }
        }
    }
    return result;
}

// DO NOT MODIFY THE CODE BELOW!

int main(void) {
    int tc_num = 1;
    {
        char *variables[] = {"var1", "apple", "var2", "orange"};
        char *result = merge("{var1}-{var2}", variables, sizeof(variables)/sizeof(char *));
        printf("Test Case %d\n", tc_num++);
        printf("Expected:apple-orange\n");
        printf("Actual  :%s\n", result);
        free(result);
        printf("\n");
    }
    
    {
        char *variables[] = {"var1", "apple", "var2", "orange"};
        char *result = merge("{var1}{var2}{var1}{var2}", variables, sizeof(variables)/sizeof(char *));
        printf("Test Case %d\n", tc_num++);
        printf("Expected:appleorangeappleorange\n");
        printf("Actual  :%s\n", result);
        free(result);
        printf("\n");
    }

    {
        char *variables[] = {"name", "apple", "temperature", "37.5"};
        char *result = merge("Good morning, {name}! Your temperature is {temperature}", variables, sizeof(variables)/sizeof(char *));
        printf("Test Case %d\n", tc_num++);
        printf("Expected:Good morning, apple! Your temperature is 37.5\n");
        printf("Actual  :%s\n", result);
        free(result);
        printf("\n");
    }
}
