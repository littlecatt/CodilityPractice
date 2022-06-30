#include <iostream>
#include <vector>

#include "solution.h"
#include "helpers.h"


using namespace std;

int main(){

    int A[] {20};
    int B[] {2};
    int M = 3;
    int X = 5;
    int Y = 200;
    size_t N = sizeof(A) / sizeof(int); 
    Solution *solution_class = new Solution();
    cout << solution_class->solution(A, B, M, X, Y, N) << endl; 
    return 0;
}
