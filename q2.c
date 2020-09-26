/*
 * Name : Wen Liang
 * Email: wlgoh.2020
 */

#include <stdio.h>

// write your answer below
void move_robot(int position[], char moves[], int n) {
    int num_moves = 1;
    for (int i = 0; i < n; i++) {
        int move = moves[i];
        if (move >= '0' && move <= '9') {
            num_moves = move - '0';
        }
        switch(move) {
            case 'N':
                position[1] += num_moves;
                num_moves = 1;
                break;
            case 'S':
                position[1] -= num_moves;
                num_moves = 1;
                break;
            case 'E':
                position[0] += num_moves;
                num_moves = 1;
                break;
            case 'W':
                position[0] -= num_moves;
                num_moves = 1;
                break;
        }
    }
}

// do not edit the main method.
int main_q2(void) {
    int tc_num = 1;
    {
        printf("Test %d\n", tc_num++);
        char moves[] = {'N', 'N', 'N', 'S', 'S'};
        int position[] = {0, 0};
        move_robot(position, moves, sizeof(moves) / sizeof(char));
        printf("Expected:(0,1)\n");
        printf("Actual  :(%d,%d)\n", position[0], position[1]);
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        char moves[] = {'N', 'E', 'W', 'S', 'N', 'E', 'W', 'S'};
        int position[] = {1, 1};
        move_robot(position, moves, sizeof(moves) / sizeof(char));
        printf("Expected:(1,1)\n");
        printf("Actual  :(%d,%d)\n", position[0], position[1]);
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        char moves[] = {'5', 'N', 'E', 'E'};
        int position[] = {3, 1};
        move_robot(position, moves, sizeof(moves) / sizeof(char));
        printf("Expected:(5,6)\n");
        printf("Actual  :(%d,%d)\n", position[0], position[1]);
        printf("\n");
    }

    {
        char moves[] = {'N', 'N', 'N', 'S', 'S'};
        int position[] = {0, 0};
        move_robot(position, moves, sizeof(moves) / sizeof(char));
        printf("Test %d\n", tc_num++);
        printf("Expected:(0,1)\n");
        printf("Actual  :(%d,%d)\n", position[0], position[1]);
        printf("\n");
    }

    {
        char moves[] = {'3', 'N', 'S', 'E', 'E', '2', 'E'};
        int position[] = {1, 5};
        move_robot(position, moves, sizeof(moves) / sizeof(char));
        printf("Test %d\n", tc_num++);
        printf("Expected:(5,7)\n");
        printf("Actual  :(%d,%d)\n", position[0], position[1]);
        printf("\n");
    }

    return 0;
}