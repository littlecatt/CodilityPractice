#include <iostream>
#include <string>


int main (){
    // Get inputs
    std::string x{}; 
    std::cin >> x;
    std::string y{};
    std::cin >> y;
    std::string z{};
    std::cin >> z;
    int X = std::stoi(x);
    int Y = std::stoi(y);
    int N = std::stoi(z);

    // 5 cases in loop
    for (size_t i{1}; i <= N; ++i){
        // 1 is special (always divisible)
        if (i == 1) {
            if (X == 1){
                std::cout << "Fizz" << std::endl;
            } else{
                std::cout << 1 << std::endl;
            }
        }
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
