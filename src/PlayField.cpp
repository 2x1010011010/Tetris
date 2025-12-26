#include "PlayField.h"
#include <algorithm>

PlayField::PlayField()
{
    for (auto& row : grid)
        std::ranges::fill(row, Cell::Empty);

    for (auto& row : tileColors)
        std::ranges::fill(row, TileColor::CYAN);
}

int PlayField::checkAndClearLines()
{
    int linesCleared = 0;

    for (int y = HEIGHT - 1; y >= 0; --y)
    {
        if (isLineFull(y))
        {
            clearLine(y);
            shiftDownFrom(y);
            ++linesCleared;
            ++y;
        }
    }

    return linesCleared;
}

void PlayField::clearAllLines()
{
    for (int y = 0; y < HEIGHT; ++y)
        clearLine(y);
}

void PlayField::clearLine(int y)
{
    for (int x = 0; x < WIDTH; ++x)
        grid[y][x] = Cell::Empty;
}

void PlayField::clearPiece(const std::vector<sf::Vector2i>& coords)
{
    for (const auto& pos : coords)
        if (isInBounds(pos.x, pos.y))
            setCell(pos.x, pos.y, Cell::Empty);
}

Cell PlayField::getCell(int x, int y) const
{
    if (isInBounds(x, y))
        return grid[y][x];

    return Cell::Filled;
}

TileColor PlayField::getCellColor(int x, int y) const
{
    if (isInBounds(x, y))
        return tileColors[y][x];

    return TileColor::CYAN;
}

bool PlayField::isCellEmpty(int x, int y) const
{
    return isInBounds(x, y) && grid[y][x] == Cell::Empty;
}

bool PlayField::isGameOver() const
{
    for (int x = 0; x < WIDTH; ++x)
        if (grid[0][x] == Cell::Filled)
            return true;

    return false;
}

bool PlayField::isInBounds(int x, int y)
{
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

bool PlayField::isLineFull(int y) const
{
    for (int x = 0; x < WIDTH; ++x)
        if (grid[y][x] == Cell::Empty)
            return false;

    return true;
}

void PlayField::placePiece(const std::vector<sf::Vector2i>& coords, TileColor color)
{
    for (const auto& pos : coords)
        if (isInBounds(pos.x, pos.y))
            setCell(pos.x, pos.y, Cell::Filled, color);
}

void PlayField::shiftDownFrom(int row)
{
    for (int y = row; y > 0; --y)
    {
        grid[y]   = grid[y - 1];
        tileColors[y] = tileColors[y - 1];
    }
    std::ranges::fill(grid[0], Cell::Empty);
    std::ranges::fill(tileColors[0], TileColor::CYAN);
}

void PlayField::setCell(int x, int y, Cell value, TileColor color)
{
    if (isInBounds(x, y))
    {
        grid[y][x]   = value;
        tileColors[y][x] = color;
    }
}

bool PlayField::canPlacePiece(const std::vector<sf::Vector2i>& coords) const
{
    for (const auto& pos : coords)
    {
        if (pos.y < 0)
        {
            if (pos.x < 0 || pos.x >= WIDTH)
                return false;
            continue;
        }

        if (!isInBounds(pos.x, pos.y) || !isCellEmpty(pos.x, pos.y))
        {
            return false;
        }
    }
    return true;
}
