#include <iostream>
#include <vector>
#include "solution.h"
#include "helpers.h"

int Solution::solution(std::vector<int> &gas, std::vector<int> &cost){

    // build difference vector
    std::vector<int> diff {}; 
    build_diff(diff, gas, cost);

    // check if there's a solution at all (sum > 0)
    if (!solvable(diff)) return -1; 

    // a start index and an end index
    int start {0};
    int end {0};
    // start from any index with difference > 0
    start = init_start(diff);
    end = start;

    // main loop
    int temp_sum {diff.at(start)};    
    while (true){
        // increment the end index 
        increment(end, diff.size());
        temp_sum += diff.at(end); 
        // decrement the start index if not feasible  
        while (temp_sum < 0){
            decrement(start, diff.size());
            temp_sum += diff.at(start); 
            // solution found if end meets start
            if (end == start) return start;
        }
        // solution found if end meets start
        if (end == start) return start;
    }
    
}
