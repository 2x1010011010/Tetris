#include "GameStats.h"

void GameStats::checkLevelUp(unsigned int oldLines)
{
    if (linesCleared_ % LINES_PER_LEVEL < LEVEL_THRESHOLD &&
        oldLines % LINES_PER_LEVEL >= LEVEL_THRESHOLD)
    {
        level_++;
    }
}

void GameStats::updateScore(unsigned int lines)
{
    ScoreMultiplayer multiplayer;

    switch (lines)
    {
        case 1:
            multiplayer = ScoreMultiplayer::SINGLE_LINE;
            break;
        case 2:
            multiplayer = ScoreMultiplayer::DOUBLE_LINE;
            break;
        case 3:
            multiplayer = ScoreMultiplayer::TRIPLE_LINE;
            break;
        case 4:
            multiplayer = ScoreMultiplayer::TETRIS;
            break;
    }

    score_ += static_cast<int>(multiplayer) * (level_ + 1);
}

void GameStats::processLinesCleared(unsigned int linesClearedCount)
{
    updateScore(linesClearedCount);
    const unsigned int oldLines = linesCleared_;
    linesCleared_ += linesClearedCount;
    checkLevelUp(oldLines);
}
