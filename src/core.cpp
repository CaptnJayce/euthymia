#include "../headers/core.hpp"
#include "../headers/rng.hpp"
#include <iostream>

CORE::CORE(PARAMS& params) : params(params), totalEntities(0), maxEntitiesReached(false) {
    this->params.maxEntities = 1000;
}

int CORE::checkEntityCount() {
    if (totalEntities >= params.maxEntities) {
        std::cout << "Max entities reached: " << totalEntities << "/" << params.maxEntities << "\n" << std::endl;
        maxEntitiesReached = true;
    }
    return 0;
}

int CORE::spawnEntity(RNG& rng) {
    checkEntityCount();

    if (!maxEntitiesReached) {
        float roll = rng.rollFloat() * totalWeight;

        for (const auto& enemy : spawnTable) {
            if (roll < enemy.spawnChance) {
                totalEntities++;
                activeEntities[enemy.name]++;
                std::cout << "Spawned entity: " << enemy.name << std::endl;
                std::cout << "Total entities: " << totalEntities << "\n" << std::endl;
                for (const auto& [key, val] : activeEntities) {
                    std::cout << "  [" << key << "]: " << val << "\n";
                }
                std::cout << std::endl;
                break;
            }
            roll -= enemy.spawnChance;
        }
    } else {
        std::cout << "Cannot spawn entity, max entities reached.\n" << std::endl;
    }
    return 0;
}

int CORE::removeEntity(std::string entityName) {
    if (totalEntities > 0) {
        totalEntities--;
        maxEntitiesReached = false;
        if (--activeEntities[entityName] <= 0) {
            activeEntities.erase(entityName);
        }
        std::cout << "Removed entity: " << entityName << ". Total entities: " << totalEntities << "\n" << std::endl;
    } else {
        std::cout << "No entities to remove.\n" << std::endl;
    }
    return 0;
}