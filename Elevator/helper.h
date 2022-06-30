#ifndef HELPERS_H
#define HELPERS_H

void next_ride(int &stops, int **A_end, int **A_head, int **A_tail, 
               int **B_head, int **B_tail, int X, int Y);


void update_ptrs(int **A_end, int **A_head, int **A_tail, 
                 int **B_head, int **B_tail, int X, int Y);

void sort_this_range(int *B_head, int *B_tail);

void count_and_update(int &stops, int *B_head, int *B_tail);

#endif

