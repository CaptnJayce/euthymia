#include "../headers/rng.hpp"
#include "../headers/tick.hpp"
#include <iostream>

int main() {
    uint64_t seed;

    std::cout << "Type a seed: ";
    std::cin >> seed;

    RNG rng(seed);

    for(int i = 0; i < 3; i++) {
        std::cout << i << "\n";

        TICK tick(5);
        tick.progressTick(rng);
    }

    return 0;
}