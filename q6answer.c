/*
 * Name : Wen Liang (audit student)
 * Email: wlgoh.2020
 */

#include <stdio.h>

// write your answer below
int get_crowd_size(int timings[], int n) {
    int max_crowd = 0;
    for (int time = 0; time < 2301; time += 100) {
        int hour_crowd = 0;

        for (int i = 0; i < n; i += 2) {
            int in = timings[i];
            int out = timings[i+1];
            if (in <= time && time < out) {
                hour_crowd++;
            }
        }
        max_crowd = (hour_crowd > max_crowd) ? hour_crowd : max_crowd;
    }
    return max_crowd;
}