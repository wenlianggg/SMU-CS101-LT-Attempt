// Name: Wen Liang Goh (Audit Student)
// Email: wlgoh.2020
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Process each line from a left to right manner
void process(int n, int *input, int *output) {
    int seed = 0;
    for (int outpos = 0; outpos < n && seed < n; outpos++, seed++) {

        int offset = 1;
        int a = input[seed];
        int b = input[seed + 1];

        while (a == 0 && seed < n) {
            seed++;
            a = input[seed];
            b = input[seed + 1];
        }

        while (b == 0 && seed + offset < n) {
            offset++;
            b = input[seed + offset];
        }

        if (a == b && a != 0 && seed + offset < n) {
            output[outpos] = a * 2;
            seed += offset;
        } else if (seed < n) {
            output[outpos] = a;
        }
    }
}

// Convert then copy each direction into a single array for the process function
// Then copy back to the original location
void move(int n, int board[n][n], char direction[]) {
    int *input = NULL;
    int *output = NULL;
    
    if (strcmp(direction, "up") == 0) {
        for (int colidx = 0; colidx < n; colidx++) {
            input = calloc(sizeof(int), n);
            output = calloc(sizeof(int), n);
            for (int i = 0; i < n; i++) {
                input[i] = board[i][colidx];
            }
            process(n, input, output);
            for (int i = 0; i < n; i++) {
                board[i][colidx] = output[i];
            }
        }
    } else if (strcmp(direction, "down") == 0) {
        for (int colidx = 0; colidx < n; colidx++) {
            input = calloc(sizeof(int), n);
            output = calloc(sizeof(int), n);
            for (int i = 0; i < n; i++) {
                input[i] = board[n-i-1][colidx];
            }
            process(n, input, output);
            for (int i = 0; i < n; i++) {
                board[n-i-1][colidx] = output[i];
            }
        }
    } else if (strcmp(direction, "left") == 0) {
        for (int rowidx = 0; rowidx < n; rowidx++) {
            input = calloc(sizeof(int), n);
            output = calloc(sizeof(int), n);
            for (int i = 0; i < n; i++) {
                input[i] = board[rowidx][i];
            }
            process(n, input, output);
            for (int i = 0; i < n; i++) {
                board[rowidx][i] = output[i];
            }
        }
    } else if (strcmp(direction, "right") == 0) {
        for (int rowidx = 0; rowidx < n; rowidx++) {
            input = calloc(sizeof(int), n);
            output = calloc(sizeof(int), n);
            for (int i = 0; i < n; i++) {
                input[i] = board[rowidx][n-i-1];
            }
            process(n, input, output);
            for (int i = 0; i < n; i++) {
                board[rowidx][n-i-1] = output[i];
            }
        }
    }
    free(input);
    free(output);
}

// DO NOT MODIFY THE CODE BELOW!
void print_board(int n, int board[n][n]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int tc_num = 1;
    {
        // no possible move
        int board[][4] = {
            {4, 2, 6, 8},
            {4, 2, 6, 8},
            {4, 2, 4, 2},
            {4, 2, 4, 2}};
        int n = 4;
        move(n, board, "left");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("4 2 6 8\n");
        printf("4 2 6 8\n");
        printf("4 2 4 2\n");
        printf("4 2 4 2\n");
        printf("Actual:\n");
        print_board(n, board);
        printf("\n");
    }

    {
        int board[][4] = {
            {2, 0, 2, 0},
            {2, 0, 0, 0},
            {4, 2, 2, 2},
            {2, 4, 2, 2}};
        int n = 4;
        move(n, board, "right");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("0 0 0 4\n");
        printf("0 0 0 2\n");
        printf("0 4 2 4\n");
        printf("0 2 4 4\n");
        printf("Actual:\n");
        print_board(n, board);
        printf("\n");
    }

    {
        int board[][4] = {
            {2, 0, 2, 0},
            {2, 0, 0, 0},
            {4, 2, 2, 2},
            {2, 4, 2, 2}};
        int n = 4;
        move(n, board, "left");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("4 0 0 0\n");
        printf("2 0 0 0\n");
        printf("4 4 2 0\n");
        printf("2 4 4 0\n");
        printf("Actual:\n");
        print_board(n, board);
        printf("\n");
    }

        {
        int board[][4] = {
            {2, 0, 2, 0},
            {2, 0, 0, 0},
            {4, 2, 2, 2},
            {2, 4, 2, 2}};
        int n = 4;
        move(n, board, "up");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("4 2 4 4\n");
        printf("4 4 2 0\n");
        printf("2 0 0 0\n");
        printf("0 0 0 0\n");
        printf("Actual:\n");
        print_board(n, board);
        printf("\n");
    }

    
        {
        int board[][4] = {
            {2, 0, 2, 0},
            {2, 0, 0, 0},
            {4, 2, 2, 2},
            {2, 4, 2, 2}};
        int n = 4;
        move(n, board, "down");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("0 0 0 0\n");
        printf("4 0 0 0\n");
        printf("4 2 2 0\n");
        printf("2 4 4 4\n");
        printf("Actual:\n");
        print_board(n, board);
        printf("\n");
    }

}