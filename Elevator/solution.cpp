#include <iostream>
#include <vector>
#include "solution.h"
#include "helpers.h" 

int Solution::solution(int *A, int *B, int M, int X, int Y, size_t N){
    // each array has a head ptr and tail ptr
    int *A_head = A; 
    int *A_tail = A; 
    int *B_head = B; 
    int *B_tail = B; 
    int *A_end = A + N - 1;
    // moving along the array until tail is the end()
    int stops {0};
    int i{0};
    // do-while to deal with corner case (1 person in queue)
    do {
        // count the stop times one ride at a time
        next_ride(stops, &A_end, &A_head, &A_tail, &B_head, &B_tail, X, Y); 
    } while (A_tail != A_end);

    return stops;
}
