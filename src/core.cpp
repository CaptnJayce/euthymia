#include "../headers/core.hpp"
#include "../headers/rng.hpp"
#include <iostream>

CORE::CORE(PARAMS& params) : params(params), totalEntities(0), maxEntitiesReached(false) {
    this->params.maxEntities = 10;
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
        float x = rng.rollFloat();
        if (x < 0.5f) {
            std::cout << "Spawned entity: Basic Barry. Total entities: " << totalEntities + 1 << "\n" << std::endl;
            totalEntities++;
        } else {
            std::cout << "Spawned nothing. Total entities: " << totalEntities << "\n" << std::endl;
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