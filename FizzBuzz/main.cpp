#include <iostream>
#include <string>


int main (int argc, char* argv[]){
    // Get inputs
    std::cout << argv[0] << std::endl;
    std::string x_string = argv[1];
    std::string y_string = argv[2];
    std::string n_string = argv[3];
    int X = std::stoi(x_string);
    int Y = std::stoi(y_string);
    int N = std::stoi(n_string);

    // 4 cases in loop
    for (size_t i{1}; i <= N; ++i){
        // 1 is special (always divisible)
        if (i == 1) std::cout << 1 << std::endl;
        // FizzBuzz (both X and Y)
        else if (i % X == 0 && i % Y == 0){
            std::cout << "FizzBuzz" << std::endl;
        }
        // Fizz (divisible by X)
        else if (i % X == 0){
            std::cout << "Fizz" << std::endl;
        }
        // Buzz (divisible by Y)
        else if (i % Y == 0){
            std::cout << "Buzz" << std::endl;
        }
        else std::cout << i << std::endl;
    }
    return 0;
}
