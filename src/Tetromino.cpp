#include "Tetromino.h"
#include "TetrominoShape.h"

Tetromino::Tetromino(const TetrominoType type, const sf::Vector2i startPos) : shape(type), offset(startPos), rotationState(0)
{
    updatePositions();
}

void Tetromino::updatePositions()
{
    const auto coords = shape.getCoordinates();
}
