#include "../headers/core.hpp"
#include "../headers/entity.hpp"
#include "../headers/params.hpp"
#include "../headers/rng.hpp"
#include "../headers/tick.hpp"
#include <iostream>

int main() {
  ENEMY_DEF basic{"Basic Barry", 50.0f, 1, 1, 100, 5.0f};
  ENEMY_DEF inter{"Intermediate Barry", 40.0f, 1, 1, 100, 15.0f};
  ENEMY_DEF rarer{"Rare Barry", 10.0f, 1, 1, 100, 50.0f};

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

  core.totalWeight = rng.sumWeights(core.spawnTable);
  std::cout << "Total spawn weight: " << core.totalWeight << "\n" << std::endl;

  for (int i = 0; i < params.totalLevels; i++) {
    std::cout << "Current iteration: " << i << std::endl;

    TICK tick(params);
    tick.progressTick(rng, core);

    core.clearAllEntities();
    std::cout << std::endl;
  }

  return 0;
}
