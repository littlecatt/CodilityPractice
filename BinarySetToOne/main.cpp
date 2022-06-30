#include <iostream>
#include <vector>
#include <string>
#include "helpers.h"

using namespace std;

int solution(int, int);

int main(){
    // get inputs
    int A{3};
    int B{15};

    // print result
    cout << "A: " << A << " B: " << B << endl;
    cout << "There are " << solution(A, B) << " bits set to 1." << endl;

    return 0;
}

int solution(int A, int B){
    // take the bigger one as base, smaller one as multiplyer 
    int base_num = (A > B) ? A : B;
    int multiplyer_num = (base_num == A) ? B : A;
    
    // binary formats 
    string base = to_binary(base_num);
    string multiplyer = to_binary(multiplyer_num);

    // construct the buffer for adding binary numbers 
    vector<string> add_buffer {};
    construct_buffer(add_buffer, base, multiplyer);

    // add all the binary numbers in the buffer
    int result;
    add_all(result, add_buffer); 


    return result;
}
