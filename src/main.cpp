#include "../headers/rng.hpp"
#include <iostream>

int main() {
    uint64_t seed;

    std::cout << "Type a seed: ";
    std::cin >> seed;

    RNG rng(seed);

    for(int i = 0; i < 10; i++) {
        std::cout << rng.rollInt(1, 100) << "\n";
    }

    return 0;
}