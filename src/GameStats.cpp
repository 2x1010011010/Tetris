#include "GameStats.h"

void GameStats::checkLevelUp(unsigned int oldLines)
{
    if (linesCleared_ % LINES_PER_LEVEL < LEVEL_THRESHOLD &&
        oldLines % LINES_PER_LEVEL >= LEVEL_THRESHOLD)
    {
        level_++;
    }
}

