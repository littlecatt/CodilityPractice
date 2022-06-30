#include <iostream>
#include "helpers.h"

void next_ride(int &stops, int **A_end, int **A_head, int **A_tail, 
               int **B_head, int **B_tail, int X, int Y){
    // determine the step tail pointers should take and update pointers
    // according to A array (n of people and weights)
    update_ptrs(A_end, A_head, A_tail, B_head, B_tail, X, Y);

    // sort the specified range according to B array (the floors)
    // note that A array is irrelavant in this 
    sort_this_range(*B_head, *B_tail);

    // count the stop and update 'stops'
    count_and_update(stops, *B_head, *B_tail);

    // update heads if there's still people in the queue
    if (*A_tail != *A_end){
        *A_head = *A_tail+1;
        *B_head = *B_tail+1;
    } 
}

void update_ptrs(int **A_end, int **A_head, int **A_tail, 
                 int **B_head, int **B_tail, int X, int Y){

    // move tail to the head (start next ride)
    *A_tail = *A_head;
    *B_tail = *B_head;
    int n_of_people {0};
    int weights {0};
    bool has_ended {false};
    while (true){
        // take a step
        n_of_people += 1;
        weights += *(*A_tail);
        // check the number of people and sum of their weights
        if (n_of_people > X || weights > Y){
            // take one step back 
            (*A_tail)--;
            (*B_tail)--;
            break;
        }

        // update pointers
        // don't update through boundary
        if (*A_tail != *A_end){
            (*A_tail)++;
            (*B_tail)++;
        } else{ 
            if (has_ended) break;
            has_ended = true;
        }
    }
}

void sort_this_range(int *B_head, int *B_tail){
    std::sort(B_head, B_tail+1); // std::sort is right-end opened
    while (B_head <= B_tail){
        std::cout << *B_head << " "; 
        B_head++;
    }
    std::cout << std::endl;
}

void count_and_update(int &stops, int *B_head, int *B_tail){
    int this_floor {-1};
    int next_floor {-1};
    for (size_t i {0}; B_head + i <= B_tail; ++i){
        next_floor = *(B_head + i);
        // increment stops if there's a change
        if (next_floor != this_floor){
            stops++;
        }
        // update 
        this_floor = next_floor;
    }
    // don't forget the ground floor in the end
    stops += 1;
}
