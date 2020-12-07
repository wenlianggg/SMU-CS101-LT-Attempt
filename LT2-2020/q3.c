// Name: Wen Liang Goh (Audit Student)
// Email: wlgoh.2020

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DO NOT MODIFY the struct definition
typedef struct citizen {
    char *name;
    int age;
    struct citizen *next;
} citizen;
// DO NOT MODIFY the struct definition

void custom_print_queue(citizen *queue) {
    citizen *ptr = queue;
    while (ptr != NULL) {
        printf("%s(%d) -> ", ptr->name, ptr->age);
        ptr = ptr->next;
    }
    puts("NULL");
}

void insert_into_end(citizen *person, citizen **priority_queue) {
    person->next = NULL;
    printf("INSERTING INTO PRIORITY: %s(%d)\n", person->name, person->age);

    citizen *p_current = *priority_queue;
    citizen *p_previous = NULL;

    while (true) {
        if (p_current) {
            p_previous = p_current;
            p_current = p_current->next;
        } else {
            if (p_previous) {
                p_previous->next = person;
            } else {
                *priority_queue = person;
            }
            break;
        }
    }
    printf("PRIORITY NOW: ");
    custom_print_queue(*priority_queue);
}

void move_to_priority(citizen **queue, citizen **priority_queue) {
    // at end of priority now
    citizen *q_current = *queue;
    citizen *q_previous = NULL;
    while (q_current != NULL) {
        if (q_current->age >= 65) {
            if (q_previous) {
                q_previous->next = q_current->next;
                insert_into_end(q_current, priority_queue);
                q_current = q_previous->next;
            } else {
                *queue = q_current->next;
                insert_into_end(q_current, priority_queue);
                q_current = *queue;
            }
        } else {
            q_previous = q_current;
            q_current = q_current->next;
        }
        custom_print_queue(*queue);
    }
}

// DO NOT MODIFY THE CODE BELOW!
void print_queue(citizen *queue) {
    citizen *ptr = queue;
    while (ptr != NULL) {
        printf("%s -> ", ptr->name);
        ptr = ptr->next;
    }
    puts("NULL");
}

int main(void) {
    int tc_num = 1;

    {
        citizen daniel = {"daniel", 35, NULL};
        citizen charlie = {"charlie", 36, &daniel};
        citizen ben = {"ben", 25, &charlie};
        citizen adeline = {"adeline", 21, &ben};
        citizen *start = &adeline;
        citizen *priority = NULL;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :adeline -> ben -> charlie -> daniel -> NULL\n");
        printf("Expected(priority queue):NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }

    {
        citizen daniel = {"daniel", 35, NULL};
        citizen charlie = {"charlie", 66, &daniel};
        citizen ben = {"ben", 65, &charlie};
        citizen adeline = {"adeline", 21, &ben};
        citizen *start = &adeline;
        citizen *priority = NULL;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :adeline -> daniel -> NULL\n");
        printf("Expected(priority queue):ben -> charlie -> NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }

    {

        citizen elise = {"elise", 80, NULL};
        citizen daniel = {"daniel", 65, NULL};
        citizen charlie = {"charlie", 26, &daniel};
        citizen ben = {"ben", 22, &charlie};
        citizen adeline = {"adeline", 66, &ben};
        citizen *start = &adeline;
        citizen *priority = &elise;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :ben -> charlie -> NULL\n");
        printf("Expected(priority queue):elise -> adeline -> daniel -> NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }

    {
        citizen adeline = {"adeline", 66, NULL};
        citizen *start = &adeline;
        citizen *priority = NULL;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :NULL\n");
        printf("Expected(priority queue):adeline -> NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }

    {
        citizen billy = {"billy", 67, NULL};
        citizen adeline = {"adeline", 66, &billy};
        citizen *start = &adeline;
        citizen *priority = NULL;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :NULL\n");
        printf("Expected(priority queue):adeline -> billy -> NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }


    {
        citizen billy = {"billy", 17, NULL};
        citizen adeline = {"adeline", 16, &billy};
        citizen *start = &adeline;
        citizen *priority = NULL;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :adeline -> billy -> NULL\n");
        printf("Expected(priority queue):NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }



    {
        citizen *start = NULL;
        citizen adeline = {"adeline", 96, NULL};
        citizen *priority = &adeline;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :NULL\n");
        printf("Expected(priority queue):adeline -> NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }
}