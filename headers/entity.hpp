#pragma once
#include <string>

struct ENEMY_DEF {
    std::string name;
    float spawnChance;
    int tier; // 0 lowest, n highest
    int minHealth;
    int maxHealth;
    float dropChance;
};