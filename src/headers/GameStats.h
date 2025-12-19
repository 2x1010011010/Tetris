#pragma once

#include "const/Enums.h"

class GameStats
{
public:
    static constexpr unsigned int LINES_PER_LEVEL = 10;
    static constexpr unsigned int LEVEL_THRESHOLD = 4;

private:
    unsigned int level_ {1};
    unsigned int score_ {0};
    unsigned int linesCleared_ {0};
    float gameTime_ {0.0f};

    void updateScore(unsigned int lines);
    void checkLevelUp(unsigned int oldLines);

public:
    GameStats() = default;
    
};