#include <iostream>
#include <vector>

#include "solution.h"


int main(){

    std::vector<int> gas {5, 1, 2, 3, 4};
    std::vector<int> cost {4, 4, 1, 5, 1};

    Solution *solution = new Solution();
    std::cout << solution->solution(gas, cost) << std::endl;
    return 0;
}
