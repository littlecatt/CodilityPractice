#include <iostream>
#include <vector>
#include "helpers.h"


void build_diff(std::vector<int> &diff, std::vector<int> &gas, std::vector<int> &cost){
    for (size_t i{0}; i < gas.size(); ++i){
        diff.push_back(gas.at(i) - cost.at(i));
    }
    for (size_t i{0}; i < gas.size(); ++i){
        std::cout << diff.at(i) << " "; 
    }
    std::cout << std::endl;
}

bool solvable(std::vector<int> &diff){
    int sum = 0;
    for (auto v : diff){
        sum += v;
    }
    return (sum >= 0) ? true : false;
}
int init_start(std::vector<int> &diff){
    int i = 0;
    for (auto v : diff){
        if (v >= 0) return i;
        else ++i;
    }
    std::cout << "init failed" << std::endl;
    return -1;
}

// circular increment and decrement
void increment(int &index, int v_length){
    if (index == v_length-1) index = 0; 
    else index++;
}
void decrement(int &index, int v_length){
    if (index == 0) index = (v_length - 1);
    else index--;
}
