#include "../headers/core.hpp"
#include "../headers/params.hpp"
#include <iostream>

CORE::CORE(PARAMS& params) : params(params), totalEntities(0), maxEntitiesReached(false) {
    this->params.maxEntities = 10;
}

int CORE::checkEntityCount() {
    if (totalEntities >= params.maxEntities) {
        std::cout << "Max entities reached: " << totalEntities << "/" << params.maxEntities << "\n" << std::endl;
        return -1;
    }
    return 0;
}

int CORE::spawnEntity(std::string entityName, int EntityId) {
    checkEntityCount();

    if (maxEntitiesReached) {
        std::cout << "Cannot spawn entity: " << entityName << " with ID: " << EntityId << ". Max entities reached.\n" << std::endl;
        return -1;
    } else {
        totalEntities++;
        std::cout << "Spawned entity: " << entityName << " with ID: " << EntityId << ". Total entities: " << totalEntities << "\n" << std::endl;
    }
    return 0;
}

int CORE::removeEntity(std::string entitiyName, int entityId) {
    if (totalEntities > 0) {
        totalEntities--;
        std::cout << "Removed entity: " << entitiyName << " with ID: " << entityId << ". Total entities: " << totalEntities << "\n" << std::endl;
    } else {
        std::cout << "No entities to remove.\n" << std::endl;
        return -1;
    }
    return 0;
}