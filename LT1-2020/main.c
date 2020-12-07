/*
 * Name : Wen Liang (audit student)
 * Email: wlgoh.2020
 */

#include "all_headers.h" // to work with repl.it

int main(void) {
    // Please refer to the respective files on the sidebar
    puts("--- QUESTION 1 ---");
    main_q1();
    /* 
    1. Create a second empty array of the same size
    2. Loop through each element of the new array
    2a. Add the original array's values
    2b. If not first item in array, add previous value [i - 1]
    2c. If not last item in array, add next value [i + 1]
    */

    puts("--- QUESTION 2 ---");
    main_q2();
    /*
    1. Set movement increment to 1 (default)
    2. Go through each element of array
    3a. Element is number? Set movement increment to that number
    3b1. Element is direction? Move in that direction by increment value
    3b2. - Reset the movement increment to 0
    */

    puts("--- QUESTION 3 ---");
    main_q3();
    /*
    1. Count the number of digits
    2. Count back downwards
    2a. If the digit is within start/end, add to extracted and exponent
    */

    puts("--- QUESTION 4 ---");
    main_q4();
    /*
    1. Have a function to calculate the sum of every digit squared
    2. Repeatedly use that function, until ending up with a 4 or 1
    */

    puts("--- QUESTION 5 ---");
    main_q5();
    /*
    1. Get the days difference between 1 Jan 1970 for each date
    2. Get the difference between the days difference in the earlier step
    */

    puts("--- QUESTION 6 ---");
    /*
    1. Using nested for loop
    2. Cycle through every hour from 000 to 2300 (increment of 100)
    2a. Get the in and out timing pairs and check if the hour overlaps
    2b. This will calculate the crowd number per hour
    3. If more than max, set max value to that amount.
    */
    main_q6();
}