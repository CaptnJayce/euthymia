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
                std::cout << "Spawned entity: " << enemy.name << ". Total entities: " << totalEntities << "\n" << std::endl;
                break;
            }
            roll -= enemy.spawnChance;
        }
    } else {
        std::cout << "Cannot spawn entity, max entities reached.\n" << std::endl;
    }
    return 0;
}

int CORE::removeEntity(std::string entitiyName, int entityId) {
    if (totalEntities > 0) {
        totalEntities--;
        maxEntitiesReached = false;
        std::cout << "Removed entity: " << entitiyName << " with ID: " << entityId << ". Total entities: " << totalEntities << "\n" << std::endl;
    } else {
        std::cout << "No entities to remove.\n" << std::endl;
    }
    return 0;
}