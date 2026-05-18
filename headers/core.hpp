#pragma once
#include "entity.hpp"
#include "params.hpp"
#include "rng.hpp"
#include <string>
#include <vector>

class CORE{
public:
    CORE(PARAMS& params);

    // entity handling
    int checkEntityCount();
    int spawnEntity(RNG& rng);
    int removeEntity(std::string entitiyName, int entityId);
    float totalWeight = 0.0f;

    std::vector<ENEMY_DEF> spawnTable;
private:

// drop handling 
float spawnDrop(std::string dropName, int dropId);
float removeDrop(std::string dropName, int dropId);

// level handling
bool loadLevel(std::string levelName, int levelId);
bool unloadLevel(std::string levelName, int levelId);

// process handling
bool isProcessRunning(std::string processName, int processId);
bool startProcess(std::string processName, int processId);
bool stopProcess(std::string processName, int processId);

int totalEntities;
bool maxEntitiesReached;

PARAMS& params;
};