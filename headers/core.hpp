#pragma once
#include "params.hpp"
#include <string>

class CORE{
public:
    CORE(PARAMS& params);
private:
// entity handling
int checkEntityCount();
int spawnEntity(std::string entityName, int EntityId);
int removeEntity(std::string entitiyName, int entityId);

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