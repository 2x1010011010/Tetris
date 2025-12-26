#pragma once

#include <array>
#include <vector>
#include <SFML/System/Vector2.hpp>

#include "TileConst.h"
#include "Enums.h"

class PlayField
{
public:
    static constexpr int WIDTH = 10;
    static constexpr int HEIGHT = 20;
    static constexpr int VISIBLE_HEIGHT = 20;

private:
    std::array<std::array<Cell, WIDTH>, HEIGHT> grid{};
    std::array<std::array<TileColor, WIDTH>,HEIGHT> tileColors{};

public:
    PlayField();

    [[nodiscard]] static bool isInBounds(int x, int y);
    [[nodiscard]] bool isCellEmpty(int x, int y) const;

    void setCell(int x, int y, Cell value, TileColor color = TileColor::CYAN);
    [[nodiscard]] Cell getCell(int x, int y) const;
    [[nodiscard]] TileColor getCellColor(int x, int y) const;

    [[nodiscard]] bool canPlacePiece(const std::vector<sf::Vector2i>& coords) const;
    void placePiece(const std::vector<sf::Vector2i>& coords, TileColor color);
    void clearPiece(const std::vector<sf::Vector2i>& coords);

    [[nodiscard]] bool isLineFull(int y) const;
    void clearLine(int y);
    void shiftDownFrom(int row);
    int checkAndClearLines();
    void clearAllLines();

    [[nodiscard]] bool isGameOver() const;
};