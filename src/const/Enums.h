#pragma once

enum class GameState
{
    Start,
    Play,
    Pause,
    GameOver,
};

enum class TetrominoType
{
    I     = 0,
    Z     = 1,
    S     = 2,
    T     = 3,
    L     = 4,
    J     = 5,
    O     = 6,
    COUNT = 7
};