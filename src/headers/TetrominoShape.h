#pragma once

#include <array>
#include <vector>

#include "Enums.h"
#include "TetrominoShape.h"
#include "const/TetrominoConst.h"

struct Point
{
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
    Point() : Point(0, 0) {}

};

struct TetrominoShape
{
private:
    TetrominoType type_;

public:
    explicit TetrominoShape(const TetrominoType type) : type_(type) {}

    [[nodiscard]] std::vector<Point> GetCoordinates() const
    {
        std::vector<Point> coordinates;
        const auto& shape = TetrominoConst::TETROMINO_SHAPES.at(type_);

        for (const auto& coord : shape)
        {
            coordinates.emplace_back(coord[0], coord[1]);
        }

        return coordinates;
    };

    [[nodiscard]] TileColor getColor() const
    {
        return TetrominoConst::TETROMINO_COLOR_MAP.at(type_);
    }

    [[nodiscard]] TetrominoType getType() const
    {
        return type_;
    }
};