#include "../headers/rng.hpp"
#include "../headers/tick.hpp"
#include "../headers/params.hpp"
#include "../headers/entity.hpp"
#include "../headers/core.hpp"
#include <iostream>

int main() {
    ENEMY_DEF basic{"Basic Barry", 50.0f, 1, 1, 100, 25.0f};
    ENEMY_DEF inter{"Intermediate Barry", 40.0f, 1, 1, 100, 25.0f};
    ENEMY_DEF rarer{"Rare Barry", 10.0f, 1, 1, 100, 25.0f};

    PARAMS params;
    params.framesPerSecond = 60;
    params.ticksPerSecond = 5;
    params.totalLevels = 3;

    uint64_t seed;

    std::cout << "Type a seed: ";
    std::cin >> seed;

    RNG rng(seed);
    CORE core(params);

    core.spawnTable.push_back(basic);
    core.spawnTable.push_back(inter);
    core.spawnTable.push_back(rarer);

    for(int i = 0; i < params.totalLevels; i++) {
        std::cout << i << std::endl;

        TICK tick(params);
        tick.progressTick(rng, core);
    }

    return 0;
}