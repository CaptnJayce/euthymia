#pragma once
#include "params.hpp"

class RNG;

class TICK {
public:
    TICK(const PARAMS& params);
    int progressTick(RNG& rng);    

private:
    int tps;
};