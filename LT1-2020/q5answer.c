/*
 * Name : Wen Liang
 * Email: wlgoh.2020
 */

#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool is_leap_year(int year);
int days_in_month(int month, int year);
int days_in_year(int year);
int days_since_start(int d, int m, int y);

// Actual logic
int num_days_between(int d1, int m1, int y1, int d2, int m2, int y2) {
    int days1 = days_since_start(d1, m1, y1);
    int days2 = days_since_start(d2, m2, y2);
    int diff = days1 - days2;
    if (diff < 0) {
        diff -=1;
    }
    return diff;
}


// Utility functions
bool is_leap_year(int year) {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    if (year % 4 == 0) {
        return true;
    }
    return false;
}

int days_in_month(int month, int year) {
    switch(month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return 29;
    }
    return -10000;
}

int days_in_year(int year) {
    if (is_leap_year(year)) {
        return 366;
    }
    return 365;
}

int days_since_start(int d, int m, int y) {
    int dayssince1970 = 1;
    while (y > 1970) {
        y--;
        dayssince1970 += days_in_year(y);
    }
    while (m > 1) {
        m--;
        dayssince1970 += days_in_month(m, y);
    }
    while (d > 1) {
        d--;
        dayssince1970++;
    }
    return dayssince1970;
}

