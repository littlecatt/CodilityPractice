#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>

std::string to_binary(int num);
void construct_buffer(std::vector<std::string> &buffer, std::string base, std::string multiplyer);
std::string add_bin(std::string bin1, std::string bin2);
void add_all(int &result, std::vector<std::string> &buffer);

#endif
