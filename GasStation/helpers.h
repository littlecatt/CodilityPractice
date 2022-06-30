#include <vector>
#ifndef HELPERS_H
#define HELPERS_H

void build_diff(std::vector<int> &diff, std::vector<int> &gas, std::vector<int> &cost);
bool solvable(std::vector<int> &diff);
int init_start(std::vector<int> &diff);
void increment(int &index, int v_length);
void decrement(int &index, int v_length);

#endif

