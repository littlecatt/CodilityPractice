#include <iostream>
#include <vector>
#include <string>
#include "helpers.h"

std::string to_binary(int num){

    std::string temp{};
    while(true){
        // only '1' remain
        if (num == 1){
            temp.push_back('1');
            break;
        } 
        // divisible by 2
        else if (num % 2 == 1) {
            num = (num - 1) / 2;
            temp.push_back('1'); 
        }
        // not divisible by 2
        else{
            num = num / 2;
            temp.push_back('0');
        }
    }
    // note that the produced temp is reversed
    reverse(temp.begin(), temp.end());
    return temp;
}

void construct_buffer(std::vector<std::string> &buffer, std::string base, std::string multiplyer){

    // Go through each bit of multiplyer
    for (int i{0}; i < multiplyer.length(); ++i){
        std::string temp = base;
        if (multiplyer.at(i) == '1'){
            // push right amout of '0's to the base 
            for (int j{0}; j < multiplyer.length() - 1 - i; ++j){
                temp.push_back('0');
            } 
            // push the modified base to the buffer
            buffer.push_back(temp);
        }
    }
} 

void add_all(int &result, std::vector<std::string> &buffer){
    std::string temp {};
    // go through buffer
    for (auto binary : buffer){
        temp = add_bin(temp, binary); 
    }
    // coun the '1'
    for (const char c : temp){
        if (c == '1') result++;
    }
}
std::string add_bin(std::string bin1, std::string bin2){
    // one of the string is empty
    if (bin1.length() == 0) return bin2;
    // note that we should reverse the strings before add
    reverse(bin1.begin(), bin1.end());
    reverse(bin2.begin(), bin2.end());
    // keep moving the index of both bins, 
    // note that bin1 is bound to be longer
    std::string temp{};
    int i{0};
    int squeeze{0}; // squeeze to next bit
    int sum {0};
    while (i < bin1.length()){
        // bin2 not yet used up
        if (i < bin2.length()){
            sum = (bin1.at(i) - '0') + (bin2.at(i) - '0') + squeeze;
        } 
        // bin2 is used up
        else{
            sum = (bin1.at(i) - '0') + squeeze;
        }
        switch (sum){
            case 0:
                temp.push_back('0'); break;
            case 1:
                temp.push_back('1'); break;
            case 2:
                temp.push_back('0');
                squeeze = 1;
                break;
            case 3:
                temp.push_back('1');
                squeeze = 1;
                break;
            default:
                std::cout << "Oops" << std::endl;
        }
        ++i;
    }
    return temp;
}
